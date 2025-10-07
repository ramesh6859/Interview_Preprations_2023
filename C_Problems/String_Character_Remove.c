#include <stdio.h>
void removeCharacter(char*, char);
int main()
{
    system("cls");
    char str[100], ch;
    printf("Enter a string: \n");
    scanf("%s", str);
    printf("Enter the character to remove: \n");
    scanf(" %c", &ch);
    removeCharacter(str, ch);
    printf("String after removing %c: %s\n", ch, str);
    return 0;
}
void removeCharacter(char* str, char ch)
{
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ch) 
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}