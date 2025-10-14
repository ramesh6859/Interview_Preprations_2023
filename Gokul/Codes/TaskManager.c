#include "ProfileHandler.h"
#include "UartDriver.h"
#include "CurrentDriver.h"
#include "TimeHandler.h"
#include "DwinCommandHandler.h"
#include "CommonBuffer.h"
#include "CommandHelper.h"
#include "StdTypes.h"
#include "TaskManager.h"

Std_ReturnType getStringFromReceived(uint8_t *rawBuffer, uint8_t maxBufferSize, uint8_t commandType) 
{
    Std_ReturnType retVal = STD_NOT_OK;
    uint8_t dataLength = 0x00U;
    uint8_t _it = 0x00U;
    uint8_t __it = 0x00U;
    memset(rawBuffer, 0, sizeof(rawBuffer));
    executeDWINCommand(commandType);
    dataLength = getDataLen(receivedString);
    if (dataLength != 0x00U)
    {
        retVal = STD_OK;
        for(_it = VALID_DATA_INDEX,__it; _it <  dataLength && __it < dataLength; _it++,__it++)
         {
            if( receivedString[_it] != 0xFFU)
            {
               rawBuffer[__it] = receivedString[_it];
            }
         }
        
    }
    flushRxBuffer();
    return retVal;
}

Std_ReturnType loginUser(char* expectedName,char* expectedPassword)
{
    char name[MAX_NAME_SIZE];
    char password[MAX_PASSWORD_SIZE];

    memset(name, 0, sizeof(name));
    memset(password, 0, sizeof(password));
    if (getStringFromReceived((char*)name, MAX_NAME_SIZE, GET_USER_NAME) == STD_OK &&
        getStringFromReceived((char*)password, MAX_PASSWORD_SIZE, GET_USER_PASSWORD) == STD_OK)
        {
        if (strcmp(name,expectedName) == 0 && strcmp(password,expectedPassword) == 0)
        {
            Admin = (strcmp(expectedName, "admin") == 0) ? STD_ACTIVE : STD_IDLE;
            return STD_OK;
        }
    }

    return STD_NOT_OK;
}
Std_ReturnType TaskManager(void) 
{
    Std_ReturnType retVal = STD_NOT_OK;
    uint8_t checkIndex = 0;
    uint8_t commandType = 0;
    uint8_t i;
    memset(receivedString, 0, sizeof(receivedString));
    for (;;) 
    {
        getDataLen(receivedString);
        checkIndex = receivedString[CHECK_INDEX];
        if (checkIndex == LOGIN_CHECK)
           {
                if (loginUser("admin", "3428") == STD_OK) 
                {
                    executeDWINCommand(GOTO_ADMIN_PAGE);
                    memset(receivedString, 0, sizeof(receivedString));
                    retVal = STD_OK;
                } 
                else if (loginUser("user", "1234") == STD_OK) 
                {
                    executeDWINCommand(GOTO_USER_PAGE);
                    memset(receivedString, 0, sizeof(receivedString));
                    retVal = STD_OK;
                } 
                else 
                {
                    executeDWINCommand(LOGIN_ERROR_MESSAGE);
                    executeDWINCommand(ERROR_MESSAGE_COLOR_RED);
                    memset(receivedString, 0, sizeof(receivedString));
                }
            }
        else if (checkIndex == POWER_RECYCLE_T5L)
            {
                executeDWINCommand(POWER_RECYCLE);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[0].checkIndex)
            {
                runProfile(checkIndexToCommandMap[0].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[1].checkIndex)
            {
                runProfile(checkIndexToCommandMap[1].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex ==checkIndexToCommandMap[2].checkIndex)
            {
                runProfile(checkIndexToCommandMap[2].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[3].checkIndex)
            {
               runProfile(checkIndexToCommandMap[3].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[4].checkIndex)
            {
                runProfile(checkIndexToCommandMap[4].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[5].checkIndex)
            {
                runProfile(checkIndexToCommandMap[5].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[6].checkIndex)
            {
                runProfile(checkIndexToCommandMap[6].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[7].checkIndex)
            {
                runProfile(checkIndexToCommandMap[7].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex ==checkIndexToCommandMap[8].checkIndex)
            {
                runProfile(checkIndexToCommandMap[8].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[9].checkIndex)
            {
               runProfile(checkIndexToCommandMap[9].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[10].checkIndex)
            {
                runProfile(checkIndexToCommandMap[10].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[11].checkIndex)
            {
                runProfile(checkIndexToCommandMap[11].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[12].checkIndex)
            {
                runProfile(checkIndexToCommandMap[12].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[13].checkIndex)
            {
                runProfile(checkIndexToCommandMap[13].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex ==checkIndexToCommandMap[14].checkIndex)
            {
                runProfile(checkIndexToCommandMap[14].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[15].checkIndex)
            {
               runProfile(checkIndexToCommandMap[15].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[16].checkIndex)
            {
                runProfile(checkIndexToCommandMap[16].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[17].checkIndex)
            {
                runProfile(checkIndexToCommandMap[17].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[18].checkIndex)
            {
                runProfile(checkIndexToCommandMap[18].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else if (checkIndex == checkIndexToCommandMap[19].checkIndex)
            {
                runProfile(checkIndexToCommandMap[19].commandType);
                memset(receivedString, 0, sizeof(receivedString));
                retVal = STD_OK;
            }
        else
            {
             ; //Do Nothing !!!
            }
        if (STD_NOT_OK != retVal)
            {
               memset(receivedString,0,sizeof(receivedString));
               break;
            }
        }
         return STD_OK;
    }