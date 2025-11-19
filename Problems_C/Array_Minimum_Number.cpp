#include <stdio.h>
#include <stdlib.h>
int find_min(const int *arr, size_t len) {
    int min = arr[0];
    for (size_t i = 1; i < len; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}
int main() {
    system("cls");
    int numbers[] = {37, 95, 73, 59, 15, 15, 86, 60, 70, 2, 96, 83, 21, 18, 18, 30, 52, 43, 29, 61, 13, 29, 36, 45};
    size_t len = sizeof(numbers) / sizeof(numbers[0]);
    printf("Minimum: %d\n", find_min(numbers, len));
    return 0;
}
