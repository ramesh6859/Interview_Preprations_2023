#include <stdio.h>
#define IntSize sizeof(int) * 8
int Reverse_bits(int);
int main()
{
    system("cls");
    int input_number = 0;
    printf("Enter the input decimal number : ");
    scanf("%d", &input_number);
    printf("The number after reversing its bits is: %d\n", Reverse_bits(input_number));
    return 0;
}
int Reverse_bits(int number)
{
    int output_number = 0;
    for (int i = 0; i < 8; i++)
    {
        output_number <<= 1;           // Left shift by 1 bit
        output_number |= (number & 1); // Add the rightmost bit to the reversed number
        number >>= 1;                  // Right shift by 1 bit
    }
    return output_number;
}
