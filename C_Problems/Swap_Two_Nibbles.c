#include <stdio.h>
int Swap_nibbles(int);
int main()
{
    system("cls");
    int input_number = 0;
    printf("Enter 2 bytes value in Hexadecimal: ");
    scanf("%x", &input_number);
    printf("Number before swapping : %X\n", input_number);
    printf("Number after swapping  : %X\n", Swap_nibbles(input_number));
    return 0;
}
int Swap_nibbles(int number)
{
    return ((number << 4) & 0xf0) | ((number >> 4) & 0x0f);
}
