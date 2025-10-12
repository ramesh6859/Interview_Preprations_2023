#include <stdio.h>
#include <stdlib.h>
int binary_to_decimal(int* binary) {
    int decimal = 0;
    for (int i = 0; i < 8; i++)
        decimal = decimal * 2 + binary[i];
    return decimal;
}
void print_binary(int* binary) {
    for (int i = 0; i < 8; i++)
        printf("%d", binary[i]);
}
int main() {
    system("cls");
    int decimal, binary_number[8];
    printf("Enter 8 bits of the binary number (0 or 1), separated by spaces: ");
    for (int i = 0; i < 8; i++)
        scanf("%d", &binary_number[i]);
    printf("The entered binary is: ");
    print_binary(binary_number);
    printf("\n");
    decimal = binary_to_decimal(binary_number);
    printf("Decimal number: %d", decimal);
    return 0;
}
