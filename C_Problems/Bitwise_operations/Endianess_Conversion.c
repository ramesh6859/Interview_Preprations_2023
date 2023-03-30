#include <stdio.h>
int main(void)
{
    system("cls");
    int value = 0x11223344;
    int converted = 0;
    printf("Value Before Converting = 0x%x\n", value);
    converted |= ((0xff & value) << 24);
    converted |= (((0xff << 8) & value) << 8);
    converted |= (((0xff << 16) & value) >> 8);
    converted |= (((0xff << 24) & value) >> 24);
    printf("Value After Converting = 0x%x\n", converted);
    return 0;
}