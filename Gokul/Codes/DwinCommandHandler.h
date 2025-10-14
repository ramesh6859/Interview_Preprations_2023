#ifndef DWINCOMMANDHANDLER_H
#define DWINCOMMANDHANDLER_H

#include "StdTypes.h"

#define COMMAND_LENGTH_7   0x07U
#define COMMAND_LENGTH_8   0x08U
#define COMMAND_LENGTH_10  0x0AU
#define COMMAND_LENGTH_13  0x0DU
#define COMMAND_LENGTH_15  0x0FU
#define COMMAND_LENGTH_16  0x10U
#define COMMAND_LENGTH_54  0x36U

void sendCommand(uint16_t command, uint8_t length);

Std_ReturnType executeDWINCommand(uint16_t command);

#endif