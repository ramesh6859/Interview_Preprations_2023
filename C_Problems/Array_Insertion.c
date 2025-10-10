#include <stdio.h>
void insertElement(int [], int *, int, int);
int main()
{
    system("cls");
    int array[] = {1, 2, 3, 4, 5};
    int size = 0, position = 0, element = 0;
    size = sizeof(array) / sizeof(array[0]);
    printf("Enter the position : ");
    scanf("%d", &position);
    printf("Enter the element : ");
    scanf("%d", &element);
    printf("Initial array: ");
    for (int i = 0; i < size; i++) 
         printf("%d ", array[i]);
    printf("\n");
    insertElement(array, &size, position, element);
    return 0;
}
void insertElement(int array[], int *size, int position, int element)
{
    if (position < 0 || position > *size)
    {
        printf("Invalid position to insert element.\n");
        return;
    }
    for (int i = *size; i > position; i--) 
        array[i] = array[i - 1];
    array[position] = element;
    (*size)++;
    printf("Element %d inserted successfully at position %d.\n", element, position);
    printf("Updated array: ");
    for (int i = 0; i < *size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/*
#include <stdio.h>
#include <stdlib.h>
void insertElement(int *array, int *size, int position, int element) {
    if (position < 0 || position > *size) {
        printf("Invalid position to insert element.\n");
        return;
    }
    int *ptr = array + *size;
    int *shift_ptr = array + position;
    for (; ptr > shift_ptr; ptr--)
        *ptr = *(ptr - 1);
    *shift_ptr = element; // Insert new element
    (*size)++;

    printf("Element %d inserted successfully at position %d.\n", element, position);
    printf("Updated array: ");
    for (int *p = array; p < array + *size; p++)
        printf("%d ", *p);
    printf("\n");
}

int main()
{
    int array[10] = {1, 2, 3, 4, 5};
    int size = 5, position = 0, element = 0;
    printf("Enter the position: ");
    scanf("%d", &position);
    printf("Enter the element: ");
    scanf("%d", &element);

    printf("Initial array: ");
    for (int *ptr = array; ptr < array + size; ptr++)
        printf("%d ", *ptr);
    printf("\n");

    insertElement(array, &size, position, element);

    return 0;
}
*/