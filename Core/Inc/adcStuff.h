/*
 * adcStuff.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Sina
 */

#ifndef INC_ADCSTUFF_H_
#define INC_ADCSTUFF_H_

#define VOLUME_DEFAULT 10
#define LIGHT_DEFAULT 10
#define VOLUME_LIGHT_FILTERING_SAMPLE_NUM 16
#define ADC_DELAY 20

void handleVolume(ADC_HandleTypeDef *hadc);
void handleLight(ADC_HandleTypeDef *hadc);

#endif /* INC_ADCSTUFF_H_ */
