#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int minutes;
    int hours;
} time;

int main()
{
    time *tm = calloc(2, sizeof(*tm));
}