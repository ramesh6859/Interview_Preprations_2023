#include <stdio.h>
void mergeSortedArrays(int *arr1, int size1, int *arr2, int size2, int *merged) {
    int *end1 = arr1 + size1;
    int *end2 = arr2 + size2;
    int *ptr = merged;
    // Traverse both arrays using pointers
    while (arr1 < end1 && arr2 < end2) {
        if (*arr1 <= *arr2) {
            *ptr++ = *arr1++;
        } else {
            *ptr++ = *arr2++;
        }
    }
    // Copy remaining elements from arr1
    while (arr1 < end1) {
        *ptr++ = *arr1++;
    }
    // Copy remaining elements from arr2
    while (arr2 < end2) {
        *ptr++ = *arr2++;
    }
}

int main() {
    int arr1[] = {1, 4, 7, 8};
    int arr2[] = {2, 3, 5, 6, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int merged[size1 + size2];
    int i;

    mergeSortedArrays(arr1, size1, arr2, size2, merged);

    printf("Merged array: ");
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
