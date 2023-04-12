#include <stdio.h>
int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);
int main()
{
    system("cls");
    int x, y, choice, result;
    int (*op[4])(int, int);
    op[0] = add;
    op[1] = subtract;
    op[2] = multiply;
    op[3] = divide;
    printf("Enter First integer: ");
    scanf("%d", &x);
    printf("Enter Second integer: ");
    scanf("%d", &y);
    printf("Please enter the option: \n");
    printf("\t0 :::: Add\n\t1 :::: Subtract\n\t2 :::: Multiply\n\t3 :::: Divide\n");
    scanf("%d", &choice);
    result = op[choice](x, y);
    printf("The result is %d", result);
    return 0;
}
int add(int x, int y)
{
    return (x + y);
}
int subtract(int x, int y)
{
    return (x - y);
}
int multiply(int x, int y)
{
    return (x * y);
}
int divide(int x, int y)
{
    if (y != 0)
        return (x / y);
    else
        return 0;
}