#include <stdio.h>
void passbyvalue(int first, int second)
{
    first = first + second;  // a=30 (10+20)
    second = first - second; // b=10 (30-20)
    first = first - second;  // a=20 (30-10)
    printf("After swap passbyvalue a = %d b = %d\n", first, second);
}
void passbyreference(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
    printf("After swap passbyreference a = %d b = %d\n", *x, *y);
}
int main()
{
    int a, b;
    printf("Enter the first number : ");
    scanf("%d", &a);
    printf("Enter the second number : ");
    scanf("%d", &b);
    passbyvalue(a, b);
    printf("Original Value after calling passbyvalue of a = %d b = %d\n", a, b);
    passbyreference(&a, &b);
    printf("Original Value after calling passbyreference of a = %d b = %d\n", a, b);
    return 0;
}