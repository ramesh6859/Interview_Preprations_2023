#include <stdio.h>
#include <stdlib.h>
int main()
{
    for (int x = 0; x < 135; x++)
        fprintf(stderr, "%d: %s\n", x, strerror(x));
    return 0;
}