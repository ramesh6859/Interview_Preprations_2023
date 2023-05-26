// #include <stdio.h>
// int main(void)
// {
//     system("cls");
//     unsigned int value = 0x1;
//     char *r = (char *)&value;
//     if (*r == 1)
//         printf("Your system is Little Endian\n");
//     else
//         printf("Your system is Big Endian\n");
//     return 0;
// }

#include <stdio.h>
union
{
    int u32RawData;
    char au8DataBuff[4];
} RawData;

int main()
{
    RawData uCheckEndianess;
    uCheckEndianess.u32RawData = 0x11223344;
    if (uCheckEndianess.au8DataBuff[0] == 0x44)
        printf("little-endian");
    else if (uCheckEndianess.au8DataBuff[0] == 0x11)
        printf("big-endian");
    return 0;
}
