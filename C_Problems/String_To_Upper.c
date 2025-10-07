#include <stdio.h>
#define maxsize 100
int main()
{
    system("cls");
    char str[maxsize];
    char * s = str;
    printf("Enter your text : ");
    gets(str);
    while(*s)
    {
        *s = (*s >= 'a' && *s <= 'z') ? *s-32 : *s;
        s++;
    }
    printf("Uppercase string : %s",str);
    return 0;
}