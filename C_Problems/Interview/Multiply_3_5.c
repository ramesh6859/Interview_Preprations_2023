#include <stdio.h>
#define bits 8
void main()
{
    system("cls");
    int input_number = 0, scaled_input = 0, result = 0;
    float decimal_result = 0;
    printf("Enter the decimal number: ");
    scanf("%d", &input_number);
    scaled_input = input_number << bits;
    result = (scaled_input * 2) + scaled_input + (scaled_input / 2);
    decimal_result = (float)result / (1 << bits);
    printf("Result: %f\n", decimal_result);
}