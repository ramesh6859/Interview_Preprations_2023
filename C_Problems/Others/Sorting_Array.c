#include <stdio.h>
void main()
{
    system("cls");
    int i, j, temp, limit, number[30];
    printf("Enter the value of N : ");
    scanf("%d", &limit);
    printf("Enter the numbers \n");
    for (i = 0; i < limit; ++i)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &number[i]);
    }
    for (i = 0; i < limit; ++i)
    {
        for (j = i + 1; j < limit; ++j)
        {
            if (number[i] > number[j])
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }
    printf("The numbers arranged in ascending order : ");
    for (i = 0; i < limit; ++i)
        printf("%d ", number[i]);
}