#include <stdio.h>
int Swap_bits(int, int, int);
int main()
{
    system("cls");
    int input_number = 0, bit1 = 0, bit2 = 0;
    printf("Enter the input decimal number : ");
    scanf("%d", &input_number);
    printf("Enter the two bits to be swapped : ");
    scanf("%d %d", &bit1, &bit2);
    printf("After swapping the bits, data value is: %d\n", Swap_bits(input_number, bit1, bit2));
    return 0;
}
int Swap_bits(int number, int first_bit, int second_bit)
{
    int maskedbit1 = 0, maskedbit2 = 0, xor_of_bit = 0, output_number = 0;
    maskedbit1 = (number >> first_bit) & 1;
    maskedbit2 = (number >> second_bit) & 1;
    xor_of_bit = maskedbit1 ^ maskedbit2;
    output_number = number ^ (xor_of_bit << first_bit | xor_of_bit << second_bit);
    return output_number;
}