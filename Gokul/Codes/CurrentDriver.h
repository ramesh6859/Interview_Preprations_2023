#ifndef CURRENT_DRIVER_H
#define CURRENT_DRIVER_H

#include "StdTypes.h"

#define inMin 0x01U
#define inMax 0x1388U
#define outMin 0x08U
#define outMax 0xEA1U

sbit CS at LATC1_bit;

sbit CS_Direction at TRISC1_bit;

/* Initializes the current driver */
Std_ReturnType initCurrentDriver(void);

/* Sets the current value */
Std_ReturnType setCurrentValue(uint16_t mA);

/* Sets the current value to zero */
Std_ReturnType setCurrentZero(void);

/* Maps the raw current value to the desired range */
uint16_t mapCurrentValue(uint16_t raw_mA);

#endif /* CURRENT_DRIVER_H */

