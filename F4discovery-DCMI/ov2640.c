/*
 * uHAL OmniVision OV2640 camera driver
 *
 * Copyright (C) 2016, Marek Koza, qyx@krtko.org
 *
 * This file is part of uMesh node firmware (http://qyx.krtko.org/projects/umesh)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * The following part is borrowed from the linux ov2640 driver. Some of the
 * registers are named but still there are many without any documentation.
 * Another possible source is the ArduCam project but it is not documented
 * and there are long arrays of magic values only.
 */

/*
 * Copyright (C) 2010 Alberto Panizzo <maramaopercheseimorto@gmail.com>
 *
 * Based on ov772x, ov9640 drivers and previous non merged implementations.
 *
 * Copyright 2005-2009 Freescale Semiconductor, Inc. All Rights Reserved.
 * Copyright (C) 2006, OmniVision
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */


#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/** @todo get rid of this, use i2c device interface instead */
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/dma.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/dcmi.h>

#include "ov2640.h"


static void delay(size_t cycles) {
	for (size_t i = 0; i < cycles; i++) {
		__asm__("nop");
	}
}

/******************************************** @todo **************************************************/

static uint8_t i2c_start(uint32_t i2c, uint8_t address, uint8_t mode) {
	i2c_send_start(i2c);

	/* Wait for master mode selected */
	while (!((I2C_SR1(i2c) & I2C_SR1_SB)
		& (I2C_SR2(i2c) & (I2C_SR2_MSL | I2C_SR2_BUSY))));

	i2c_send_7bit_address(i2c, address, mode);

	/* Waiting for address is transferred. */
	while (!(I2C_SR1(i2c) & I2C_SR1_ADDR));

	/* Cleaning ADDR condition sequence. */
	uint32_t reg32 = I2C_SR2(i2c);
	(void) reg32; /* unused */

	return 0;
}

static uint8_t i2c_write(uint32_t i2c, uint8_t address, uint8_t reg, uint8_t data) {
	i2c_start(i2c, address, I2C_WRITE);

	i2c_send_data(i2c, reg);

	while (!(I2C_SR1(i2c) & (I2C_SR1_BTF)));
	i2c_send_data(i2c, data);

	while (!(I2C_SR1(i2c) & (I2C_SR1_BTF)));

	i2c_send_stop(i2c);

	return 0;
}

static uint32_t i2c_read(uint32_t i2c, uint8_t address, uint8_t reg) {
	while ((I2C_SR2(i2c) & I2C_SR2_BUSY));

	i2c_start(i2c, address, I2C_WRITE);

	i2c_send_data(i2c, reg);
	while (!(I2C_SR1(i2c) & (I2C_SR1_BTF)));

	i2c_enable_ack(i2c);
	i2c_nack_current(i2c);
	i2c_start(i2c, address, I2C_READ);

	//~ while (!(I2C_SR1(i2c) & (I2C_SR1_BTF)));

	while (!(I2C_SR1(i2c) & I2C_SR1_RxNE));
	uint32_t result = i2c_get_data(i2c);
	i2c_send_stop(i2c);
	while (!(I2C_SR1(i2c) & I2C_SR1_RxNE));
	result = result << 8 | i2c_get_data(i2c);

	I2C_SR1(i2c) &= ~I2C_SR1_AF;

	return result;
}

static ov2640_ret_t ov2640_write_array(const struct regval_list *vals) {
	while ((vals->reg_num != 0xff) || (vals->value != 0xff)) {
		if (i2c_write(I2C1, 0x60 >> 1, vals->reg_num, vals->value) != 0) {
			return -1;
		}
		vals++;
	}
	return OV2640_OK;
}


/** @todo abstract i2c */
static ov2640_ret_t ov2640_reset(Ov2640 *self) {
	if (self == NULL) {
		return OV2640_FAILED;
	}
	i2c_write(I2C1, self->address, 0xff, 1);    /* set to page 1 */
	i2c_write(I2C1, self->address, 0x12, 80);   /* software reset */
	delay(100000);

	return OV2640_OK;
}


ov2640_ret_t ov2640_init(Ov2640 *self) {

	memset(self, 0, sizeof(Ov2640));
	interface_camera_init(&self->camera_iface);

	/** @todo should be handled with the i2c device implementation */
	/* Set the default address. */
	self->address = 0x60 >> 1;

	return OV2640_OK;
}


ov2640_ret_t ov2640_free(Ov2640 *self) {
	interface_camera_free(&self->camera_iface);

	return OV2640_OK;
}


static ov2640_ret_t ov2640_init_dma(Ov2640 *self) {
	dma_stream_reset(DMA2, DMA_STREAM1);
	dma_set_priority(DMA2, DMA_STREAM1, DMA_SxCR_PL_HIGH);
	dma_set_memory_size(DMA2, DMA_STREAM1, DMA_SxCR_MSIZE_32BIT);
	dma_set_peripheral_size(DMA2, DMA_STREAM1, DMA_SxCR_PSIZE_32BIT);
	dma_enable_memory_increment_mode(DMA2, DMA_STREAM1);
	//~ dma_enable_circular_mode(DMA2, DMA_STREAM1);
	dma_set_transfer_mode(DMA2, DMA_STREAM1, DMA_SxCR_DIR_PERIPHERAL_TO_MEM);
	dma_set_peripheral_address(DMA2, DMA_STREAM1, (uint32_t)&(DCMI_DR));
	dma_set_memory_address(DMA2, DMA_STREAM1, (uint32_t)&(self->buffer));
	dma_set_number_of_data(DMA2, DMA_STREAM1, BUFFER_SIZE / 4);
	dma_enable_transfer_complete_interrupt(DMA2, DMA_STREAM1);
	// dma_enable_half_transfer_interrupt(DMA2, DMA_STREAM1);
	dma_channel_select(DMA2, DMA_STREAM1, DMA_SxCR_CHSEL_1);
}


ov2640_ret_t ov2640_start(Ov2640 *self) {
	if (self == NULL) {
		return OV2640_FAILED;
	}

	// ov2640_init_dma(self);

	/* set PWDN low to exit power down */
	gpio_clear(GPIOC, GPIO11);
	delay(10000);

	/* reset the camera */
	gpio_clear(GPIOC, GPIO10);
	delay(10000);
	gpio_set(GPIOC, GPIO10);
	delay(10000);

	//~ ov2640_reset(self);

	ov2640_write_array(ov2640_init_regs);
	ov2640_write_array(ov2640_size_change_preamble_regs);
	ov2640_write_array(ov2640_svga_regs);

	ov2640_write_array(ov2640_format_change_preamble_regs);
	//~ ov2640_write_array(ov2640_yuyv_regs);
	// ov2640_write_array(ov2640_rgb565_be_regs);
	ov2640_write_array(ov2640_jpeg_regs);

	ov2640_write_array(ov2640_light_mode_sunny_regs);


	rcc_periph_reset_pulse(RST_DCMI);

	/* DCMI configuration */
	DCMI_CR |= DCMI_CR_JPEG | DCMI_CR_CM | DCMI_CR_PCKPOL;
	DCMI_IER |= DCMI_IER_FRAME;
	DCMI_CR |= DCMI_CR_EN;

	ov2640_init_dma(self);

	return OV2640_OK;
}


ov2640_ret_t ov2640_stop(Ov2640 *self) {
	if (self == NULL) {
		return OV2640_FAILED;
	}

	/* Set PWDN high to enter power down mode. */
	gpio_set(GPIOC, GPIO11);

	return OV2640_OK;
}


ICamera *ov2640_camera(Ov2640 *self) {
	if (self == NULL) {
		return false;
	}

	return &self->camera_iface;
}

ov2640_ret_t ov2640_dma_irq_handler(Ov2640 *self) {
	if (dma_get_interrupt_flag(DMA2, DMA_STREAM1, DMA_TCIF)) {
		dma_clear_interrupt_flags(DMA2, DMA_STREAM1, DMA_TCIF);
		self->frame_bytes = (BUFFER_SIZE / 4 - DMA_SNDTR(DMA2, DMA_STREAM1)) * 4;
		printf("dma completed bytes = %u\n", self->frame_bytes);

		for (size_t i = 0; i < self->frame_bytes; i++) {
			printf("%02x", self->buffer[i]);
		}
		printf("\n");

	}
}
