#include<stdio.h>
int main()
{
    system("cls");
    int input_num = 0, flag = 1;
    printf("Enter the input number : ");
    scanf("%d", &input_num);

    for (int i = 2; i <= input_num / 2; i++) 
    {
        if (input_num % i == 0) 
        {
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("%d is a Prime number", input_num);
    else
        printf("%d is not a Prime number", input_num);

    return 0;
}