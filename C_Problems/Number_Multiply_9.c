#include<stdio.h>
int main(){
    int number;
    printf("Enter the Number: ");
    scanf("%d", &number);
    printf("Result: %d\n", (number<<3)+number);
    return 0;
}