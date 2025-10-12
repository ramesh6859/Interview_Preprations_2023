// #include <stdio.h>
// #define maxsize 100
// int main()
// {
//     system("cls");
//     char str1[maxsize], str2[maxsize];
//     char * s1 = str1;
//     char * s2 = str2;
//     printf("Enter first string: ");
//     gets(str1);
//     printf("Enter second string: ");
//     gets(str2);
//     while(*(++s1));
//     while(*(s1++) = *(s2++));
//     printf("Concatenated string = %s", str1);
//     return 0;
// }

//  ############################################################

#include <stdio.h>
#define maxsize 100
int main()
{
    system("cls");
    char str1[maxsize], str2[maxsize];
    int i, j;
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    i=-1;
    while(str1[++i]);
    j = 0;
    while(str1[i++] = str2[j++]);
    printf("Concatenated string = %s", str1);
    return 0;
}