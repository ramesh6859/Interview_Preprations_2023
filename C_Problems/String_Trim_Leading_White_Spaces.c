#include <stdio.h>
#define maxsize 100
void trimLeading(char *);
int main()
{
    system("cls");
    char str[maxsize];
    printf("Enter any string: ");
    scanf("%[^\n]s", str);
    printf("String before trimming leading whitespace: %s\n", str);
    trimLeading(str);
    printf("String after trimming leading whitespace: %s\n", str);
    return 0;
}
void trimLeading(char * str)
{
    int index, i, j;
    index = 0;
    while(str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
        index++;
    if(index != 0)
    {
        i = 0;
        while(str[i + index] != '\0')
        {
            str[i] = str[i + index];
            i++;
        }
        str[i] = '\0';
    }
}
