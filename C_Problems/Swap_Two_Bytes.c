#include <stdio.h>
int Swap_bytes(int);
int main()
{
    system("cls");
    int input_number = 0;
    printf("Enter 4 bytes value in Hexadecimal: ");
    scanf("%x", &input_number);
    printf("Number before swapping : %X\n", input_number);
    printf("Number after swapping  : %X\n", Swap_bytes(input_number));
    return 0;
}
int Swap_bytes(int number)
{
    return ((number << 8) & 0xff00) | ((number >> 8) & 0x00ff);
}
