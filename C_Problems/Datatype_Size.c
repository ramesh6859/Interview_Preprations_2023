#include <stdio.h>
int main( void )
{
    system("cls");
    int intValue = 8;
    int* intPtr1 = &intValue;
    int* intPtr2 = intPtr1 + 1;
    
    printf("%d", (char*)intPtr2 - (char*)intPtr1);
    return 0;
}