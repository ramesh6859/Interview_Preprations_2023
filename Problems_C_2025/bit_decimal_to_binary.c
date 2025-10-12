#include <stdio.h>
#include <stdlib.h>
int* decimal_to_binary(int decimal) {
    static int binary[8];
    for (int k = 0; k < 8; k++)
        binary[k] = 0;
    int i = 7;
    while (decimal > 0 && i >= 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i--;
    }
    return binary;
}
void print_binary(int* binary) {
    for (int i = 0; i < 8; i++)
        printf("%d", binary[i]);
}
int main() {
    system("cls");
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Original number: %d\n", num);
    int* binary_number = decimal_to_binary(num);
    printf("Original Binary: ");
    print_binary(binary_number);
    return 0;
}
