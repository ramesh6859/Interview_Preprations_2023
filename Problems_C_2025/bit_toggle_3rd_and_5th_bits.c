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
void print_binary(int* binary) {
    for (int i = 0; i < 8; i++)
        printf("%d", binary[i]);
}
int main() {
    system("cls");
    int num, toggled_num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Original number: %d\n", num);
    int* binary_number = decimal_to_binary(num);
    printf("Original Binary: ");
    print_binary(binary_number);
    printf("\n");
    num = num ^ ((1 << 2) | (1 << 4));
    int* toggled_binary = decimal_to_binary(num);
    printf("Binary after toggling 3rd and 5th bits: ");
    print_binary(toggled_binary);
    printf("\n");
    
    toggled_num = binary_to_decimal(toggled_binary);
    printf("Toggled number: %d", toggled_num);
    return 0;
}
