#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/dcmi.h>
#include <libopencm3/stm32/dma.h>

#include "ov2640.h"


static void mcu_setup(void) {

	rcc_clock_setup_hse_3v3(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);

	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_GPIOC);
	rcc_periph_clock_enable(RCC_GPIOD);
	rcc_periph_clock_enable(RCC_GPIOE);

	rcc_periph_clock_enable(RCC_I2C1);
	rcc_periph_clock_enable(RCC_TIM1);
	rcc_periph_clock_enable(RCC_DMA2);
	rcc_periph_clock_enable(RCC_USART2);

	rcc_periph_clock_enable(RCC_DCMI);

}


static void gpio_setup(void) {
	/* Green LED */
	//~ gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
	gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO15);

	/* I2C1 connected to the SCCB camera bus. */
	gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO8 | GPIO9);
	gpio_set_output_options(GPIOB, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, GPIO8 | GPIO9);
	gpio_set_af(GPIOB, GPIO_AF4, GPIO8 | GPIO9);

	/* USART1 */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO2);
	gpio_set_af(GPIOA, GPIO_AF7, GPIO2);

	/* Power down pin. */
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO11);

	/* Camera reset. */
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO10);

	/* XCLK */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO8);
	gpio_set_af(GPIOA, GPIO_AF1, GPIO8);

	/* DCMI */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO4 | GPIO6);
	gpio_set_af(GPIOA, GPIO_AF13, GPIO4 | GPIO6);
	gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO6 | GPIO7);
	gpio_set_af(GPIOB, GPIO_AF13, GPIO6 | GPIO7);
	gpio_mode_setup(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO6 | GPIO7 | GPIO8 | GPIO9);
	gpio_set_af(GPIOC, GPIO_AF13, GPIO6 | GPIO7 | GPIO8 | GPIO9);
	gpio_mode_setup(GPIOE, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO4 | GPIO5 | GPIO6);
	gpio_set_af(GPIOE, GPIO_AF13, GPIO4 | GPIO5 | GPIO6);


	timer_reset(TIM1);
	timer_set_mode(TIM1, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);
	timer_set_prescaler(TIM1, 0);
	timer_continuous_mode(TIM1);
	timer_direction_up(TIM1);
	timer_set_period(TIM1, 7);
	timer_enable_preload(TIM1);
	timer_enable_break_main_output(TIM1);

	/* OC1 is allocated for XCLK. */
	timer_enable_oc_preload(TIM1, TIM_OC1);
	timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_PWM1);
	timer_set_oc_value(TIM1, TIM_OC1, 4);
	timer_enable_oc_output(TIM1, TIM_OC1);

	timer_enable_counter(TIM1);

}


static void i2c_setup(void) {
	i2c_peripheral_disable(I2C1);
	i2c_reset(I2C1);
	i2c_set_fast_mode(I2C1);
	i2c_set_clock_frequency(I2C1, I2C_CR2_FREQ_16MHZ);
	i2c_set_ccr(I2C1, 35); /* wat? */
	i2c_set_trise(I2C1, 43); /* wat? */
	i2c_peripheral_enable(I2C1);
}


static void usart_setup(void) {
	usart_set_baudrate(USART2, 460800);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
	usart_enable(USART2);
}


static void delay(size_t cycles) {
	for (size_t i = 0; i < cycles; i++) {
		__asm__("nop");
	}
}


Ov2640 camera;

void dma2_stream1_isr(void) {
	ov2640_dma_irq_handler(&camera);
}

void dcmi_isr(void) {
	if (DCMI_MIS & DCMI_MIS_FRAME) {
		DCMI_ICR |= DCMI_ICR_FRAME;
		printf("frame\n");
		dma_disable_stream(DMA2, DMA_STREAM1);
	}
	if (DCMI_MIS & DCMI_MIS_LINE) {
		DCMI_ICR |= DCMI_ICR_LINE;
		printf("line\n");
	}
	if (DCMI_MIS & DCMI_MIS_VSYNC) {
		DCMI_ICR |= DCMI_ICR_VSYNC;
		printf("vsync\n");
	}
}


int _write(int file, char *ptr, int len) {
	int i;

	if (file == STDOUT_FILENO || file == STDERR_FILENO) {
		for (i = 0; i < len; i++) {
			if (ptr[i] == '\n') {
				usart_send_blocking(USART2, '\r');
			}
			usart_send_blocking(USART2, ptr[i]);
		}
		return i;
	}
	errno = EIO;
	return -1;
}


uint8_t data[320 * 8 * 4];

int main(void) {

	mcu_setup();
	gpio_setup();
	i2c_setup();
	usart_setup();
	ov2640_init(&camera);
	ov2640_start(&camera);
	nvic_enable_irq(NVIC_DMA2_STREAM1_IRQ);
	nvic_enable_irq(NVIC_DCMI_IRQ);
	delay(50000000);


	while (1) {
		dma_enable_stream(DMA2, DMA_STREAM1);
		DCMI_CR |= DCMI_CR_CAPTURE;
		gpio_set(GPIOD, GPIO15);
		delay(50000000);
		gpio_clear(GPIOD, GPIO15);


		delay(50000000);


	}

	return 0;
}
