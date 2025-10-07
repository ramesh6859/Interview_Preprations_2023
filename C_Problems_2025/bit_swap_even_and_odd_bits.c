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
int binary_to_decimal(int* binary) {
    int decimal = 0;
    for (int i = 0; i < 8; i++)
        decimal = decimal * 2 + binary[i];
    return decimal;
}
int swap_even_odd_bits(int n) {
    unsigned char even_bits = n & 0xAA;
    unsigned char odd_bits = n & 0x55;
    even_bits >>= 1;
    odd_bits <<= 1;
    return (even_bits | odd_bits);
}
void print_binary(int* binary) {
    for (int i = 0; i < 8; i++)
        printf("%d", binary[i]);
}
int main() {
    system("cls");
    int num, swapped_num;
    printf("Enter the number (0-255): ");
    scanf("%d", &num);
    printf("Original number: %d\n", num);
    int* binary_number = decimal_to_binary(num);
    printf("Original Binary: ");
    print_binary(binary_number);
    printf("\n");
    swapped_num = swap_even_odd_bits(num);
    printf("Swapped number: %d\n", swapped_num);
    int* swapped_binary = decimal_to_binary(swapped_num);
    printf("Swapped Binary: ");
    print_binary(swapped_binary);
    return 0;
}
