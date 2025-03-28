#include <stdio.h>
void printFibonacci(int);
int main()
{
    system("cls");
    int input_number = 0;
    printf("Enter the number : ");
    scanf("%d", &input_number);
    printFibonacci(input_number);
    return 0;
}
void printFibonacci(int n)
{
    int fib[n];
    int *ptr = fib;
    *ptr = 0;
    *(ptr + 1) = 1;
    printf("Fibonacci Series: %d %d ", *ptr, *(ptr + 1));
    for (int i = 2; i < n; i++) 
    {
        *(ptr + i) = *(ptr + i - 1) + *(ptr + i - 2);
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}
