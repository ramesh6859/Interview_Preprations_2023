#include <stdio.h>
int main()
{
    system("cls");
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    int result = 1;
    while (result < num)
        result <<= 1;
    result >>= 1;
    printf("The next lower power of 2 is: %d\n", result);
    return 0;
}
