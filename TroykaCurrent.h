/****************************************************************************/
//  Function:       Header file for TroykaCurrent
//  Hardware:       ACS712-05
//  Arduino IDE:    Arduino-1.6.11
//  Author:         Igor Dementiev
//  Date:           Sep 09,2016
//  Version:        v1.0
//  by www.amperka.ru
/****************************************************************************/

#ifndef TROYKA_CURRENT_H_
#define TROYKA_CURRENT_H_

#include <Arduino.h>

#define RMS              0.707
#define VREF             5.0
#define ACS712_05        0.185
#define SAMPLE_TIMES     50
#define SAMPLE_INTERVAL  1
#define FAULT_ADC		 0.011

class ACS712
{
public:
    ACS712(uint8_t pin);
    void begin();
    float readCurrentDC();
    float readCurrentAC();
private:
    uint8_t _pin;
};
#endif  // TROYKA_CURRENT_H_
