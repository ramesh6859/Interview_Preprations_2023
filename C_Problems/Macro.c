#include <stdio.h>
#define MIN(x,y) ((x < y) ? x : y)

void main()
{
    system("cls");
    int first_no, second_no;
    printf("Enter the first number: ");
    scanf("%d", &first_no);
    printf("Enter the second number: ");
    scanf("%d", &second_no);
    printf("Minimum Number : %d\n", MIN(first_no, second_no));
}