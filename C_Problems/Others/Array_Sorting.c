#include <stdio.h>
void sortNumbers(int [], int);
int main()
{
    system("cls");
    int limit, number[30];
    printf("Enter the limit: ");
    scanf("%d", &limit);
    printf("Enter the numbers: \n");
    for (int i = 0; i < limit; ++i)
        scanf("%d", &number[i]);
    sortNumbers(number, limit);
    printf("The numbers arranged in ascending order: \n");
    for (int i = 0; i < limit; ++i)
        printf("%d ", number[i]);
    return 0;
}

void sortNumbers(int number[], int limit)
{
    for (int i = 0; i < limit; ++i)
    {
        for (int j = i + 1; j < limit; ++j) 
        {
            if (number[i] > number[j])
            {
                int temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }
}
