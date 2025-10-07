// #include <stdio.h>
// #include <conio.h>
// #include <string.h>
// void main()
// {
//     char string[20], temp;
//     int i, length;
//     printf("Enter String : ");
//     scanf("%s", string);
//     length = strlen(string) - 1;
//     for (i = 0; i < strlen(string) / 2; i++)
//     {
//         temp = string[i];
//         string[i] = string[length];
//         string[length--] = temp;
//     }
//     printf("\nReverse string :%s", string);
//     getch();
// }

//  ############################################################

// #include <stdio.h>
// #include <string.h>
// void reverseString(char *str)
// {
//     char *begin_ptr, *end_ptr, temp;
//     begin_ptr = str;
//     end_ptr = str;
//     while(*end_ptr)
//          end_ptr++;
//     end_ptr--;
//     while(begin_ptr < end_ptr)
//     {
//         temp = *begin_ptr;
//         *begin_ptr = *end_ptr;
//         *end_ptr = temp;
//         begin_ptr++;
//         end_ptr--;
//     }
// }
// int main()
// {
//     system("cls");
//     char str[100];
//     printf("Enter a string: ");
//     scanf("%s", str);
//     printf("The entered string is : %s\n", str);
//     reverseString(str);
//     printf("Reverse of the string: %s\n", str);
//     return 0;
// }

//  ############################################################

#include <stdio.h>
#define maxsize 100
int main()
{
    system("cls");
    char str[maxsize], reverse[maxsize];
    char *s = str;
    char *r = reverse;
    int len = 0;
    printf("Enter any string: ");
    gets(str);
    while(*(s++)) len++;
    s--;
    while(len >= 0)
    {
        *(r++) = *(--s);
        len--;
    }
    *r = '\0';
    printf("\nOriginal string = %s\n", str);
    printf("Reverse string = %s", reverse);
    return 0;
}
