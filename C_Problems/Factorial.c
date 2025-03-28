//////// Normal Function
// #include <stdio.h>
// #define Factorial(n) ({ int fact = 1; \
//                         for (int i = 1; i <= (n); ++i) \
//                             fact *= i; \
//                         fact; \
//                     })

// int main()
// {
//     system("cls");
//     int num;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     int result = Factorial(num);
//     printf("The factorial of %d is: %d\n", num, result);
//     return 0;
// }

//  ############################################################

//////// Function Pointer
// #include <stdio.h>
// int factorial(int);
// int main() 
// {
//     system("cls");
//     int num, result;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     int (*fact)(int);
//     fact = factorial;
//     result = fact(num);
//     printf("The factorial of %d is: %d\n", num, result);
//     return 0;
// }
// int factorial(int n)
// {
//     int fact = 1;
//     for (int i = 1; i <= (n); ++i)
//         fact *= i;
//     return fact;
// }

//  ############################################################

//////// Integer to Pointer Function
// #include <stdio.h>
// #include <stdlib.h>
// int* factorial(int*);
// int main() 
// {
//     system("cls");
//     int num, *result;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     int* (*fact)(int*);
//     fact = factorial;
//     result = fact(&num);
//     printf("The factorial of %d is: %d\n", num, *result);
//     free(result); 
//     return 0;
// }
// int* factorial(int* n)
// {
//     int *fact = (int*)malloc(sizeof(int));
//     *fact = 1;
//     for (int i = 1; i <= *n; ++i)
//         *fact *= i;
//     return fact;
// }

//  ############################################################

//////// Using Recursion
#include <stdio.h>
int factorial(int*);
int main() 
{
    system("cls");
    int num = 0, result = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    result = factorial(&num);
    printf("The factorial of %d is: %d\n", num, result);
    return 0;
}

int factorial(int* n)
{
    if (*n == 0 || *n == 1)
        return 1;
    else
    {
        int temp;
        temp = *n - 1;
        return *n * factorial(&temp);
    }
}
