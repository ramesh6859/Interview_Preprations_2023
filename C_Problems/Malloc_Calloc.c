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
