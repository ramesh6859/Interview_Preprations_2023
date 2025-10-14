#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "StdTypes.h"
#include "CommandHelper.h"

#define LOGIN_CHECK 0x7FU
#define POWER_RECYCLE_T5L 0x99U

#define STEP_READ_1 0x10U
#define STEP_READ_2 0x20U
#define STEP_READ_3 0x30U
#define STEP_READ_4 0x40U
#define STEP_READ_5 0x50U
#define STEP_READ_6 0x70U
#define STEP_READ_7 0x80U
#define STEP_READ_8 0x90U
#define STEP_READ_9 0xA0U
#define STEP_READ_10 0xB0U
#define STEP_READ_11 0xC0U
#define STEP_READ_12 0xD0U
#define STEP_READ_13 0xE0U
#define STEP_READ_14 0xF0U
#define STEP_READ_15 0x11U
#define STEP_READ_16 0x12U
#define STEP_READ_17 0x13U
#define STEP_READ_18 0x14U
#define STEP_READ_19 0x15U
#define STEP_READ_20 0x16U

#define CHECK_INDEX 0x08U
#define MAX_NAME_SIZE  10
#define MAX_PASSWORD_SIZE  10
#define MAX_RECEIVED_STRING_SIZE  47

typedef struct {
    uint8_t checkIndex;
    uint8_t commandType;
} CheckIndexToCommandType;

static const CheckIndexToCommandType checkIndexToCommandMap[] = {
    {STEP_READ_1, GET_PROFILE_1},
    {STEP_READ_2, GET_PROFILE_2},
    {STEP_READ_3, GET_PROFILE_3},
    {STEP_READ_4, GET_PROFILE_4},
    {STEP_READ_5, GET_PROFILE_5},
    {STEP_READ_6, GET_PROFILE_6},
    {STEP_READ_7, GET_PROFILE_7},
    {STEP_READ_8, GET_PROFILE_8},
    {STEP_READ_9, GET_PROFILE_9},
    {STEP_READ_10, GET_PROFILE_10},
    {STEP_READ_11, GET_PROFILE_11},
    {STEP_READ_12, GET_PROFILE_12},
    {STEP_READ_13, GET_PROFILE_13},
    {STEP_READ_14, GET_PROFILE_14},
    {STEP_READ_15, GET_PROFILE_15},
    {STEP_READ_16, GET_PROFILE_16},
    {STEP_READ_17, GET_PROFILE_17},
    {STEP_READ_18, GET_PROFILE_18},
    {STEP_READ_19, GET_PROFILE_19},
    {STEP_READ_20, GET_PROFILE_20}
};
Std_ReturnType TaskManager(void);
Std_ReturnType loginUser(char* expectedName,char* expectedPassword);
Std_ReturnType getStringFromReceived(uint8_t *rawBuffer, uint8_t maxBufferSize, uint8_t commandType);

#endif