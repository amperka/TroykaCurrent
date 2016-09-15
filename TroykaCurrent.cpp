/****************************************************************************/
//  Function:       Cpp file for TroykaCurrent
//  Hardware:       ACS712-05
//  Arduino IDE:    Arduino-1.6.11
//  Author:         Igor Dementiev
//  Date:           Sep 09,2016
//  Version:        v1.0
//  by www.amperka.ru
/****************************************************************************/

#include "TroykaCurrent.h"

#define ADC_COUNT           1023
#define ADC_COUNT_HALF      ADC_COUNT / 2
#define ADC_COUNT_ACS712_1A 37.88
#define RMS                 0.707
#define SAMPLE_TIMES        32
#define FAULT_ADC           0.011

ACS712::ACS712(uint8_t pin) {
    _pin = pin;
}

float ACS712::readCurrentDC() {
    int sensorValue = 0;
    float sensorCurrent = 0;
    for (int i = 0; i < SAMPLE_TIMES; i++) {
        sensorValue += analogRead(_pin);
    }
    sensorValue = sensorValue >> 5;
    sensorCurrent = (sensorValue - ADC_COUNT_HALF) / ADC_COUNT_ACS712_1A;
    return sensorCurrent;
}

float ACS712::readCurrentAC() {
    int sensorValue = 0;
    int maxValue = 0;
    int minValue = ADC_COUNT;
    float sensorCurrent = 0;
    float sensorCurrentRMS = 0;
    unsigned long startTime = millis();
    while ((millis() - startTime) < 60) {
        sensorValue = analogRead(_pin);
        if (sensorValue > maxValue) {
            maxValue = sensorValue;
        } else if (sensorValue < minValue) {
            minValue = sensorValue;
        }
    }
    maxValue -= maxValue * FAULT_ADC;
    minValue += minValue * FAULT_ADC;
    sensorCurrent = (((maxValue) - minValue) / 2.0) / ADC_COUNT_ACS712_1A;
    sensorCurrentRMS = sensorCurrent * RMS;
    return sensorCurrentRMS;
}
