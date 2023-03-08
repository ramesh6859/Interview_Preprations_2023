#include <stdio.h>
char *isAllBitsUnset(int);
char *isAllBitsSet(int);
int main()
{
    system("cls");
    int input_number = 0, count = 0;
    printf("Enter the input decimal number : ");
    scanf("%d", &input_number);
    printf("%s", isAllBitsUnset(input_number));
    printf("%s", isAllBitsSet(input_number));
    return 0;
}
char *isAllBitsUnset(int number)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        if (number & 1)
        {
            count++;
            break;
        }
        number >>= 1;
    }
    if (count >= 1)
        return "All bits are not UNSET/LOW\n";
    else
        return "All bits are UNSET/LOW\n";
}
char *isAllBitsSet(int number)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        if (!(number & 1))
        {
            count++;
            break;
        }
        number >>= 1;
    }
    if (count)
        return "All bits are not SET/HIGH\n";
    else
        return "All bits are SET/HIGH\n";
}
