/*
 * keypad.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Sina
 */

#ifndef SRC_KEYPAD_H_
#define SRC_KEYPAD_H_

extern GPIO_TypeDef *const Row_ports[];
extern const uint16_t Row_pins[];
extern GPIO_TypeDef *const Column_ports[];
extern const uint16_t Column_pins[];
extern uint32_t last_gpio_exti;

void handleKeypad(uint16_t GPIO_Pin);

#endif /* SRC_KEYPAD_H_ */
