#include<stdio.h>
char *returnstring();
void main()
{
    char *result;
    result = returnstring();
    printf("%s\n", result);
    result[0] = 'S';
    printf("%s", result);
}
char *returnstring()
{
    static char str[] = "Ramesh K P"; 
    return str;
}
