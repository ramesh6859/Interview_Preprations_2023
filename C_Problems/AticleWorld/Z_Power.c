#include <stdio.h>
int power(int, int);
int main()
{
    system("cls");
    int base, exponent, result;
    printf("Enter the base : ");
    scanf("%d", &base);
    printf("Enter the exponent : ");
    scanf("%d", &exponent);
    result = power(base, exponent);
    printf("%d raised to the power of %d is: %d\n", base, exponent, result);
    return 0;
}
int power(int base, int exponent)
{
    int result = 1;
    while (exponent > 0)
    {
        result *= base;
        exponent--;
    }
    return result;
}
