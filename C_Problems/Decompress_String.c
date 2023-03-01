// abc2[pq] = abcpqpq
// a3[b]c = abbbc

#include <stdio.h>

char* Decompression_String(char *strng)
{
    printf("gu");
    return strng;
}
int main()
{
    char input_string[20];
    char *output_string;
    printf("String Decompression\n");
    printf("Enter the String : ");
    scanf("%s",input_string);
    printf("The Input String is : %s\n", input_string);
    output_string = Decompression_String(&input_string);
    printf("%s", *output_string);
    return 0;
}

