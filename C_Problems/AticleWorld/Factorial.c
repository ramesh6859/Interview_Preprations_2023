// #include <stdio.h>
// #define FACTORIAL(n) \
//     ({ \
//         int fact = 1; \
//         for (int i = 1; i <= (n); ++i) \
//             fact *= i; \
//         fact; \
//     })

// int main() {
//     int num;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     int result = FACTORIAL(num);
//     printf("The factorial of %d is: %d\n", num, result);
//     return 0;
// }

// #include <stdio.h>
// int FACTORIAL(int n)
// {
//     int fact = 1;
//     for (int i = 1; i <= (n); ++i)
//         fact *= i;
//     return fact;
// }

// int main() {
//     int num;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     int (*fact)(int);
//     fact = FACTORIAL;
//     int result = fact(num);
//     printf("The factorial of %d is: %d\n", num, result);
//     return 0;
// }

#include <stdio.h>
long factorial(int n) 
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    long result = factorial(num);
    printf("The factorial of %d is: %llu\n", num, result);
    return 0;
}

