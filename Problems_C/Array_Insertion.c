#include <stdio.h>
#include <stdlib.h>
void insertElement(int *array, int *size, int position, int element) {
    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *size; i > position; i--)
        array[i] = array[i - 1];
    array[position] = element;
    (*size)++;
    printf("Element %d inserted at position %d.\nUpdated array: ", element, position);
    for (int i = 0; i < *size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
int main() {
    system("cls");
    int array[10] = {1, 2, 3, 4, 5};
    int size = 5, position, element;
    printf("Enter the position: ");
    scanf("%d", &position);
    printf("Enter the element: ");
    scanf("%d", &element);
    printf("Initial array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    insertElement(array, &size, position, element);
    return 0;
}
