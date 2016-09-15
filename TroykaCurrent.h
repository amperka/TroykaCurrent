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

class ACS712
{
public:
    ACS712(uint8_t pin);
    float readCurrentDC();
    float readCurrentAC();
private:
    uint8_t _pin;
};
#endif  // TROYKA_CURRENT_H_
