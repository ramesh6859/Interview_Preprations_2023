/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int *ptr, limit, i, sum;
    printf("Enter limit of the array: ");
    scanf("%d", &limit);
    ptr = (int*)malloc(limit * sizeof(int));
    // ptr = (int*) calloc(n, sizeof(int));
    
    for (i = 0; i < limit; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", (ptr + i));
    }
    
    printf("\nEntered array elements are: ");
    for (i = 0; i < limit; i++)
        printf("%d ", *(ptr + i));
    
    sum = 0;
    for (i = 0; i < limit; i++)
        sum += *(ptr + i);

    printf("\nSum of array elements is: %d", sum);
    free(ptr);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
int main() {
    // Write C code here
    int first = 20, second = 10, result;
    int *addition = (int *)malloc(1*sizeof(int));
    int *subtraction = (int *)malloc(1*sizeof(int));
    int *multiplication = (int *)calloc(1, sizeof(int));
    int *division = (int *)calloc(1,sizeof(int));

    if(!addition || !subtraction || !multiplication || !division) {
        printf("Memory allocation failed\n");
    }
    
    *addition = first + second;
    *subtraction = first - second;
    *multiplication = first * second;
    if(!second)
        printf("Division with 0 is not possible");
    else
        *division = first / second;
    
    printf("Addition (malloc): %d", *addition);
    printf("Subtraction (malloc): %d", *subtraction);
    printf("Multiplication (calloc): %d", *multiplication);
    printf("Division (calloc): %d", *division);

    
    return 0;
}
