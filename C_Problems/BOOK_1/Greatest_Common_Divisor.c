#include <stdio.h>
int main(void)
{
    system("cls");
    int number1, number2, result, first, second;
    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);
    if (number1 > number2)
    {
        first = number1;
        second = number2;
    }
    else if (number2 > number1)
    {
        first = number2;
        second = number1;
    }
    else
        result = number1;

    result = first;
    while (result != 0)
    {
        result = second % first;
        second = first;
        first = result;
    }
    printf("gcd(%ld, %ld) = %ld \n", number1, number2, second);
    return 0;
}