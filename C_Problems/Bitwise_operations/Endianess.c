#include <stdio.h>
int main(void)
{
    system("cls");
    unsigned int value = 0x1;
    char *r = (char *)&value;
    if (*r == 1)
        printf("Your system is Little Endian\n");
    else
        printf("Your system is Big Endian\n");
    return 0;
}