#include <stdio.h>
double power(int base, int exponent)
{
    double result = 1.0;
    int i;
    if (exponent > 0)
    {
        for (i = 1; i <= exponent; i++)
            result *= base;
    }
    else if (exponent < 0)
    {
        for (i = 1; i <= -exponent; i++) 
            result /= base;
    }    
    return result;
}

int main() 
{
    double base;
    int exponent;
    printf("Enter the base: ");
    scanf("%lf", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    double result = power(base, exponent);
    printf("Result: %.2f\n", result);
    return 0;
}

