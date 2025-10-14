#include "DwinCommandHandler.h"
#include "CommandDB.h"
#include "StdTypes.h"
Std_ReturnType executeDWINCommand(uint16_t command)
{
    if (command >= 0x00U && command <= 0x93U)
    {
        sendCommand(command, COMMAND_LENGTH_7);
    }
    else if (command >= 0x9AU && command <= 0x18AU)
    {
        sendCommand(command, COMMAND_LENGTH_8);
    }
    else if (command >= 0x192U && command <= 0x1F6U)
    {
        sendCommand(command, COMMAND_LENGTH_10);
    }
    else if (command >= 0x200U && command <= 0x2F7U)
    {
        sendCommand(command, COMMAND_LENGTH_13);
    }
    else if (command >= 0x304U && command <= 0x38BU)
    {
        sendCommand(command, COMMAND_LENGTH_15);
    }
    else if (command >= 0x39AU && command <= 0x42AU)
    {
        sendCommand(command, COMMAND_LENGTH_16);
    }
    else
    {
        sendCommand(command, COMMAND_LENGTH_54);
    }
    return STD_OK;
}

void sendCommand(uint16_t command, uint8_t length)
{
    uint8_t j;
    for (j = 0x00U; j < length; j++)
    {
        UART1_Write(CommandDB[command + j]);
    }
}