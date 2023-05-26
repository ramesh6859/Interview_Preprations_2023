#include<stdio.h>
float add(int a, int b)
{
    return a + b;
}
float subtract(int a, int b)
{
    return a - b;
}
float multiply(int a, int b)
{
    return a * b;
}
float division(int a, int b)
{
    if(b == 0)
        return 0;
    else 
        return (float)a / b;
}
int main()
{
    int first_no, second_no, result;
    int operation;
    printf("Enter the first number: ");
    scanf("%d", &first_no);
    printf("Enter the second number: ");
    scanf("%d", &second_no);
    printf("Enter the operation: \n\t0 : Addition\n\t1 : Subtraction\n\t2 : Multiplication\n\t3 : Division\n");
    scanf("%d", &operation);
    float (*cal[4])(int, int) = {add, subtract, multiply, division}; 
    printf("Result : %f\n", cal[operation](first_no, second_no));
    return 0;
}