#include<stdio.h>
#define addTwoNumber(x, y) x + y
int main()
{
    int num1, num2, sum;
    printf("Enter the first number num1 : \n");
    scanf("%d", &num1);
    printf("Enter the second number num2 : \n");
    scanf("%d", &num2);
    sum = addTwoNumber(num1,num2);
    printf("Addition of num1 and num2 is: %d", sum);
    return 0;
}

// #include <stdio.h>
// int add(int a, int b)
// {
//     return a + b;
// }
// int main()
// {
//     int num1, num2, result;
//     printf("Enter the first number num1 : \n");
//     scanf("%d", &num1);
//     printf("Enter the second number num2 : \n");
//     scanf("%d", &num2);
//     int (*addPtr)(int, int);
//     addPtr = &add;
//     result = addPtr(num1, num2);
//     printf("The sum is: %d\n", result);
//     return 0;
// }