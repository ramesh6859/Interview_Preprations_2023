#include <stdio.h>

int main()

{

    char a[50], b[50], t;

    int i, j;

    printf("Enter a String..\n");

    gets(a);

    for (i = 0; a[i]; i++)

        b[i] = a[i];

    b[i] = '\0';

    printf("%s\n", b);

    for (i = 0; a[i]; i++)
        ;

    for (j = i - 1, i = 0; i < j; i++, j--)

    {

        t = a[i];

        a[i] = a[j];

        a[j] = t;
    }

    printf("%s\n", a);

    for (i = 0; a[i]; i++)

    {

        if (a[i] != b[i])

            break;
    }

    if (a[i] == b[i])

        printf("It is a Palindrome..\n");

    else

        printf("It is not a Palindrome..\n");
}