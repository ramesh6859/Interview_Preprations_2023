#include <stdio.h>
int compare(int, int);
int main() 
{
    int num1, num2;
    printf("Enter the first number num1 : ");
    scanf("%d", &num1);
    printf("Enter the second number num2 : ");
    scanf("%d", &num2);

    int (*comparePtr)(int, int);
    comparePtr = &compare;
    int result = comparePtr(num1, num2);

    if (result == 0)
        printf("Both numbers are equal.\n");
    else
        printf("%d is the largest.\n", result);

    return 0;
}

int compare(int a, int b)
{
    if (a > b)
        return a;
    else if (a < b)
        return b;
    else
        return 0;
}
