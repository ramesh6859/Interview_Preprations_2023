/*
("Python") -> "PYTHON"
("abcdcsd") -> "ABCDCSD"
*/
#include <stdio.h>
#include <string.h>
int main()
{
    printf("\n");
    char input_str[] = "Python";
    int i;
    int len = strlen(input_str);
    for (i = 0; i < len; i++)
    {
        if (input_str[i] >= 'a' && input_str[i] <= 'z')
            input_str[i] = input_str[i] - 32;
    }
    printf("%s\n", input_str);
    printf("\n");
    return 0;
}