/*
 * init.c
 *
 *  Created on: Jun 11, 2022
 *      Author: Sina
 */

#include "requisite.h"
#include "keypad.h"

void init() {
	HAL_TIM_Base_Start_IT(&htim6);
	HAL_ADC_Start_IT(&hadc1);
	HAL_ADC_Start_IT(&hadc2);

	for (int i = 0; i < 4; i++)
		HAL_GPIO_WritePin(Column_ports[i], Column_pins[i], GPIO_PIN_SET);
}
