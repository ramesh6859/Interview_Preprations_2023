// #include <stdio.h>
// #define maxsize 100
// int main()
// {
//     system("cls");
//     char text1[maxsize], text2[maxsize];
//     char * str1 = text1;
//     char * str2 = text2; 
//     printf("Enter any string: ");
//     gets(text1);
//     while(*(str2++) = *(str1++));
//     printf("First string = %s\n", text1);
//     printf("Second string = %s\n", text2);
//     return 0;
// }

//  ############################################################

#include <stdio.h>
#define maxsize 100
int main()
{
    system("cls");
    char text1[maxsize];
    char text2[maxsize];
    int i;
    printf("Enter any string: ");
    gets(text1);
    i=0;
    while(text1[i] != '\0')
    {
        text2[i] = text1[i];
        i++;
    }
    text2[i] = '\0';
    printf("First string = %s\n", text1);
    printf("Second string = %s\n", text2);
    printf("Total characters copied = %d\n", i);
    return 0;
}