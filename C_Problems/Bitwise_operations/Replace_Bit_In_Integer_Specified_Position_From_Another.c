#include <stdio.h>
int replaceBit(int, int, int);
int main()
{
    system("cls");
    int first_number = 0, second_number = 0, position = 0;
    printf("Enter the first number: ");
    scanf("%d", &first_number);
    printf("Enter the second number: ");
    scanf("%d", &second_number);
    printf("Enter the position to change the bit: ");
    scanf("%d", &position);
    printf("%d\n", replaceBit(first_number, second_number, position));
    return 0;
}
int replaceBit(int first, int second, int pos)
{
    int new_number, change_bit;
    new_number = 1 << pos;
    first &= ~new_number;
    change_bit = (second >> pos) & 1;
    first |= change_bit << pos;
    return first;
}
