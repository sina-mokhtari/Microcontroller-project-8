/*
 * globals.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Sina
 */

#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_

typedef enum {
	ASCENDING, DESCENDING
} xChangingMode;

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;

extern I2C_HandleTypeDef hi2c1;

extern SPI_HandleTypeDef hspi1;

extern TIM_HandleTypeDef htim6;

extern UART_HandleTypeDef huart2;

extern PCD_HandleTypeDef hpcd_USB_FS;

extern int x;
extern int keypadNum;
extern double xSin;
extern double xCos;
extern double xCubeRoot;

extern xChangingMode mode;

extern uint_fast32_t light, volume;

extern char str[100];

#endif /* INC_GLOBALS_H_ */
