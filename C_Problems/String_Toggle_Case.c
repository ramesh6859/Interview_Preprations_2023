#include <stdio.h>
#define maxsize 100
void toggleCase(char *);
int main()
{
    system("cls");
    char str[maxsize];
    printf("Enter any string: ");
    scanf("%[^\n]s", str);
    printf("String before toggling case: %s\n", str);
    toggleCase(str);
    printf("String after toggling case: %s\n", str);
    return 0;
}
void toggleCase(char * str)
{
    int x = 0;
    while(str[x] != '\0')
    {
        if(str[x]>='a' && str[x]<='z')
            str[x] = str[x] - 32;
        else if(str[x]>='A' && str[x]<='Z')
            str[x] = str[x] + 32;
        x++;
    }
}