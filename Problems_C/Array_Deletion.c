#include <stdio.h>
#include <stdlib.h>
void deleteElement(int *arr, int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
    printf("Element at position %d deleted. Updated array: ", position);
    for (int i = 0; i < *size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    system("cls");
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("Initial array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    deleteElement(array, &size, pos);
    return 0;
}
