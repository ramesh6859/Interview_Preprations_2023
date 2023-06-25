#include<stdio.h>
void reverse_string(char *);
int check_palindrome(char *);
int main()
{
    system("cls");
    char string[50], temp;
    printf("Enter the input string : ");
    scanf("%s", string);
    printf("The Entered string is : %s\n", string);
    reverse_string(string);
    printf("The Entered string is : %s\n", string);
    if(check_palindrome(string))
        printf("%s is palindrome", string);
    else
        printf("%s is not a palindrome", string);
    return 0;   
}

void reverse_string(char *string)
{
    char *source = string;
    char *dest = string;
    char temp;
    while(*dest)
         dest++;
    dest--;
    while(source < dest)
    {
        temp = *source;
        *source = *dest;
        *dest = temp;
        source++;
        dest--;
    }
}
int check_palindrome(char *string)
{
    char *source = string;
    char *dest = string;
    while(*dest)
         dest++;
    dest--;
    while (source < dest)
    {
        if (*source != *dest)
            return 0;
        source++;
        dest--;
    }
    return 1;
}