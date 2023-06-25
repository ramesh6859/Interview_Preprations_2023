#include <stdio.h>
int isSubstring(const char*, const char*);
void readString(char*, int);
int main()
{
    system("cls");
    char string[100];
    char substring[100];
    printf("Enter a string: ");
    readString(string, sizeof(string));
    printf("Enter a substring to search: ");
    readString(substring, sizeof(substring));
    if (isSubstring(string, substring))
        printf("Substring found in the string.\n");
    else
        printf("Substring not found in the string.\n");
    return 0;
}
int isSubstring(const char* string, const char* substring)
{
    int i = 0;
    int j = 0;
    while (string[i] != '\0' && substring[j] != '\0')
    {
        if (string[i] == substring[j])
            j++;
        else
        {
            j = 0;
            if (string[i] == substring[j])
                j++;
        }
        i++;
    }
    if (substring[j] == '\0')
        return 1;
    return 0;
}
void readString(char* str, int maxLength)
{
    int i = 0;
    char c;
    while (i < maxLength - 1)
    {
        c = getchar();
        if (c == '\n' || c == EOF)
            break;
        str[i] = c;
        i++;
    }
    str[i] = '\0';
}