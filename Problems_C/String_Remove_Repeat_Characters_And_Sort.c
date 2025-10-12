#include <stdio.h>
#include <string.h>
void main()
{
    system("cls");
    int x, j = 0, k = 0;
    char str[100], str1[10][20], temp, min;
    printf("enter the string:");
    scanf("%[^\n]s", str);
    /* ignores spaces */
    for (x = 0; str[x]!= '\0';x++)
    {
        if (str[x] == ' ')
        {
            for (j = x;str[j] != '\0'; j++)
                str[j] = str[j + 1];
        }
    }
    /* removes repeated characters */
    for (x = 0;str[x]!= '\0';x++)
    {
        for (j = x + 1;str[j] != '\0';j++)
        {
            if (str[x] == str[j])
            {
                for (k = j; str[k] != '\0'; k++)
                    str[k] = str[k+1];
                j--;
            }
        }
    }
    /* sorts the string */
    for (x = 0; str[x] != '\0'; x++) 
    {
        for (j = 0; str[j] != '\0';j++)
        {
            if (str[j] > str[x])
            {
                temp = str[x];
                str[x] = str[j];
                str[j] = temp;
            }
        }
    }
    printf("%s", str);
}