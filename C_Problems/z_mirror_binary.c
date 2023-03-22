#include <stdio.h>
int main()
{
    system("cls");
    int decimal, mirrored_decimal = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    int num_bits = sizeof(decimal) * 8;
    for (int i = 0; i < num_bits; i++)
    {
        if (decimal & (1 << i))
        {
            mirrored_decimal |= 1 << (num_bits - 1 - i);
        }
    }
    printf("The mirrored binary representation of the decimal number is: %d\n", mirrored_decimal);
    return 0;
}
