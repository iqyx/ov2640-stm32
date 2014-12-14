#include "ch.h"
#include "hal.h"

MemoryHeap ccm_heap;


static const I2CConfig i2cfg1 = {
	OPMODE_I2C,
	100000,
	FAST_DUTY_CYCLE_2,
};



uint32_t sccb_read_reg(uint8_t addr, uint8_t reg, uint8_t *value) {

	systime_t timeout = MS2ST(4);
	uint8_t txbuf[2] = {reg, 0x00};
	uint8_t rxbuf[2];

	i2cAcquireBus(&I2CD1);
	msg_t status = i2cMasterTransmitTimeout(&I2CD1, addr, txbuf, 1, rxbuf, 1, timeout);
	i2cReleaseBus(&I2CD1);

	if (status != RDY_OK){
		return -1;
	}

	*value = rxbuf[0];

	return 0;
}



static msg_t Thread1(void *arg) {
	(void)arg;

	chRegSetThreadName("test");

	/* I2C1_SDA */
	palSetPadMode(GPIOB, 7, PAL_MODE_ALTERNATE(4));
	/* I2C1_SCL */
	palSetPadMode(GPIOB, 8, PAL_MODE_ALTERNATE(4));

	i2cStart(&I2CD1, &i2cfg1);

	while (1) {
		uint8_t vid;
		if (sccb_read_reg(0x60, 0x0a, &vid) == 0) {
			palTogglePad(GPIOD, 14);
		}

		palTogglePad(GPIOD, 15);
		chThdSleepMilliseconds(50);
	}

	return 0;
}


int main(void) {

	halInit();
	chSysInit();
	chHeapInit(&ccm_heap, (void *)0x10000000, 0x10000);

	/* leds */
	palSetPadMode(GPIOD, 12, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOD, 13, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOD, 14, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOD, 15, PAL_MODE_OUTPUT_PUSHPULL);

	palClearPad(GPIOD, 12);
	palClearPad(GPIOD, 13);
	palClearPad(GPIOD, 14);
	palClearPad(GPIOD, 15);



	chThdCreateFromHeap(&ccm_heap, 4000, NORMALPRIO, Thread1, NULL);

	while (1) {
		chThdSleepMilliseconds(500);
	}
}
