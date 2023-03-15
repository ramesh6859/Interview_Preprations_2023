#include <stdio.h>
void main()
{
    system("cls");
    int first[10] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28};
    int second[10] = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29};
    int third[10] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
    int input_number = 0;
    printf("Enter the input number: ");
    scanf("%d", &input_number);
    for (int i = 0; i < 10; i++)
    {
        if (first[i] == input_number || second[i] == input_number || third[i] == input_number)
        {
            if (first[i] == input_number)
                printf("The %d is in First Array \n", input_number);
            if (second[i] == input_number)
                printf("The %d is in Second Array \n", input_number);
            if (third[i] == input_number)
                printf("The %d is in Third Array \n", input_number);
        }
    }
}