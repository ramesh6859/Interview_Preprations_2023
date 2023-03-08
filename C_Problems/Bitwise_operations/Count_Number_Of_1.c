#include <stdio.h>
#define IntSize sizeof(int) * 8
int Count_ones(int);
int main()
{
    system("cls");
    int input_number = 0;
    printf("Enter the input decimal number : ");
    scanf("%d", &input_number);
    printf("The number of Ones : %d\n", Count_ones(input_number));
    return 0;
}
int Count_ones(int number)
{
    int count = 0;
    for (int i = 0; i < IntSize; i++)
    {
        if (number & 1)
            count++;
        number >>= 1;
    }
    return count;
}