/*
#include <stdio.h>
void removeDuplicates(int [], int *);
int main()
{
    system("cls");
    int arr[] = {1, 2, 3, 4, 2, 3, 5, 6, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array before removing duplicates: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    removeDuplicates(arr, &size);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
void removeDuplicates(int arr[], int *size)
{
    int i, j, k;
    for (i = 0; i < *size; i++) 
    {
        for (j = i + 1; j < *size;) 
        {
            if (arr[j] == arr[i]) 
            {
                for (k = j; k < *size - 1; k++) 
                    arr[k] = arr[k + 1];
                (*size)--;
            }
            else
                j++;
        }
    }
}
*/

#include <stdio.h>
#include <stdlib.h>

void removeDuplicates(int *arr, int *size) {
    int *i, *j, *k;
    for (i = arr; i < arr + *size; i++) {
        for (j = i + 1; j < arr + *size;) {
            if (*j == *i) {
                for (k = j; k < arr + *size - 1; k++)
                    *k = *(k + 1);
                (*size)--;
            }
            else
                j++;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 2, 3, 5, 6, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before removing duplicates: ");
    for (int *p = arr; p < arr + size; p++)
        printf("%d ", *p);
    printf("\n");

    removeDuplicates(arr, &size);

    printf("Array after removing duplicates: ");
    for (int *p = arr; p < arr + size; p++)
        printf("%d ", *p);
    printf("\n");

    return 0;
}
