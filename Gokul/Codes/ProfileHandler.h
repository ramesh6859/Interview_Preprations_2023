#ifndef PROFILE_HANDLER_H
#define PROFILE_HANDLER_H

#include <stdint.h>
#include "StdTypes.h"

#define VALID_DATA_INDEX 7
#define TOTAL_STEPS 10
#define INC_BY_4 0x04U

Std_ReturnType runProfile(uint8_t command);
Std_ReturnType getProfile(uint8_t command);
Std_ReturnType storeProfile(void);
Std_ReturnType cleanProfile(void);
uint8_t readProfile(uint8_t address);
Std_ReturnType setPeripherals(void);
void defaultSteps(void);

#endif /* PROFILE_HANDLER_H */