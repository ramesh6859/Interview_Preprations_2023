#include <stdio.h>

union {
    unsigned int i;
    char bytes[4];
} EndianChecker;

int main() {
    EndianChecker checker;
    checker.i = 1;

    if (checker.bytes[0] == 1) {
        printf("This system is Little-Endian.\n");
    } else {
        printf("This system is Big-Endian.\n");
    }

    return 0;
}
