#include <stdio.h>

#define SIZEOF(type) ((char*)(&type+1) - (char*)(&type))

int main()
{
    int first;
    double second;
    char third;

    printf("Size of int: %d \n", SIZEOF(first));
    printf("Size of double: %d \n", SIZEOF(second));
    printf("Size of char: %d \n", SIZEOF(third));

    return 0;
}
