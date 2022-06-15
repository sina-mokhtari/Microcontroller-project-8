/*
 * adcStuff.c
 *
 *  Created on: Jun 11, 2022
 *      Author: Sina
 */

#include <math.h>
#include "requisite.h"
#include "adcStuff.h"

uint_fast32_t rightShiftValue;
uint_fast32_t volumeRawValue, lightRawValue;
uint_fast32_t normalLight, normalVolume;
uint_fast32_t volumeSamplingSum = VOLUME_DEFAULT * VOLUME_LIGHT_FILTERING_SAMPLE_NUM,
        lightSamplingSum = LIGHT_DEFAULT * VOLUME_LIGHT_FILTERING_SAMPLE_NUM;
uint_fast32_t lightSamplingIdx = 0, volumeSamplingIdx = 0;

uint_fast16_t volumeSamplingArr[VOLUME_LIGHT_FILTERING_SAMPLE_NUM] = {
        [0 ... VOLUME_LIGHT_FILTERING_SAMPLE_NUM - 1] = VOLUME_DEFAULT};
uint_fast16_t lightSamplingArr[VOLUME_LIGHT_FILTERING_SAMPLE_NUM] = {
        [0 ... VOLUME_LIGHT_FILTERING_SAMPLE_NUM - 1] = LIGHT_DEFAULT};

void adcInit() {
    rightShiftValue = log2(VOLUME_LIGHT_FILTERING_SAMPLE_NUM);
}

void handleVolume(ADC_HandleTypeDef *hadc) {
    volumeRawValue = HAL_ADC_GetValue(hadc);

    normalVolume = (uint_fast32_t) ((float) volumeRawValue / 40);    // simplified of (x - 0) * 100 / (4000 - 0);

    volumeSamplingSum += normalVolume - volumeSamplingArr[volumeSamplingIdx];

    volumeSamplingArr[volumeSamplingIdx] = normalVolume;

    volume = volumeSamplingSum >> rightShiftValue;
    volume = volume > 100 ? 100 : volume;

    volumeSamplingIdx = (volumeSamplingIdx + 1) % VOLUME_LIGHT_FILTERING_SAMPLE_NUM;

}

void handleLight(ADC_HandleTypeDef *hadc) {
    lightRawValue = HAL_ADC_GetValue(hadc);

    normalLight = (uint_fast32_t) ((float) lightRawValue / 10); // simplified of (x - 0) * 100 / (1000 - 0)

    lightSamplingSum += normalLight - lightSamplingArr[lightSamplingIdx];

    lightSamplingArr[lightSamplingIdx] = normalLight;

    light = lightSamplingSum >> rightShiftValue;
    light = light > 100 ? 100 : light;

    lightSamplingIdx = (lightSamplingIdx + 1) % VOLUME_LIGHT_FILTERING_SAMPLE_NUM;

}

