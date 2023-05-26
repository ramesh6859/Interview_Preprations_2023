#include <stdio.h>
#define MAX(x, y) (x > y ? x : y)
int main()
{
    int num1, num2;    
    printf("Enter the first number num1 : \n");
    scanf("%d", &num1);
    printf("Enter the second number num2 : \n");
    scanf("%d", &num2);
    int largest = MAX(num1, num2);
    printf("The largest number is: %d\n", largest);
    return 0;
}


// #include <stdio.h>
// int compare(int a, int b)
// {
//     if (a > b)
//         return a;
//     else if (a < b)
//         return b;
//     else
//         return 0;
// }
// int main() {
//     int num1, num2;
//     printf("Enter the first number num1 : \n");
//     scanf("%d", &num1);
//     printf("Enter the second number num2 : \n");
//     scanf("%d", &num2);
//     int (*comparePtr)(int, int);
//     comparePtr = &compare;
//     int result = comparePtr(num1, num2);
//     printf("%d is the largest.\n", result);
//     return 0;
// }
