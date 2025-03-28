#include <stdio.h>
#define maxsize 100
int compare(char *, char *);
int main()
{
    system("cls");
    char str1[maxsize], str2[maxsize];
    int res;
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    res = compare(str1, str2);
    if(res == 0)
        printf("Both strings are equal.");
    else if(res < 0)
        printf("First string is lexicographically smaller than second.");
    else
        printf("First string is lexicographically greater than second.");
    return 0;
}
int compare(char * str1, char * str2)
{
    while((*str1 && *str2) && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}