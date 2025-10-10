// #include <stdio.h>
// #define MAX(x, y, z) ((x > y) ? ((x > z) ? (x) : (z)) : ((y > z) ? y : z))
// int main() 
// {
//     system("cls");
//     int num1, num2, num3;
//     printf("Enter the first number num1 : ");
//     scanf("%d", &num1);
//     printf("Enter the second number num2 : ");
//     scanf("%d", &num2);
//     printf("Enter the third number num3 : ");
//     scanf("%d", &num3);
//     int largest = MAX(num1, num2, num3);
//     printf("The largest number is: %d\n", largest);
//     return 0;
// }

//  ############################################################

#include <stdio.h>
int compare(int, int, int);
int main()
{
    system("cls");
    int num1, num2, num3;
    printf("Enter the number1 = ");
    scanf("%d", &num1);
    printf("Enter the number2 = ");
    scanf("%d", &num2);
    printf("Enter the number3 = ");
    scanf("%d", &num3);
    int (*CompareNumbers)(int x, int y, int z);
    CompareNumbers = &compare;
    int result = CompareNumbers(num1, num2, num3);
    printf("Largest Number: %d\n", result);
    return 0;
}
int compare(int x, int y, int z)
{
    if (x > y)
    {
        if (x > z)
            return x;
        else
            return z;
    }
    else if (y > z)
        return y;
    else
        return z;
}