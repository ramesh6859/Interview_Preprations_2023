#include "CurrentDriver.h"
#include "StdTypes.h"

Std_ReturnType initCurrentDriver(void)
{
    ANSELA = STD_LOW;
    ANSELC = STD_LOW;
    SLRCON = STD_LOW;
    CS = STD_HIGH;
    CS_Direction = STD_LOW;
    SPI1_Init();
    return STD_OK;
}

Std_ReturnType setCurrentValue(uint16_t mA)
{
    uint8_t tempBuffer;
    if (mA <= 0x1388U)
    {
        mA = mapCurrentValue(mA);
        CS = STD_LOW;
        tempBuffer = (mA >> 8U) & 0x0FU;
        tempBuffer |= 0x10U;
        SPI1_Write(tempBuffer);
        tempBuffer = mA;
        SPI1_Write(tempBuffer);
        CS = STD_HIGH;
        return STD_OK;
    }
    else
    {
        return STD_NOT_OK;
    }
}

Std_ReturnType setCurrentZero(void)
{
    uint8_t tempBuffer;
    CS = STD_LOW;
    tempBuffer = (0x00U >> 8U) & 0x0FU;
    tempBuffer |= 0x10U;
    SPI1_Write(tempBuffer);
    tempBuffer = 0x00U;
    SPI1_Write(tempBuffer);
    CS = STD_HIGH;
    return STD_OK;
}

uint16_t mapCurrentValue(uint16_t raw_mA)
{
    return ((uint32_t)(raw_mA - inMin) * (uint32_t)(outMax - outMin) + (uint32_t)(inMax - inMin) / 2U) / (uint32_t)(inMax - inMin) + outMin;
}
