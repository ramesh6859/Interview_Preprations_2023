#include "ProfileHandler.h"
#include "CommandHelper.h"
#include "UartDriver.h"
#include "CurrentDriver.h"
#include "TimeHandler.h"
#include "DwinCommandHandler.h"
#include "CommonBuffer.h"
#include "StdTypes.h"

#define STEP_CLEAR_FIELD(x)    executeDWINCommand(x);
#define STEP_TEXT_PENDING(x)   executeDWINCommand(x);
#define STEP_TEXT_RUNNING(x)   executeDWINCommand(x);
#define STEP_TEXT_COMPLETED(x) executeDWINCommand(x);

uint8_t rawBuffer[BUFFER_SIZE];
static uint8_t profileIndex;

Std_ReturnType runProfile(uint8_t command)
{
    Std_ReturnType retVal = STD_NOT_OK;
    setCurrentZero();
    retVal = getProfile(command);

    if (retVal != STD_NOT_OK)
    {
        defaultSteps();
        cleanProfile();
        retVal = storeProfile();

        if (retVal != STD_NOT_OK)
        {
            retVal = setPeripherals();

            if (Admin == STD_ACTIVE)
            {
                defaultSteps();
                Delay_ms(500);
                if (command >= 0xEU && command <= 0x2AU)
                {
                    executeDWINCommand(SWITCH_ADMIN_PAGE_1);
                }
                else if (command >= 0x31U && command <= 0x4DU)
                {
                    executeDWINCommand(SWITCH_ADMIN_PAGE_2);
                }
                else if (command >= 0x54U && command <= 0x70U)
                {
                    executeDWINCommand(SWITCH_ADMIN_PAGE_3);
                }
                else if (command >= 0x77U && command <= 0x93U)
                {
                    executeDWINCommand(SWITCH_ADMIN_PAGE_4);
                }
            }
            else
            {
                defaultSteps();
                Delay_ms(500);
                if (command >= 0xEU && command <= 0x2AU)
                {
                    executeDWINCommand(SWITCH_USER_PAGE_1);
                }
                else if (command >= 0x31U && command <= 0x4DU)
                {
                    executeDWINCommand(SWITCH_USER_PAGE_2);
                }
                else if (command >= 0x54U && command <= 0x70U)
                {
                    executeDWINCommand(SWITCH_USER_PAGE_3);
                }
                else if (command >= 0x77U && command <= 0x93U)
                {
                    executeDWINCommand(SWITCH_USER_PAGE_4);
                }
            }
        }
    }
    flushRxBuffer();
    return retVal;
}

Std_ReturnType getProfile(uint8_t command)
{
    Std_ReturnType retVal = STD_NOT_OK;
    uint8_t _it  = 0;
    uint8_t __it = 0;

    executeDWINCommand(command);
    profileIndex = getDataLen(receivedString);
    memset(rawBuffer, 0, sizeof(rawBuffer));

    if (profileIndex != 0)
        retVal = STD_OK;
    if( retVal != STD_NOT_OK)
    {
      for (_it = VALID_DATA_INDEX, __it; _it < profileIndex, __it < profileIndex; _it++, __it++)
          rawBuffer[__it] = receivedString[_it];
    }
    flushRxBuffer();

    return retVal;
}

Std_ReturnType storeProfile(void)
{
    Std_ReturnType retVal = STD_NOT_OK;
    uint8_t ___it = 0;

    retVal = (profileIndex > 0) ? STD_OK : STD_NOT_OK;

    if (retVal != STD_NOT_OK)
    {
        for (___it; ___it < profileIndex; ___it++)
            EEPROM_Write(___it, rawBuffer[___it]);
    }

    return retVal;
}

Std_ReturnType cleanProfile(void)
{
    uint8_t ___it = 0;

    for (___it; ___it < 0xFF; ___it++)
        EEPROM_Write(___it, 0xFF);

    return STD_OK;
}

uint8_t readProfile(uint8_t address)
{
    return EEPROM_Read(address);
}

Std_ReturnType setPeripherals(void)
{
    Std_ReturnType retVal = STD_NOT_OK;

    uint8_t _it10           = 0x00U;
    uint8_t Current_MSB_INC = 0x00U;
    uint8_t Current_LSB_INC = 0x01U;
    uint8_t Time_MSB_INC    = 0x02U;
    uint8_t Time_LSB_INC    = 0x03U;
    uint16_t Current;
    uint16_t Time;

    for (_it10; _it10 < TOTAL_STEPS; _it10++)
    {
        uint8_t Current_MSB = readProfile(Current_MSB_INC);
        uint8_t Current_LSB = readProfile(Current_LSB_INC);
        uint8_t Time_MSB    = readProfile(Time_MSB_INC);
        uint8_t Time_LSB    = readProfile(Time_LSB_INC);

        Current_MSB_INC += INC_BY_4;
        Current_LSB_INC += INC_BY_4;
        Time_MSB_INC    += INC_BY_4;
        Time_LSB_INC    += INC_BY_4;

        Current = (((uint16_t)Current_MSB << 8) | (uint16_t)Current_LSB);
        Time = (((uint16_t)Time_MSB << 8) | (uint16_t)Time_LSB);

        switch (_it10)
        {
        case 0:
            STEP_CLEAR_FIELD(STEP1_CLEAR_FIELD);
            STEP_TEXT_RUNNING(STEP1_TEXT_RUNNING);
            break;
        case 1:
            STEP_CLEAR_FIELD(STEP1_CLEAR_FIELD);
            STEP_TEXT_COMPLETED(STEP1_TEXT_COMPLETED);
            STEP_CLEAR_FIELD(STEP2_CLEAR_FIELD);
            STEP_TEXT_RUNNING(STEP2_TEXT_RUNNING);
            break;
        case 2:
            STEP_CLEAR_FIELD(STEP2_CLEAR_FIELD);
            STEP_TEXT_COMPLETED(STEP2_TEXT_COMPLETED);
            STEP_CLEAR_FIELD(STEP3_CLEAR_FIELD);
            STEP_TEXT_RUNNING(STEP3_TEXT_RUNNING);
            break;
        case 3:
            STEP_CLEAR_FIELD(STEP3_CLEAR_FIELD);
            STEP_TEXT_COMPLETED(STEP3_TEXT_COMPLETED);
            STEP_CLEAR_FIELD(STEP4_CLEAR_FIELD);
            STEP_TEXT_RUNNING(STEP4_TEXT_RUNNING);
            break;
        case 4:
            STEP_CLEAR_FIELD(STEP4_CLEAR_FIELD);
            STEP_TEXT_COMPLETED(STEP4_TEXT_COMPLETED);
            STEP_CLEAR_FIELD(STEP5_CLEAR_FIELD);
            STEP_TEXT_RUNNING(STEP5_TEXT_RUNNING);
            break;
        case 5:
            STEP_CLEAR_FIELD(STEP5_CLEAR_FIELD);
            STEP_TEXT_COMPLETED(STEP5_TEXT_COMPLETED);
            STEP_CLEAR_FIELD(STEP6_CLEAR_FIELD);
            STEP_TEXT_RUNNING(STEP6_TEXT_RUNNING);
            break;
        case 6:
            STEP_CLEAR_FIELD(STEP6_CLEAR_FIELD);
            STEP_TEXT_COMPLETED(STEP6_TEXT_COMPLETED);
            STEP_CLEAR_FIELD(STEP7_CLEAR_FIELD);
            STEP_TEXT_RUNNING(STEP7_TEXT_RUNNING);
            break;
        case 7:
            STEP_CLEAR_FIELD(STEP7_CLEAR_FIELD);
            STEP_TEXT_COMPLETED(STEP7_TEXT_COMPLETED);
            STEP_CLEAR_FIELD(STEP8_CLEAR_FIELD);
            STEP_TEXT_RUNNING(STEP8_TEXT_RUNNING);
            break;
        case 8:
            STEP_CLEAR_FIELD(STEP8_CLEAR_FIELD);
            STEP_TEXT_COMPLETED(STEP8_TEXT_COMPLETED);
            STEP_CLEAR_FIELD(STEP9_CLEAR_FIELD);
            STEP_TEXT_RUNNING(STEP9_TEXT_RUNNING);
            break;
        case 9:
            STEP_CLEAR_FIELD(STEP9_CLEAR_FIELD);
            STEP_TEXT_COMPLETED(STEP9_TEXT_COMPLETED);
            STEP_CLEAR_FIELD(STEP10_CLEAR_FIELD);
            STEP_TEXT_RUNNING(STEP10_TEXT_RUNNING);
            break;
        default:
            break;
        }
        setCurrentValue(Current);
        delaySeconds(Time);
    }

    STEP_CLEAR_FIELD(STEP10_CLEAR_FIELD);
    STEP_TEXT_COMPLETED(STEP10_TEXT_COMPLETED);
    
    setCurrentZero();
    retVal = STD_OK;
    return retVal;
}

void defaultSteps(void)
{

    STEP_CLEAR_FIELD(STEP1_CLEAR_FIELD);
    STEP_TEXT_PENDING(STEP1_TEXT_PENDING);

    STEP_CLEAR_FIELD(STEP2_CLEAR_FIELD);
    STEP_TEXT_PENDING(STEP2_TEXT_PENDING);

    STEP_CLEAR_FIELD(STEP3_CLEAR_FIELD);
    STEP_TEXT_PENDING(STEP3_TEXT_PENDING);

    STEP_CLEAR_FIELD(STEP4_CLEAR_FIELD);
    STEP_TEXT_PENDING(STEP4_TEXT_PENDING);

    STEP_CLEAR_FIELD(STEP5_CLEAR_FIELD);
    STEP_TEXT_PENDING(STEP5_TEXT_PENDING);

    STEP_CLEAR_FIELD(STEP6_CLEAR_FIELD);
    STEP_TEXT_PENDING(STEP6_TEXT_PENDING);

    STEP_CLEAR_FIELD(STEP7_CLEAR_FIELD);
    STEP_TEXT_PENDING(STEP7_TEXT_PENDING);

    STEP_CLEAR_FIELD(STEP8_CLEAR_FIELD);
    STEP_TEXT_PENDING(STEP8_TEXT_PENDING);

    STEP_CLEAR_FIELD(STEP9_CLEAR_FIELD);
    STEP_TEXT_PENDING(STEP9_TEXT_PENDING);

    STEP_CLEAR_FIELD(STEP10_CLEAR_FIELD);
    STEP_TEXT_PENDING(STEP10_TEXT_PENDING);
    
    flushRxBuffer();
}