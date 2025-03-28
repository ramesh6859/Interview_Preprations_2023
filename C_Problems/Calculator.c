//////// Normal Function
// #include<stdio.h>
// #define add(x, y) (x + y)
// #define subtract(x, y) (x - y)
// #define multiply(x, y) (x * y)
// #define division(x, y) (y != 0 ? ((float)x / (float)y) : 0)
// int main()
// {
//     system("cls");
//     int first_no, second_no, result;
//     int operation;
//     printf("Enter the first number: ");
//     scanf("%d", &first_no);
//     printf("Enter the second number: ");
//     scanf("%d", &second_no);
//     printf("Enter the operation: \n\t0 : Addition\n\t1 : Subtraction\n\t2 : Multiplication\n\t3 : Division\n");
//     scanf("%d", &operation);
//     switch(operation)
//     {
//         case 0:
//             result = add(first_no, second_no);
//             printf("Result : %d\n", result);
//             break;
//         case 1:
//             result = subtract(first_no, second_no);
//             printf("Result : %d\n", result);
//             break;
//         case 2:
//             result = multiply(first_no, second_no);
//             printf("Result : %d\n", result);
//             break;
//         case 3:
//             printf("Result : %f\n", division(first_no, second_no));
//             break;
//         default:
//             printf("Invalid choice. Please enter a number between 0 and 3");
//             break;
//     }
//     return 0;
// }

//  ############################################################

//////// Function Pointer
// #include<stdio.h>
// float add(int, int);
// float subtract(int, int);
// float multiply(int, int);
// float division(int, int);
// int main()
// {
//     system("cls");
//     int first_no, second_no, result;
//     int operation;
//     printf("Enter the first number: ");
//     scanf("%d", &first_no);
//     printf("Enter the second number: ");
//     scanf("%d", &second_no);
//     printf("Enter the operation: \n\t0 : Addition\n\t1 : Subtraction\n\t2 : Multiplication\n\t3 : Division\n");
//     scanf("%d", &operation);
//     float (*cal[4])(int, int) = {add, subtract, multiply, division}; 
//     printf("Result : %f\n", cal[operation](first_no, second_no));
//     return 0;
// }
// float add(int a, int b)
// {
//     return a + b;
// }
// float subtract(int a, int b)
// {
//     return a - b;
// }
// float multiply(int a, int b)
// {
//     return a * b;
// }
// float division(int a, int b)
// {
//     if(b == 0)
//         return 0;
//     else 
//         return (float)a / b;
// }

//  ############################################################

//////// Float to Pointer Function
#include <stdio.h>
#include <stdlib.h>

int* add(int*, int*);
int* subtract(int*, int*);
int* multiply(int*, int*);
float* division(int*, int*);

int main()
{
    system("cls");
    int first_no, second_no, operation;
    printf("Enter the first number: ");
    scanf("%d", &first_no);
    printf("Enter the second number: ");
    scanf("%d", &second_no);
    printf("Enter the operation: \n\t0 : Addition\n\t1 : Subtraction\n\t2 : Multiplication\n\t3 : Division\n");
    scanf("%d", &operation);

    int* (*cal[4])(int*, int*) = {add, subtract, multiply, (int* (*)(int*, int*))division};
    int* result = cal[operation](&first_no, &second_no);

    if (operation == 3) {
        float* float_result = (float*)result;
        printf("The result is: %f\n", *float_result);
        free(float_result);
    } else {
        printf("The result is: %d\n", *result);
        free(result);
    }

    return 0;
}

int* add(int* a, int* b)
{
    int* r = (int*)malloc(sizeof(int));
    *r = *a + *b;
    return r;
}

int* subtract(int* a, int* b)
{
    int* r = (int*)malloc(sizeof(int));
    *r = *a - *b;
    return r;
}

int* multiply(int* a, int* b)
{
    int* r = (int*)malloc(sizeof(int));
    *r = *a * *b;
    return r;
}

float* division(int* a, int* b)
{
    float* r = (float*)malloc(sizeof(float));
    *r = (float)*a / (float)*b;
    return r;
}