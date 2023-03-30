#include <stdio.h>
int main(void)
{
    system("cls");
    int number1, number2, sum, difference;
    printf("Enter the first integer: ");
    scanf("%d", &number1);
    printf("Enter the second integer: ");
    scanf("%d", &number2);
    sum = number1 + number2;
    difference = number1 - number2;
    printf("\nThe sum equals %d, and the difference equals %d.\n", sum, difference);
    return 0;
}