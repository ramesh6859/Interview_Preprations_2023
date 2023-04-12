#include <stdio.h>
int *decimal_to_binary(int number)
{
    static int a[100];
    int i = 0;
    for (i = 0; number > 0; i++)
    {
        a[i] = number % 2;
        number = number / 2;
    }
    printf("Binary of Given Number is: ");

    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return a;
}
void LSB_Check(int number)
{
    if (number & 1)
        printf("LSB of %d is set (1).\n", number);
    else
        printf("LSB of %d is unset (0)\n.", number);
}
void MSB_Check(int number)
{
    int MSB = 1 << ((sizeof(int) * 8) - 1);
    if (number & MSB)
        printf("MSB of %d is set (1).\n", number);
    else
        printf("LSB of %d is unset (0).\n", number);
}
void GET_nth_bit(int number, int bit)
{
    printf("%d th bit of %d is %d\n", bit, number, (number >> bit) & 1);
}
void SET_nth_bit(int number, int bit)
{
    printf("Number before setting %d th bit: %d (in decimal)\n", bit, number);
    printf("Number after setting %d th bit: %d (in decimal)\n", bit, (number | (1 << bit)));
}
void CLEAR_nth_bit(int number, int bit)
{
    printf("Number before clearing %d th bit: %d (in decimal)\n", bit, number);
    printf("Number after clearing %d th bit: %d (in decimal)\n", bit, (number & ~(1 << bit)));
}
void TOGGLE_nth_bit(int number, int bit)
{
    printf("Number before toggling %d th bit: %d (in decimal)\n", bit, number);
    printf("Number after toggling %d th bit: %d (in decimal)\n", bit, (number ^ (1 << bit)));
}
void GET_highest_order_set_bit(int number)
{
    int order = -1;
    int i = 0;
    for (i = 0; i < (sizeof(int) * 8); i++)
    {
        if ((number >> i) & 1)
            order = i;
    }
    if (order != -1)
        printf("Highest order set bit in %d is %d.\n", number, order);
    else
        printf("0 has no set bits. \n");
}
void GET_lowest_order_set_bit(int number)
{
    int INT_SIZE = sizeof(int) * 8;
    int order = INT_SIZE - 1;
    int i = 0;
    for (i = 0; i < INT_SIZE; i++)
    {
        if ((number >> i) & 1)
        {
            order = i;
            break;
        }
    }
    printf("Lowest order set bit in %d is %d", number, order);
}
void count_trailing_zeros(int number)
{
    int count = 0;
    while (!(number & 1))
    {
        count++;
        number >>= 1;
    }
    printf("Total number of trailing zeros = %d.", count);
}
void count_leading_zeros(int number)
{
    int INT_SIZE = sizeof(int) * 8;
    int MSB = 1 << (INT_SIZE - 1);
    int i = 0, count = 0;
    for (i = 0; i < INT_SIZE; i++)
    {
        if ((number << i) & MSB)
        {
            break;
        }
        count++;
    }
    printf("Total number of leading zeros in %d is %d", number, count);
}
void flip_all(int number)
{
    int flippedNumber = 0;
    flippedNumber = ~number;

    printf("Original number = %d (in decimal)\n", number);
    printf("Number after bits are flipped = %d (in decimal)", flippedNumber);
}
void count_zeros_and_ones(int number)
{
    int INT_SIZE = sizeof(int) * 8;
    int zeros = 0, ones = 0, i = 0;
    for (i = 0; i < INT_SIZE; i++)
    {
        if (number & 1)
            ones++;
        else
            zeros++;
        number >>= 1;
    }
    printf("Total zero bit is %d\n", zeros);
    printf("Total one bit is %d", ones);
}
int rotateLeft(int number, int rotation)
{
    int INT_SIZE = (sizeof(int) * 8) - 1;
    int DROPPED_MSB;
    rotation %= INT_SIZE;
    while (rotation--)
    {
        DROPPED_MSB = (number >> INT_SIZE) & 1;
        number = (number << 1) | DROPPED_MSB;
    }
    return number;
}
int rotateRight(int number, int rotation)
{
    int INT_SIZE = (sizeof(int) * 8) - 1;
    int DROPPED_LSB;
    rotation %= INT_SIZE;
    while (rotation--)
    {
        DROPPED_LSB = number & 1;
        number = (number >> 1) & (~(1 << INT_SIZE));
        number = number | (DROPPED_LSB << INT_SIZE);
    }
    return number;
}
void rotate_bits(int number, int rotation)
{
    printf("%d left rotated %d times = %d\n", number, rotation, rotateLeft(number, rotation));
    printf("%d right rotated %d times = %d\n", number, rotation, rotateRight(number, rotation));
}
void swap_two_numbers(int number1, int number2)
{
    printf("Original value of number1 = %d\n", number1);
    printf("Original value of number2 = %d\n", number2);
    number1 ^= number2;
    number2 ^= number1;
    number1 ^= number2;
    printf("Number1 after swapping = %d\n", number1);
    printf("Number2 after swapping = %d\n", number2);
}
void check_even_or_odd(int number)
{
    (number & 1) ? printf("%d is odd.", number) : printf("%d is even.", number);
}
void main()
{
    system("cls");
    int *array, input = 0;
    printf("Enter the Number: ");
    scanf("%d", &input);
    printf("The input number is: %d\n", input);
    array = decimal_to_binary(input);
    // for (int j = 15; j >= 0; j--)
    // {
    //     printf("%d", array[j]);
    // }

    // LSB_Check(input);
    // MSB_Check(input);
    // GET_nth_bit(input, 3);
    // SET_nth_bit(input, 3);
    // CLEAR_nth_bit(input, 1);
    // TOGGLE_nth_bit(input, 1);
    // GET_highest_order_set_bit(input);
    // GET_lowest_order_set_bit(input);
    // count_trailing_zeros(input);
    // count_leading_zeros(input);
    // flip_all(input);
    // count_zeros_and_ones(input);
    // rotate_bits(input, 2);
    // swap_two_numbers(input, 10);
    check_even_or_odd(input);
    printf("\n");
}
