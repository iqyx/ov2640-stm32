#include "ch.h"
#include "hal.h"

MemoryHeap ccm_heap;


static msg_t Thread1(void *arg) {
	(void)arg;

	chRegSetThreadName("test");

	while (1) {
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

	chThdCreateFromHeap(&ccm_heap, 37000, NORMALPRIO, Thread1, NULL);

	while (1) {
		chThdSleepMilliseconds(500);
	}
}
