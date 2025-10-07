#include <stdio.h>
#include <stdlib.h>
int find_max(const int *array, size_t length) {
    int max = *array;
    for (size_t i = 1; i < length; i++)
        if (*(array + i) > max)
            max = *(array + i);
    return max;
}
int main() {
    system("cls");
    int numbers[] = {37, 95, 73, 59, 15, 15, 86, 60, 70, 2, 96, 83, 21, 18, 18, 30, 52, 43, 29, 61, 13, 29, 36, 45};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);
    int (*find_max_ptr)(const int *, size_t) = find_max;
    int max = find_max_ptr(numbers, length);
    printf("Maximum: %d", max);
    return 0;
}
