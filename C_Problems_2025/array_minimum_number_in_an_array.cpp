#include <stdio.h>
#include <stdlib.h>
int find_min(const int *array, size_t length) {
    int min = *array;
    for (size_t i = 1; i < length; i++)
        if (*(array + i) < min)
            min = *(array + i);
    return min;
}
int main() {
    system("cls");
    int numbers[] = {37, 95, 73, 59, 15, 15, 86, 60, 70, 2, 96, 83, 21, 18, 18, 30, 52, 43, 29, 61, 13, 29, 36, 45};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);
    int (*find_min_ptr)(const int *, size_t) = find_min;
    int min = find_min_ptr(numbers, length);
    printf("Minimum: %d", min);
    return 0;
}
