#include <stdio.h>
int stringLength(const char*);
int endsWithSingh(const char*);
int main()
{
    system("cls");
    const char* strings[] = {"kpsingh", "rpsingh", "klsingh", "singh", "singhmr", "kksingh"};
    int numStrings = sizeof(strings) / sizeof(strings[0]);
    printf("Strings ending with 'singh':\n");
    for (int i = 0; i < numStrings; i++) 
    {
        if (endsWithSingh(strings[i]))
            printf("%s\n", strings[i]);
    }
    return 0;
}
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
int endsWithSingh(const char* str)
{
    int strLength = stringLength(str);
    int singhLength = stringLength("singh");
    if (strLength < singhLength)
        return 0;
    int i = strLength - singhLength;
    int j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != "singh"[j])
            return 0;
        i++;
        j++;
    }
    return 1;
}