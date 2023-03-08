#include <stdio.h>
int *decimal_to_binary(int);
int main()
{
    int input_number = 0;
    int *output_array;
    printf("Enter the decimal : ");
    scanf("%d", &input_number);
    printf("The decimal number : %d\n", input_number);
    output_array = decimal_to_binary(input_number);
    printf("The binary number : %d\n");
    for (int j = 0; j < 8; j++)
    {
        printf("%d ", *(output_array));
    }
    return 0;
}
int *decimal_to_binary(int number)
{
    int array[8];
    static int rarr[8];
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        array[8 - i - 1] = number & 1;
        number >>= 1;
    }
    for (i = 0; i < 8; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\niiiiii\n");
    return array;
}