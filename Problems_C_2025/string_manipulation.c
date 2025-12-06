#include<stdio.h>
#include<string.h>

void endian_check() {
    int i = 1;
    char *p = (char *)&i;
    if (*p == 1) printf("Little Endian");
    else printf("Big Endian");
}

char *my_strcpy(char *dest, const char *src) {
    char *start = dest;
    while((*dest++ = *src++));
    return start;
}

void reverse(char *s) {
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        char temp = s[i]; 
        s[i] = s[j]; 
        s[j] = temp;
        i++; 
        j--;
    }
}

int main() {
    char string_initial[50] = "Ramesh";
    char string_final[50];

    // endian_check();

    // my_strcpy(string_final, string_initial);
    // printf("Copied String : %s\n", string_final);

    // reverse(string_initial);
    // printf("Reversed String : %s\n", string_initial);

    
    return 0;
}