#include <stdio.h>
void reverse(int *arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = temp;
    }
}
void rotateRight(int *arr, int size, int k) {
    k = k % size;
    if (k == 0) 
        return;
    // Step 1: Reverse entire array
    reverse(arr, 0, size - 1);
    // Step 2: Reverse first k elements
    reverse(arr, 0, k - 1);
    // Step 3: Reverse remaining elements
    reverse(arr, k, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rotateRight(arr, size, k);

    printf("Rotated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
