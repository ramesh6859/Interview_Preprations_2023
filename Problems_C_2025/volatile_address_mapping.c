#include <stdio.h>
#define ADDRESS 0xFFFF0000

int main() {
    volatile unsigned char *ptr = (volatile unsigned char *)ADDRESS;
    *ptr = 0x31;
    printf("Address: %p\n", (void *)ptr);
    return 0;
}
