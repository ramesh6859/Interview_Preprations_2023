#include <stdio.h>
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);
void operation(void (*ptr)(char));
int main()
{
    system("cls");
    int operation;
    int first_no, second_no, result;
    int (*ptr[10])(int, int) = {add, subtract, multiply, divide};
    printf("Enter the first number: ");
    scanf("%d", &first_no);
    printf("Enter the second number: ");
    scanf("%d", &second_no);
    printf("Enter the operation: \n\t0 : Addition\n\t1 : Subtraction\n\t2 : Multiplication\n\t3 : Division\n");
    scanf("%d", &operation);
    result = (*ptr[operation])(first_no, second_no);
    printf("Result = %d \n", result);
}

int add(int first, int second)
{
    return first + second;
}
int subtract(int first, int second)
{
    return first - second;
}
int multiply(int first, int second)
{
    return first * second;
}
int divide(int first, int second)
{
    if (second != 0)
        return first / second;
    else
        printf("Division by zero is not possible \n");
}
