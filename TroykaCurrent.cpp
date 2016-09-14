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

ACS712::ACS712(uint8_t pin) {
    _pin = pin;
}

void ACS712::begin() {
}

float ACS712::readCurrentDC() {
	int sensorValue = 0;
  	float sensorVoltage = 0;
  	float sensorCurrent = 0;
	for (int i = 0; i < SAMPLE_TIMES; i++) {
    	sensorValue += analogRead(_pin);
    	delay(SAMPLE_INTERVAL);
  	}
  	sensorValue = sensorValue >> 5;
  	sensorCurrent = (sensorValue - ADC_COUNT / 2) / 37.888;
  	return sensorCurrent;
}
// 
float ACS712::readCurrentAC() {
  	int sensorValue;
  	int maxValue = 0;
  	int minValue = ADC_COUNT;
  	float sum;
  	float sensorVoltageAMP;
  	float sensorVoltageRMS;
  	float sensorCurrentRMS;
  	unsigned long startTime = millis();
  	while((millis() - startTime) < 200) {
    	sensorValue = analogRead(_pin);
    	if (sensorValue > maxValue) {
      		maxValue = sensorValue;
    	} else if (sensorValue < minValue) {
        	minValue = sensorValue;
    	}
  	}
  	maxValue -= maxValue * FAULT_ADC;
  	minValue += minValue * FAULT_ADC;
  	sensorVoltageAMP = (((maxValue) - minValue) / 2.0)  * (VCC / ADC_COUNT);
  	sensorVoltageRMS = sensorVoltageAMP * RMS;
  	sensorCurrentRMS = sensorVoltageRMS / ACS712_05;
  	return sensorCurrentRMS;
}
