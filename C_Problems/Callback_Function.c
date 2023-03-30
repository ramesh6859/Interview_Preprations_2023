#include <stdio.h>
int sum(int, int);
int subtract(int, int);
int display(int (*ptr)(int, int), int, int);
int main()
{
    system("cls");
    int first_no, second_no, add, minus;
    printf("Enter the first number: ");
    scanf("%d", &first_no);
    printf("Enter the second number: ");
    scanf("%d", &second_no);
    add = display(sum, first_no, second_no);
    minus = display(subtract, first_no, second_no);
    printf("Addition: %d\n", add);
    printf("Subtraction: %d\n", minus);
}
int sum(int first, int second)
{
    return first + second;
}
int subtract(int first, int second)
{
    return first - second;
}
int display(int (*ptr)(int, int), int a, int b)
{
    return ptr(a, b);
}