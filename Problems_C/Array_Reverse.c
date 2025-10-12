/*
#include <stdio.h>
void reverseWithoutPointers(int arr[], int size) {
    int temp;
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    reverseWithoutPointers(arr, size);

    printf("Reversed array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
*/
#include <stdio.h>
void reverseWithPointers(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    int temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int *p = arr; p < arr + size; p++)
        printf("%d ", *p);
    printf("\n");

    reverseWithPointers(arr, size);

    printf("Reversed array: ");
    for (int *p = arr; p < arr + size; p++)
        printf("%d ", *p);
    printf("\n");

    return 0;
}
