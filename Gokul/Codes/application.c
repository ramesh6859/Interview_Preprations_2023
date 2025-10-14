#include "CurrentDriver.h"
#include "TimeHandler.h"
#include "UartDriver.h"
#include "TaskManager.h"
#include "StdTypes.h"

void main() {
 initUartDriver();
 initCurrentDriver();
 initTimeHandler(ACTIVATE);

 while(1)
 {
 TaskManager();
 }
}