#include <stdio.h>

int main() {
    int decimal, mirrored_decimal = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Calculate the mirrored binary representation using bit-shifting
    int num_bits = sizeof(decimal) * 8;  // Calculate the number of bits in an integer
    for (int i = 0; i < num_bits; i++) {
        if (decimal & (1 << i)) {  // Check if the i-th bit is set
            mirrored_decimal |= 1 << (num_bits - 1 - i);  // Set the corresponding mirrored bit
        }
    }

    printf("The mirrored binary representation of the decimal number is: %d\n", mirrored_decimal);

    return 0;
}
