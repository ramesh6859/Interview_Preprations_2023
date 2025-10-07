#include <stdio.h>
void deleteElement(int [], int *, int);
int main()
{
    system("cls");
    int array[] = {1, 2, 3, 4, 5};
    int size = 0, position = 0;
    size = sizeof(array) / sizeof(array[0]);
    printf("Enter the position : ");
    scanf("%d", &position);
    printf("Initial array: ");
    for (int i = 0; i < size; i++) 
        printf("%d ", array[i]);
    printf("\n");
    deleteElement(array, &size, position);
    return 0;
}

void deleteElement(int array[], int *size, int position)
{
    if (position < 0 || position >= *size) 
    {
        printf("Invalid position to delete element.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++)
        array[i] = array[i + 1];
    (*size)--;
    printf("Element at position %d deleted successfully.\n", position);
    printf("Updated array: ");
    for (int i = 0; i < *size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
