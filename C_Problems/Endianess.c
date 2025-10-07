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

//  ############################################################

// #include <stdio.h>
// #include <inttypes.h>
// union RawData
// {
//     int RawInt;
//     char RawChar[4];
// };
// int main(void)
// {
//     system("cls");
//     union RawData raw;
//     raw.RawInt = 0x11223344;
//     if (raw.RawChar[0] == 0x44)
//         printf("Little-Endian");
//     else if (raw.RawChar[0] == 0x11)
//         printf("Big-Endian");
//     return 0;
// }
