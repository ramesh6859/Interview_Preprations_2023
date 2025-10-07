#include <stdio.h>
int is_alternating_pattern(int);
int main()
{
    system("cls");
    int input_number;
    printf("Enter decimal number: ");
    scanf("%d", &input_number);
    if (is_alternating_pattern(input_number))
        printf("The number contains an alternating pattern of bits.\n");
    else
        printf("The number does not contain an alternating pattern of bits.\n");
    return 0;
}
int is_alternating_pattern(int number)
{
    int prev_bit = number & 1;
    number >>= 1;
    while (number != 0)
    {
        int curr_bit = number & 1;
        if (curr_bit == prev_bit)
            return 0;
        prev_bit = curr_bit;
        number >>= 1;
    }
    return 1;
}