/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for STMicroelectronics STM32F4-Discovery board.
 */

/*
 * Board identifier.
 */
#define BOARD_ST_STM32F4_DISCOVERY
#define BOARD_NAME                  "F4_default"


/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0
#endif

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000
#endif


/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   300

/*
 * MCU type as defined in the ST header file stm32f4xx.h.
 */
#define STM32F4XX

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_2M(n)            (0U << ((n) * 2))
#define PIN_OSPEED_25M(n)           (1U << ((n) * 2))
#define PIN_OSPEED_50M(n)           (2U << ((n) * 2))
#define PIN_OSPEED_100M(n)          (3U << ((n) * 2))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2))
#define PIN_AFIO_AF(n, v)           ((v##U) << ((n % 8) * 4))



#define VAL_GPIOA_MODER			(PIN_MODE_INPUT(0) | \
					PIN_MODE_INPUT(1) | \
					PIN_MODE_INPUT(2) | \
					PIN_MODE_INPUT(3) | \
					PIN_MODE_INPUT(4) | \
					PIN_MODE_INPUT(5) | \
					PIN_MODE_INPUT(6) | \
					PIN_MODE_INPUT(7) | \
					PIN_MODE_INPUT(8) | \
					PIN_MODE_INPUT(9) | \
					PIN_MODE_INPUT(10) | \
					PIN_MODE_INPUT(11) | \
					PIN_MODE_INPUT(12) | \
					PIN_MODE_ALTERNATE(13) | \
					PIN_MODE_ALTERNATE(14) | \
					PIN_MODE_INPUT(15))
#define VAL_GPIOA_OTYPER		(PIN_OTYPE_PUSHPULL(0) | \
					PIN_OTYPE_PUSHPULL(1) | \
					PIN_OTYPE_PUSHPULL(2) | \
					PIN_OTYPE_PUSHPULL(3) | \
					PIN_OTYPE_PUSHPULL(4) | \
					PIN_OTYPE_PUSHPULL(5) | \
					PIN_OTYPE_PUSHPULL(6) | \
					PIN_OTYPE_PUSHPULL(7) | \
					PIN_OTYPE_PUSHPULL(8) | \
					PIN_OTYPE_PUSHPULL(9) | \
					PIN_OTYPE_PUSHPULL(10) | \
					PIN_OTYPE_PUSHPULL(11) | \
					PIN_OTYPE_PUSHPULL(12) | \
					PIN_OTYPE_PUSHPULL(13) | \
					PIN_OTYPE_PUSHPULL(14) | \
					PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOA_OSPEEDR		(PIN_OSPEED_100M(0) | \
					PIN_OSPEED_100M(1) | \
					PIN_OSPEED_100M(2) | \
					PIN_OSPEED_100M(3) | \
					PIN_OSPEED_100M(4) | \
					PIN_OSPEED_100M(5) | \
					PIN_OSPEED_100M(6) | \
					PIN_OSPEED_100M(7) | \
					PIN_OSPEED_100M(8) | \
					PIN_OSPEED_100M(9) | \
					PIN_OSPEED_100M(10) | \
					PIN_OSPEED_100M(11) | \
					PIN_OSPEED_100M(12) | \
					PIN_OSPEED_25M(13) | \
					PIN_OSPEED_25M(14) | \
					PIN_OSPEED_100M(15))
#define VAL_GPIOA_PUPDR			(PIN_PUPDR_PULLUP(0) | \
					PIN_PUPDR_PULLUP(1) | \
					PIN_PUPDR_PULLUP(2) | \
					PIN_PUPDR_PULLUP(3) | \
					PIN_PUPDR_PULLUP(4) | \
					PIN_PUPDR_PULLUP(5) | \
					PIN_PUPDR_PULLUP(6) | \
					PIN_PUPDR_PULLUP(7) | \
					PIN_PUPDR_PULLUP(8) | \
					PIN_PUPDR_PULLUP(9) | \
					PIN_PUPDR_PULLUP(10) | \
					PIN_PUPDR_PULLUP(11) | \
					PIN_PUPDR_PULLUP(12) | \
					PIN_PUPDR_PULLUP(13) | \
					PIN_PUPDR_PULLUP(14) | \
					PIN_PUPDR_PULLUP(15))
#define VAL_GPIOA_ODR			(PIN_ODR_HIGH(0) | \
					PIN_ODR_HIGH(1) | \
					PIN_ODR_HIGH(2) | \
					PIN_ODR_HIGH(3) | \
					PIN_ODR_HIGH(4) | \
					PIN_ODR_HIGH(5) | \
					PIN_ODR_HIGH(6) | \
					PIN_ODR_HIGH(7) | \
					PIN_ODR_HIGH(8) | \
					PIN_ODR_HIGH(9) | \
					PIN_ODR_HIGH(10) | \
					PIN_ODR_HIGH(11) | \
					PIN_ODR_HIGH(12) | \
					PIN_ODR_HIGH(13) | \
					PIN_ODR_HIGH(14) | \
					PIN_ODR_HIGH(15))
#define VAL_GPIOA_AFRL			(PIN_AFIO_AF(0, 0) | \
					PIN_AFIO_AF(1, 0) | \
					PIN_AFIO_AF(2, 0) | \
					PIN_AFIO_AF(3, 0) | \
					PIN_AFIO_AF(4, 0) | \
					PIN_AFIO_AF(5, 0) | \
					PIN_AFIO_AF(6, 0) | \
					PIN_AFIO_AF(7, 0))
#define VAL_GPIOA_AFRH			(PIN_AFIO_AF(8, 0) | \
					PIN_AFIO_AF(9, 0) | \
					PIN_AFIO_AF(10, 0) | \
					PIN_AFIO_AF(11, 0) | \
					PIN_AFIO_AF(12, 0) | \
					PIN_AFIO_AF(13, 0) | \
					PIN_AFIO_AF(14, 0) | \
					PIN_AFIO_AF(15, 0))



#define VAL_GPIOB_MODER			(PIN_MODE_INPUT(0) | \
					PIN_MODE_INPUT(1) | \
					PIN_MODE_INPUT(2) | \
					PIN_MODE_INPUT(3) | \
					PIN_MODE_INPUT(4) | \
					PIN_MODE_INPUT(5) | \
					PIN_MODE_INPUT(6) | \
					PIN_MODE_INPUT(7) | \
					PIN_MODE_INPUT(8) | \
					PIN_MODE_INPUT(9) | \
					PIN_MODE_INPUT(10) | \
					PIN_MODE_INPUT(11) | \
					PIN_MODE_INPUT(12) | \
					PIN_MODE_INPUT(13) | \
					PIN_MODE_INPUT(14) | \
					PIN_MODE_INPUT(15))
#define VAL_GPIOB_OTYPER		(PIN_OTYPE_PUSHPULL(0) | \
					PIN_OTYPE_PUSHPULL(1) | \
					PIN_OTYPE_PUSHPULL(2) | \
					PIN_OTYPE_PUSHPULL(3) | \
					PIN_OTYPE_PUSHPULL(4) | \
					PIN_OTYPE_PUSHPULL(5) | \
					PIN_OTYPE_PUSHPULL(6) | \
					PIN_OTYPE_PUSHPULL(7) | \
					PIN_OTYPE_PUSHPULL(8) | \
					PIN_OTYPE_PUSHPULL(9) | \
					PIN_OTYPE_PUSHPULL(10) | \
					PIN_OTYPE_PUSHPULL(11) | \
					PIN_OTYPE_PUSHPULL(12) | \
					PIN_OTYPE_PUSHPULL(13) | \
					PIN_OTYPE_PUSHPULL(14) | \
					PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOB_OSPEEDR		(PIN_OSPEED_100M(0) | \
					PIN_OSPEED_100M(1) | \
					PIN_OSPEED_100M(2) | \
					PIN_OSPEED_100M(3) | \
					PIN_OSPEED_100M(4) | \
					PIN_OSPEED_100M(5) | \
					PIN_OSPEED_100M(6) | \
					PIN_OSPEED_100M(7) | \
					PIN_OSPEED_100M(8) | \
					PIN_OSPEED_100M(9) | \
					PIN_OSPEED_100M(10) | \
					PIN_OSPEED_100M(11) | \
					PIN_OSPEED_100M(12) | \
					PIN_OSPEED_100M(13) | \
					PIN_OSPEED_100M(14) | \
					PIN_OSPEED_100M(15))
#define VAL_GPIOB_PUPDR			(PIN_PUPDR_PULLUP(0) | \
					PIN_PUPDR_PULLUP(1) | \
					PIN_PUPDR_PULLUP(2) | \
					PIN_PUPDR_PULLUP(3) | \
					PIN_PUPDR_PULLUP(4) | \
					PIN_PUPDR_PULLUP(5) | \
					PIN_PUPDR_PULLUP(6) | \
					PIN_PUPDR_PULLUP(7) | \
					PIN_PUPDR_PULLUP(8) | \
					PIN_PUPDR_PULLUP(9) | \
					PIN_PUPDR_PULLUP(10) | \
					PIN_PUPDR_PULLUP(11) | \
					PIN_PUPDR_PULLUP(12) | \
					PIN_PUPDR_PULLUP(13) | \
					PIN_PUPDR_PULLUP(14) | \
					PIN_PUPDR_PULLUP(15))
#define VAL_GPIOB_ODR			(PIN_ODR_HIGH(0) | \
					PIN_ODR_HIGH(1) | \
					PIN_ODR_HIGH(2) | \
					PIN_ODR_HIGH(3) | \
					PIN_ODR_HIGH(4) | \
					PIN_ODR_HIGH(5) | \
					PIN_ODR_HIGH(6) | \
					PIN_ODR_HIGH(7) | \
					PIN_ODR_HIGH(8) | \
					PIN_ODR_HIGH(9) | \
					PIN_ODR_HIGH(10) | \
					PIN_ODR_HIGH(11) | \
					PIN_ODR_HIGH(12) | \
					PIN_ODR_HIGH(13) | \
					PIN_ODR_HIGH(14) | \
					PIN_ODR_HIGH(15))
#define VAL_GPIOB_AFRL			(PIN_AFIO_AF(0, 0) | \
					PIN_AFIO_AF(1, 0) | \
					PIN_AFIO_AF(2, 0) | \
					PIN_AFIO_AF(3, 0) | \
					PIN_AFIO_AF(4, 0) | \
					PIN_AFIO_AF(5, 0) | \
					PIN_AFIO_AF(6, 0) | \
					PIN_AFIO_AF(7, 0))
#define VAL_GPIOB_AFRH			(PIN_AFIO_AF(8, 0) | \
					PIN_AFIO_AF(9, 0) | \
					PIN_AFIO_AF(10, 0) | \
					PIN_AFIO_AF(11, 0) | \
					PIN_AFIO_AF(12, 0) | \
					PIN_AFIO_AF(13, 0) | \
					PIN_AFIO_AF(14, 0) | \
					PIN_AFIO_AF(15, 0))



#define VAL_GPIOC_MODER			(PIN_MODE_INPUT(0) | \
					PIN_MODE_INPUT(1) | \
					PIN_MODE_INPUT(2) | \
					PIN_MODE_INPUT(3) | \
					PIN_MODE_INPUT(4) | \
					PIN_MODE_INPUT(5) | \
					PIN_MODE_INPUT(6) | \
					PIN_MODE_INPUT(7) | \
					PIN_MODE_INPUT(8) | \
					PIN_MODE_INPUT(9) | \
					PIN_MODE_INPUT(10) | \
					PIN_MODE_INPUT(11) | \
					PIN_MODE_INPUT(12) | \
					PIN_MODE_INPUT(13) | \
					PIN_MODE_INPUT(14) | \
					PIN_MODE_INPUT(15))
#define VAL_GPIOC_OTYPER		(PIN_OTYPE_PUSHPULL(0) | \
					PIN_OTYPE_PUSHPULL(1) | \
					PIN_OTYPE_PUSHPULL(2) | \
					PIN_OTYPE_PUSHPULL(3) | \
					PIN_OTYPE_PUSHPULL(4) | \
					PIN_OTYPE_PUSHPULL(5) | \
					PIN_OTYPE_PUSHPULL(6) | \
					PIN_OTYPE_PUSHPULL(7) | \
					PIN_OTYPE_PUSHPULL(8) | \
					PIN_OTYPE_PUSHPULL(9) | \
					PIN_OTYPE_PUSHPULL(10) | \
					PIN_OTYPE_PUSHPULL(11) | \
					PIN_OTYPE_PUSHPULL(12) | \
					PIN_OTYPE_PUSHPULL(13) | \
					PIN_OTYPE_PUSHPULL(14) | \
					PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOC_OSPEEDR		(PIN_OSPEED_100M(0) | \
					PIN_OSPEED_100M(1) | \
					PIN_OSPEED_100M(2) | \
					PIN_OSPEED_100M(3) | \
					PIN_OSPEED_100M(4) | \
					PIN_OSPEED_100M(5) | \
					PIN_OSPEED_100M(6) | \
					PIN_OSPEED_100M(7) | \
					PIN_OSPEED_100M(8) | \
					PIN_OSPEED_100M(9) | \
					PIN_OSPEED_100M(10) | \
					PIN_OSPEED_100M(11) | \
					PIN_OSPEED_100M(12) | \
					PIN_OSPEED_100M(13) | \
					PIN_OSPEED_100M(14) | \
					PIN_OSPEED_100M(15))
#define VAL_GPIOC_PUPDR			(PIN_PUPDR_PULLUP(0) | \
					PIN_PUPDR_PULLUP(1) | \
					PIN_PUPDR_PULLUP(2) | \
					PIN_PUPDR_PULLUP(3) | \
					PIN_PUPDR_PULLUP(4) | \
					PIN_PUPDR_PULLUP(5) | \
					PIN_PUPDR_PULLUP(6) | \
					PIN_PUPDR_PULLUP(7) | \
					PIN_PUPDR_PULLUP(8) | \
					PIN_PUPDR_PULLUP(9) | \
					PIN_PUPDR_PULLUP(10) | \
					PIN_PUPDR_PULLUP(11) | \
					PIN_PUPDR_PULLUP(12) | \
					PIN_PUPDR_PULLUP(13) | \
					PIN_PUPDR_PULLUP(14) | \
					PIN_PUPDR_PULLUP(15))
#define VAL_GPIOC_ODR			(PIN_ODR_HIGH(0) | \
					PIN_ODR_HIGH(1) | \
					PIN_ODR_HIGH(2) | \
					PIN_ODR_HIGH(3) | \
					PIN_ODR_HIGH(4) | \
					PIN_ODR_HIGH(5) | \
					PIN_ODR_HIGH(6) | \
					PIN_ODR_HIGH(7) | \
					PIN_ODR_HIGH(8) | \
					PIN_ODR_HIGH(9) | \
					PIN_ODR_HIGH(10) | \
					PIN_ODR_HIGH(11) | \
					PIN_ODR_HIGH(12) | \
					PIN_ODR_HIGH(13) | \
					PIN_ODR_HIGH(14) | \
					PIN_ODR_HIGH(15))
#define VAL_GPIOC_AFRL			(PIN_AFIO_AF(0, 0) | \
					PIN_AFIO_AF(1, 0) | \
					PIN_AFIO_AF(2, 0) | \
					PIN_AFIO_AF(3, 0) | \
					PIN_AFIO_AF(4, 0) | \
					PIN_AFIO_AF(5, 0) | \
					PIN_AFIO_AF(6, 0) | \
					PIN_AFIO_AF(7, 0))
#define VAL_GPIOC_AFRH			(PIN_AFIO_AF(8, 0) | \
					PIN_AFIO_AF(9, 0) | \
					PIN_AFIO_AF(10, 0) | \
					PIN_AFIO_AF(11, 0) | \
					PIN_AFIO_AF(12, 0) | \
					PIN_AFIO_AF(13, 0) | \
					PIN_AFIO_AF(14, 0) | \
					PIN_AFIO_AF(15, 0))



#define VAL_GPIOD_MODER			(PIN_MODE_INPUT(0) | \
					PIN_MODE_INPUT(1) | \
					PIN_MODE_INPUT(2) | \
					PIN_MODE_INPUT(3) | \
					PIN_MODE_INPUT(4) | \
					PIN_MODE_INPUT(5) | \
					PIN_MODE_INPUT(6) | \
					PIN_MODE_INPUT(7) | \
					PIN_MODE_INPUT(8) | \
					PIN_MODE_INPUT(9) | \
					PIN_MODE_INPUT(10) | \
					PIN_MODE_INPUT(11) | \
					PIN_MODE_INPUT(12) | \
					PIN_MODE_INPUT(13) | \
					PIN_MODE_INPUT(14) | \
					PIN_MODE_INPUT(15))
#define VAL_GPIOD_OTYPER		(PIN_OTYPE_PUSHPULL(0) | \
					PIN_OTYPE_PUSHPULL(1) | \
					PIN_OTYPE_PUSHPULL(2) | \
					PIN_OTYPE_PUSHPULL(3) | \
					PIN_OTYPE_PUSHPULL(4) | \
					PIN_OTYPE_PUSHPULL(5) | \
					PIN_OTYPE_PUSHPULL(6) | \
					PIN_OTYPE_PUSHPULL(7) | \
					PIN_OTYPE_PUSHPULL(8) | \
					PIN_OTYPE_PUSHPULL(9) | \
					PIN_OTYPE_PUSHPULL(10) | \
					PIN_OTYPE_PUSHPULL(11) | \
					PIN_OTYPE_PUSHPULL(12) | \
					PIN_OTYPE_PUSHPULL(13) | \
					PIN_OTYPE_PUSHPULL(14) | \
					PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOD_OSPEEDR		(PIN_OSPEED_100M(0) | \
					PIN_OSPEED_100M(1) | \
					PIN_OSPEED_100M(2) | \
					PIN_OSPEED_100M(3) | \
					PIN_OSPEED_100M(4) | \
					PIN_OSPEED_100M(5) | \
					PIN_OSPEED_100M(6) | \
					PIN_OSPEED_100M(7) | \
					PIN_OSPEED_100M(8) | \
					PIN_OSPEED_100M(9) | \
					PIN_OSPEED_100M(10) | \
					PIN_OSPEED_100M(11) | \
					PIN_OSPEED_100M(12) | \
					PIN_OSPEED_100M(13) | \
					PIN_OSPEED_100M(14) | \
					PIN_OSPEED_100M(15))
#define VAL_GPIOD_PUPDR			(PIN_PUPDR_PULLUP(0) | \
					PIN_PUPDR_PULLUP(1) | \
					PIN_PUPDR_PULLUP(2) | \
					PIN_PUPDR_PULLUP(3) | \
					PIN_PUPDR_PULLUP(4) | \
					PIN_PUPDR_PULLUP(5) | \
					PIN_PUPDR_PULLUP(6) | \
					PIN_PUPDR_PULLUP(7) | \
					PIN_PUPDR_PULLUP(8) | \
					PIN_PUPDR_PULLUP(9) | \
					PIN_PUPDR_PULLUP(10) | \
					PIN_PUPDR_PULLUP(11) | \
					PIN_PUPDR_PULLUP(12) | \
					PIN_PUPDR_PULLUP(13) | \
					PIN_PUPDR_PULLUP(14) | \
					PIN_PUPDR_PULLUP(15))
#define VAL_GPIOD_ODR			(PIN_ODR_HIGH(0) | \
					PIN_ODR_HIGH(1) | \
					PIN_ODR_HIGH(2) | \
					PIN_ODR_HIGH(3) | \
					PIN_ODR_HIGH(4) | \
					PIN_ODR_HIGH(5) | \
					PIN_ODR_HIGH(6) | \
					PIN_ODR_HIGH(7) | \
					PIN_ODR_HIGH(8) | \
					PIN_ODR_HIGH(9) | \
					PIN_ODR_HIGH(10) | \
					PIN_ODR_HIGH(11) | \
					PIN_ODR_HIGH(12) | \
					PIN_ODR_HIGH(13) | \
					PIN_ODR_HIGH(14) | \
					PIN_ODR_HIGH(15))
#define VAL_GPIOD_AFRL			(PIN_AFIO_AF(0, 0) | \
					PIN_AFIO_AF(1, 0) | \
					PIN_AFIO_AF(2, 0) | \
					PIN_AFIO_AF(3, 0) | \
					PIN_AFIO_AF(4, 0) | \
					PIN_AFIO_AF(5, 0) | \
					PIN_AFIO_AF(6, 0) | \
					PIN_AFIO_AF(7, 0))
#define VAL_GPIOD_AFRH			(PIN_AFIO_AF(8, 0) | \
					PIN_AFIO_AF(9, 0) | \
					PIN_AFIO_AF(10, 0) | \
					PIN_AFIO_AF(11, 0) | \
					PIN_AFIO_AF(12, 0) | \
					PIN_AFIO_AF(13, 0) | \
					PIN_AFIO_AF(14, 0) | \
					PIN_AFIO_AF(15, 0))



#define VAL_GPIOE_MODER			(PIN_MODE_INPUT(0) | \
					PIN_MODE_INPUT(1) | \
					PIN_MODE_INPUT(2) | \
					PIN_MODE_INPUT(3) | \
					PIN_MODE_INPUT(4) | \
					PIN_MODE_INPUT(5) | \
					PIN_MODE_INPUT(6) | \
					PIN_MODE_INPUT(7) | \
					PIN_MODE_INPUT(8) | \
					PIN_MODE_INPUT(9) | \
					PIN_MODE_INPUT(10) | \
					PIN_MODE_INPUT(11) | \
					PIN_MODE_INPUT(12) | \
					PIN_MODE_INPUT(13) | \
					PIN_MODE_INPUT(14) | \
					PIN_MODE_INPUT(15))
#define VAL_GPIOE_OTYPER		(PIN_OTYPE_PUSHPULL(0) | \
					PIN_OTYPE_PUSHPULL(1) | \
					PIN_OTYPE_PUSHPULL(2) | \
					PIN_OTYPE_PUSHPULL(3) | \
					PIN_OTYPE_PUSHPULL(4) | \
					PIN_OTYPE_PUSHPULL(5) | \
					PIN_OTYPE_PUSHPULL(6) | \
					PIN_OTYPE_PUSHPULL(7) | \
					PIN_OTYPE_PUSHPULL(8) | \
					PIN_OTYPE_PUSHPULL(9) | \
					PIN_OTYPE_PUSHPULL(10) | \
					PIN_OTYPE_PUSHPULL(11) | \
					PIN_OTYPE_PUSHPULL(12) | \
					PIN_OTYPE_PUSHPULL(13) | \
					PIN_OTYPE_PUSHPULL(14) | \
					PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOE_OSPEEDR		(PIN_OSPEED_100M(0) | \
					PIN_OSPEED_100M(1) | \
					PIN_OSPEED_100M(2) | \
					PIN_OSPEED_100M(3) | \
					PIN_OSPEED_100M(4) | \
					PIN_OSPEED_100M(5) | \
					PIN_OSPEED_100M(6) | \
					PIN_OSPEED_100M(7) | \
					PIN_OSPEED_100M(8) | \
					PIN_OSPEED_100M(9) | \
					PIN_OSPEED_100M(10) | \
					PIN_OSPEED_100M(11) | \
					PIN_OSPEED_100M(12) | \
					PIN_OSPEED_100M(13) | \
					PIN_OSPEED_100M(14) | \
					PIN_OSPEED_100M(15))
#define VAL_GPIOE_PUPDR			(PIN_PUPDR_PULLUP(0) | \
					PIN_PUPDR_PULLUP(1) | \
					PIN_PUPDR_PULLUP(2) | \
					PIN_PUPDR_PULLUP(3) | \
					PIN_PUPDR_PULLUP(4) | \
					PIN_PUPDR_PULLUP(5) | \
					PIN_PUPDR_PULLUP(6) | \
					PIN_PUPDR_PULLUP(7) | \
					PIN_PUPDR_PULLUP(8) | \
					PIN_PUPDR_PULLUP(9) | \
					PIN_PUPDR_PULLUP(10) | \
					PIN_PUPDR_PULLUP(11) | \
					PIN_PUPDR_PULLUP(12) | \
					PIN_PUPDR_PULLUP(13) | \
					PIN_PUPDR_PULLUP(14) | \
					PIN_PUPDR_PULLUP(15))
#define VAL_GPIOE_ODR			(PIN_ODR_HIGH(0) | \
					PIN_ODR_HIGH(1) | \
					PIN_ODR_HIGH(2) | \
					PIN_ODR_HIGH(3) | \
					PIN_ODR_HIGH(4) | \
					PIN_ODR_HIGH(5) | \
					PIN_ODR_HIGH(6) | \
					PIN_ODR_HIGH(7) | \
					PIN_ODR_HIGH(8) | \
					PIN_ODR_HIGH(9) | \
					PIN_ODR_HIGH(10) | \
					PIN_ODR_HIGH(11) | \
					PIN_ODR_HIGH(12) | \
					PIN_ODR_HIGH(13) | \
					PIN_ODR_HIGH(14) | \
					PIN_ODR_HIGH(15))
#define VAL_GPIOE_AFRL			(PIN_AFIO_AF(0, 0) | \
					PIN_AFIO_AF(1, 0) | \
					PIN_AFIO_AF(2, 0) | \
					PIN_AFIO_AF(3, 0) | \
					PIN_AFIO_AF(4, 0) | \
					PIN_AFIO_AF(5, 0) | \
					PIN_AFIO_AF(6, 0) | \
					PIN_AFIO_AF(7, 0))
#define VAL_GPIOE_AFRH			(PIN_AFIO_AF(8, 0) | \
					PIN_AFIO_AF(9, 0) | \
					PIN_AFIO_AF(10, 0) | \
					PIN_AFIO_AF(11, 0) | \
					PIN_AFIO_AF(12, 0) | \
					PIN_AFIO_AF(13, 0) | \
					PIN_AFIO_AF(14, 0) | \
					PIN_AFIO_AF(15, 0))




#define VAL_GPIOF_MODER			(PIN_MODE_INPUT(0) | \
					PIN_MODE_INPUT(1) | \
					PIN_MODE_INPUT(2) | \
					PIN_MODE_INPUT(3) | \
					PIN_MODE_INPUT(4) | \
					PIN_MODE_INPUT(5) | \
					PIN_MODE_INPUT(6) | \
					PIN_MODE_INPUT(7) | \
					PIN_MODE_INPUT(8) | \
					PIN_MODE_INPUT(9) | \
					PIN_MODE_INPUT(10) | \
					PIN_MODE_INPUT(11) | \
					PIN_MODE_INPUT(12) | \
					PIN_MODE_INPUT(13) | \
					PIN_MODE_INPUT(14) | \
					PIN_MODE_INPUT(15))
#define VAL_GPIOF_OTYPER		(PIN_OTYPE_PUSHPULL(0) | \
					PIN_OTYPE_PUSHPULL(1) | \
					PIN_OTYPE_PUSHPULL(2) | \
					PIN_OTYPE_PUSHPULL(3) | \
					PIN_OTYPE_PUSHPULL(4) | \
					PIN_OTYPE_PUSHPULL(5) | \
					PIN_OTYPE_PUSHPULL(6) | \
					PIN_OTYPE_PUSHPULL(7) | \
					PIN_OTYPE_PUSHPULL(8) | \
					PIN_OTYPE_PUSHPULL(9) | \
					PIN_OTYPE_PUSHPULL(10) | \
					PIN_OTYPE_PUSHPULL(11) | \
					PIN_OTYPE_PUSHPULL(12) | \
					PIN_OTYPE_PUSHPULL(13) | \
					PIN_OTYPE_PUSHPULL(14) | \
					PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOF_OSPEEDR		(PIN_OSPEED_100M(0) | \
					PIN_OSPEED_100M(1) | \
					PIN_OSPEED_100M(2) | \
					PIN_OSPEED_100M(3) | \
					PIN_OSPEED_100M(4) | \
					PIN_OSPEED_100M(5) | \
					PIN_OSPEED_100M(6) | \
					PIN_OSPEED_100M(7) | \
					PIN_OSPEED_100M(8) | \
					PIN_OSPEED_100M(9) | \
					PIN_OSPEED_100M(10) | \
					PIN_OSPEED_100M(11) | \
					PIN_OSPEED_100M(12) | \
					PIN_OSPEED_100M(13) | \
					PIN_OSPEED_100M(14) | \
					PIN_OSPEED_100M(15))
#define VAL_GPIOF_PUPDR			(PIN_PUPDR_PULLUP(0) | \
					PIN_PUPDR_PULLUP(1) | \
					PIN_PUPDR_PULLUP(2) | \
					PIN_PUPDR_PULLUP(3) | \
					PIN_PUPDR_PULLUP(4) | \
					PIN_PUPDR_PULLUP(5) | \
					PIN_PUPDR_PULLUP(6) | \
					PIN_PUPDR_PULLUP(7) | \
					PIN_PUPDR_PULLUP(8) | \
					PIN_PUPDR_PULLUP(9) | \
					PIN_PUPDR_PULLUP(10) | \
					PIN_PUPDR_PULLUP(11) | \
					PIN_PUPDR_PULLUP(12) | \
					PIN_PUPDR_PULLUP(13) | \
					PIN_PUPDR_PULLUP(14) | \
					PIN_PUPDR_PULLUP(15))
#define VAL_GPIOF_ODR			(PIN_ODR_HIGH(0) | \
					PIN_ODR_HIGH(1) | \
					PIN_ODR_HIGH(2) | \
					PIN_ODR_HIGH(3) | \
					PIN_ODR_HIGH(4) | \
					PIN_ODR_HIGH(5) | \
					PIN_ODR_HIGH(6) | \
					PIN_ODR_HIGH(7) | \
					PIN_ODR_HIGH(8) | \
					PIN_ODR_HIGH(9) | \
					PIN_ODR_HIGH(10) | \
					PIN_ODR_HIGH(11) | \
					PIN_ODR_HIGH(12) | \
					PIN_ODR_HIGH(13) | \
					PIN_ODR_HIGH(14) | \
					PIN_ODR_HIGH(15))
#define VAL_GPIOF_AFRL			(PIN_AFIO_AF(0, 0) | \
					PIN_AFIO_AF(1, 0) | \
					PIN_AFIO_AF(2, 0) | \
					PIN_AFIO_AF(3, 0) | \
					PIN_AFIO_AF(4, 0) | \
					PIN_AFIO_AF(5, 0) | \
					PIN_AFIO_AF(6, 0) | \
					PIN_AFIO_AF(7, 0))
#define VAL_GPIOF_AFRH			(PIN_AFIO_AF(8, 0) | \
					PIN_AFIO_AF(9, 0) | \
					PIN_AFIO_AF(10, 0) | \
					PIN_AFIO_AF(11, 0) | \
					PIN_AFIO_AF(12, 0) | \
					PIN_AFIO_AF(13, 0) | \
					PIN_AFIO_AF(14, 0) | \
					PIN_AFIO_AF(15, 0))




#define VAL_GPIOG_MODER			(PIN_MODE_INPUT(0) | \
					PIN_MODE_INPUT(1) | \
					PIN_MODE_INPUT(2) | \
					PIN_MODE_INPUT(3) | \
					PIN_MODE_INPUT(4) | \
					PIN_MODE_INPUT(5) | \
					PIN_MODE_INPUT(6) | \
					PIN_MODE_INPUT(7) | \
					PIN_MODE_INPUT(8) | \
					PIN_MODE_INPUT(9) | \
					PIN_MODE_INPUT(10) | \
					PIN_MODE_INPUT(11) | \
					PIN_MODE_INPUT(12) | \
					PIN_MODE_INPUT(13) | \
					PIN_MODE_INPUT(14) | \
					PIN_MODE_INPUT(15))
#define VAL_GPIOG_OTYPER		(PIN_OTYPE_PUSHPULL(0) | \
					PIN_OTYPE_PUSHPULL(1) | \
					PIN_OTYPE_PUSHPULL(2) | \
					PIN_OTYPE_PUSHPULL(3) | \
					PIN_OTYPE_PUSHPULL(4) | \
					PIN_OTYPE_PUSHPULL(5) | \
					PIN_OTYPE_PUSHPULL(6) | \
					PIN_OTYPE_PUSHPULL(7) | \
					PIN_OTYPE_PUSHPULL(8) | \
					PIN_OTYPE_PUSHPULL(9) | \
					PIN_OTYPE_PUSHPULL(10) | \
					PIN_OTYPE_PUSHPULL(11) | \
					PIN_OTYPE_PUSHPULL(12) | \
					PIN_OTYPE_PUSHPULL(13) | \
					PIN_OTYPE_PUSHPULL(14) | \
					PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOG_OSPEEDR		(PIN_OSPEED_100M(0) | \
					PIN_OSPEED_100M(1) | \
					PIN_OSPEED_100M(2) | \
					PIN_OSPEED_100M(3) | \
					PIN_OSPEED_100M(4) | \
					PIN_OSPEED_100M(5) | \
					PIN_OSPEED_100M(6) | \
					PIN_OSPEED_100M(7) | \
					PIN_OSPEED_100M(8) | \
					PIN_OSPEED_100M(9) | \
					PIN_OSPEED_100M(10) | \
					PIN_OSPEED_100M(11) | \
					PIN_OSPEED_100M(12) | \
					PIN_OSPEED_100M(13) | \
					PIN_OSPEED_100M(14) | \
					PIN_OSPEED_100M(15))
#define VAL_GPIOG_PUPDR			(PIN_PUPDR_PULLUP(0) | \
					PIN_PUPDR_PULLUP(1) | \
					PIN_PUPDR_PULLUP(2) | \
					PIN_PUPDR_PULLUP(3) | \
					PIN_PUPDR_PULLUP(4) | \
					PIN_PUPDR_PULLUP(5) | \
					PIN_PUPDR_PULLUP(6) | \
					PIN_PUPDR_PULLUP(7) | \
					PIN_PUPDR_PULLUP(8) | \
					PIN_PUPDR_PULLUP(9) | \
					PIN_PUPDR_PULLUP(10) | \
					PIN_PUPDR_PULLUP(11) | \
					PIN_PUPDR_PULLUP(12) | \
					PIN_PUPDR_PULLUP(13) | \
					PIN_PUPDR_PULLUP(14) | \
					PIN_PUPDR_PULLUP(15))
#define VAL_GPIOG_ODR			(PIN_ODR_HIGH(0) | \
					PIN_ODR_HIGH(1) | \
					PIN_ODR_HIGH(2) | \
					PIN_ODR_HIGH(3) | \
					PIN_ODR_HIGH(4) | \
					PIN_ODR_HIGH(5) | \
					PIN_ODR_HIGH(6) | \
					PIN_ODR_HIGH(7) | \
					PIN_ODR_HIGH(8) | \
					PIN_ODR_HIGH(9) | \
					PIN_ODR_HIGH(10) | \
					PIN_ODR_HIGH(11) | \
					PIN_ODR_HIGH(12) | \
					PIN_ODR_HIGH(13) | \
					PIN_ODR_HIGH(14) | \
					PIN_ODR_HIGH(15))
#define VAL_GPIOG_AFRL			(PIN_AFIO_AF(0, 0) | \
					PIN_AFIO_AF(1, 0) | \
					PIN_AFIO_AF(2, 0) | \
					PIN_AFIO_AF(3, 0) | \
					PIN_AFIO_AF(4, 0) | \
					PIN_AFIO_AF(5, 0) | \
					PIN_AFIO_AF(6, 0) | \
					PIN_AFIO_AF(7, 0))
#define VAL_GPIOG_AFRH			(PIN_AFIO_AF(8, 0) | \
					PIN_AFIO_AF(9, 0) | \
					PIN_AFIO_AF(10, 0) | \
					PIN_AFIO_AF(11, 0) | \
					PIN_AFIO_AF(12, 0) | \
					PIN_AFIO_AF(13, 0) | \
					PIN_AFIO_AF(14, 0) | \
					PIN_AFIO_AF(15, 0))



#define VAL_GPIOH_MODER			(PIN_MODE_INPUT(0) | \
					PIN_MODE_INPUT(1) | \
					PIN_MODE_INPUT(2) | \
					PIN_MODE_INPUT(3) | \
					PIN_MODE_INPUT(4) | \
					PIN_MODE_INPUT(5) | \
					PIN_MODE_INPUT(6) | \
					PIN_MODE_INPUT(7) | \
					PIN_MODE_INPUT(8) | \
					PIN_MODE_INPUT(9) | \
					PIN_MODE_INPUT(10) | \
					PIN_MODE_INPUT(11) | \
					PIN_MODE_INPUT(12) | \
					PIN_MODE_INPUT(13) | \
					PIN_MODE_INPUT(14) | \
					PIN_MODE_INPUT(15))
#define VAL_GPIOH_OTYPER		(PIN_OTYPE_PUSHPULL(0) | \
					PIN_OTYPE_PUSHPULL(1) | \
					PIN_OTYPE_PUSHPULL(2) | \
					PIN_OTYPE_PUSHPULL(3) | \
					PIN_OTYPE_PUSHPULL(4) | \
					PIN_OTYPE_PUSHPULL(5) | \
					PIN_OTYPE_PUSHPULL(6) | \
					PIN_OTYPE_PUSHPULL(7) | \
					PIN_OTYPE_PUSHPULL(8) | \
					PIN_OTYPE_PUSHPULL(9) | \
					PIN_OTYPE_PUSHPULL(10) | \
					PIN_OTYPE_PUSHPULL(11) | \
					PIN_OTYPE_PUSHPULL(12) | \
					PIN_OTYPE_PUSHPULL(13) | \
					PIN_OTYPE_PUSHPULL(14) | \
					PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOH_OSPEEDR		(PIN_OSPEED_100M(0) | \
					PIN_OSPEED_100M(1) | \
					PIN_OSPEED_100M(2) | \
					PIN_OSPEED_100M(3) | \
					PIN_OSPEED_100M(4) | \
					PIN_OSPEED_100M(5) | \
					PIN_OSPEED_100M(6) | \
					PIN_OSPEED_100M(7) | \
					PIN_OSPEED_100M(8) | \
					PIN_OSPEED_100M(9) | \
					PIN_OSPEED_100M(10) | \
					PIN_OSPEED_100M(11) | \
					PIN_OSPEED_100M(12) | \
					PIN_OSPEED_100M(13) | \
					PIN_OSPEED_100M(14) | \
					PIN_OSPEED_100M(15))
#define VAL_GPIOH_PUPDR			(PIN_PUPDR_PULLUP(0) | \
					PIN_PUPDR_PULLUP(1) | \
					PIN_PUPDR_PULLUP(2) | \
					PIN_PUPDR_PULLUP(3) | \
					PIN_PUPDR_PULLUP(4) | \
					PIN_PUPDR_PULLUP(5) | \
					PIN_PUPDR_PULLUP(6) | \
					PIN_PUPDR_PULLUP(7) | \
					PIN_PUPDR_PULLUP(8) | \
					PIN_PUPDR_PULLUP(9) | \
					PIN_PUPDR_PULLUP(10) | \
					PIN_PUPDR_PULLUP(11) | \
					PIN_PUPDR_PULLUP(12) | \
					PIN_PUPDR_PULLUP(13) | \
					PIN_PUPDR_PULLUP(14) | \
					PIN_PUPDR_PULLUP(15))
#define VAL_GPIOH_ODR			(PIN_ODR_HIGH(0) | \
					PIN_ODR_HIGH(1) | \
					PIN_ODR_HIGH(2) | \
					PIN_ODR_HIGH(3) | \
					PIN_ODR_HIGH(4) | \
					PIN_ODR_HIGH(5) | \
					PIN_ODR_HIGH(6) | \
					PIN_ODR_HIGH(7) | \
					PIN_ODR_HIGH(8) | \
					PIN_ODR_HIGH(9) | \
					PIN_ODR_HIGH(10) | \
					PIN_ODR_HIGH(11) | \
					PIN_ODR_HIGH(12) | \
					PIN_ODR_HIGH(13) | \
					PIN_ODR_HIGH(14) | \
					PIN_ODR_HIGH(15))
#define VAL_GPIOH_AFRL			(PIN_AFIO_AF(0, 0) | \
					PIN_AFIO_AF(1, 0) | \
					PIN_AFIO_AF(2, 0) | \
					PIN_AFIO_AF(3, 0) | \
					PIN_AFIO_AF(4, 0) | \
					PIN_AFIO_AF(5, 0) | \
					PIN_AFIO_AF(6, 0) | \
					PIN_AFIO_AF(7, 0))
#define VAL_GPIOH_AFRH			(PIN_AFIO_AF(8, 0) | \
					PIN_AFIO_AF(9, 0) | \
					PIN_AFIO_AF(10, 0) | \
					PIN_AFIO_AF(11, 0) | \
					PIN_AFIO_AF(12, 0) | \
					PIN_AFIO_AF(13, 0) | \
					PIN_AFIO_AF(14, 0) | \
					PIN_AFIO_AF(15, 0))


#define VAL_GPIOI_MODER			(PIN_MODE_INPUT(0) | \
					PIN_MODE_INPUT(1) | \
					PIN_MODE_INPUT(2) | \
					PIN_MODE_INPUT(3) | \
					PIN_MODE_INPUT(4) | \
					PIN_MODE_INPUT(5) | \
					PIN_MODE_INPUT(6) | \
					PIN_MODE_INPUT(7) | \
					PIN_MODE_INPUT(8) | \
					PIN_MODE_INPUT(9) | \
					PIN_MODE_INPUT(10) | \
					PIN_MODE_INPUT(11) | \
					PIN_MODE_INPUT(12) | \
					PIN_MODE_INPUT(13) | \
					PIN_MODE_INPUT(14) | \
					PIN_MODE_INPUT(15))
#define VAL_GPIOI_OTYPER		(PIN_OTYPE_PUSHPULL(0) | \
					PIN_OTYPE_PUSHPULL(1) | \
					PIN_OTYPE_PUSHPULL(2) | \
					PIN_OTYPE_PUSHPULL(3) | \
					PIN_OTYPE_PUSHPULL(4) | \
					PIN_OTYPE_PUSHPULL(5) | \
					PIN_OTYPE_PUSHPULL(6) | \
					PIN_OTYPE_PUSHPULL(7) | \
					PIN_OTYPE_PUSHPULL(8) | \
					PIN_OTYPE_PUSHPULL(9) | \
					PIN_OTYPE_PUSHPULL(10) | \
					PIN_OTYPE_PUSHPULL(11) | \
					PIN_OTYPE_PUSHPULL(12) | \
					PIN_OTYPE_PUSHPULL(13) | \
					PIN_OTYPE_PUSHPULL(14) | \
					PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOI_OSPEEDR		(PIN_OSPEED_100M(0) | \
					PIN_OSPEED_100M(1) | \
					PIN_OSPEED_100M(2) | \
					PIN_OSPEED_100M(3) | \
					PIN_OSPEED_100M(4) | \
					PIN_OSPEED_100M(5) | \
					PIN_OSPEED_100M(6) | \
					PIN_OSPEED_100M(7) | \
					PIN_OSPEED_100M(8) | \
					PIN_OSPEED_100M(9) | \
					PIN_OSPEED_100M(10) | \
					PIN_OSPEED_100M(11) | \
					PIN_OSPEED_100M(12) | \
					PIN_OSPEED_100M(13) | \
					PIN_OSPEED_100M(14) | \
					PIN_OSPEED_100M(15))
#define VAL_GPIOI_PUPDR			(PIN_PUPDR_PULLUP(0) | \
					PIN_PUPDR_PULLUP(1) | \
					PIN_PUPDR_PULLUP(2) | \
					PIN_PUPDR_PULLUP(3) | \
					PIN_PUPDR_PULLUP(4) | \
					PIN_PUPDR_PULLUP(5) | \
					PIN_PUPDR_PULLUP(6) | \
					PIN_PUPDR_PULLUP(7) | \
					PIN_PUPDR_PULLUP(8) | \
					PIN_PUPDR_PULLUP(9) | \
					PIN_PUPDR_PULLUP(10) | \
					PIN_PUPDR_PULLUP(11) | \
					PIN_PUPDR_PULLUP(12) | \
					PIN_PUPDR_PULLUP(13) | \
					PIN_PUPDR_PULLUP(14) | \
					PIN_PUPDR_PULLUP(15))
#define VAL_GPIOI_ODR			(PIN_ODR_HIGH(0) | \
					PIN_ODR_HIGH(1) | \
					PIN_ODR_HIGH(2) | \
					PIN_ODR_HIGH(3) | \
					PIN_ODR_HIGH(4) | \
					PIN_ODR_HIGH(5) | \
					PIN_ODR_HIGH(6) | \
					PIN_ODR_HIGH(7) | \
					PIN_ODR_HIGH(8) | \
					PIN_ODR_HIGH(9) | \
					PIN_ODR_HIGH(10) | \
					PIN_ODR_HIGH(11) | \
					PIN_ODR_HIGH(12) | \
					PIN_ODR_HIGH(13) | \
					PIN_ODR_HIGH(14) | \
					PIN_ODR_HIGH(15))
#define VAL_GPIOI_AFRL			(PIN_AFIO_AF(0, 0) | \
					PIN_AFIO_AF(1, 0) | \
					PIN_AFIO_AF(2, 0) | \
					PIN_AFIO_AF(3, 0) | \
					PIN_AFIO_AF(4, 0) | \
					PIN_AFIO_AF(5, 0) | \
					PIN_AFIO_AF(6, 0) | \
					PIN_AFIO_AF(7, 0))
#define VAL_GPIOI_AFRH			(PIN_AFIO_AF(8, 0) | \
					PIN_AFIO_AF(9, 0) | \
					PIN_AFIO_AF(10, 0) | \
					PIN_AFIO_AF(11, 0) | \
					PIN_AFIO_AF(12, 0) | \
					PIN_AFIO_AF(13, 0) | \
					PIN_AFIO_AF(14, 0) | \
					PIN_AFIO_AF(15, 0))



#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
