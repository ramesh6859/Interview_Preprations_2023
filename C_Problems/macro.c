#include <stdio.h>
#define MIN(a, b)                   \
    if (a < b)                      \
        printf("%d is Minimum", a); \
    else                            \
        printf("%d is Minimum", b);
void main()
{
    printf("\n");
    printf("\n");

    int a = 100, b = 150;
    MIN(a, b);

    printf("\n");
    printf("\n");
}
