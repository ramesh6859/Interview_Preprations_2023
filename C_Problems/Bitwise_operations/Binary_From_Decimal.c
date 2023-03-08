// Method 1
//  #include <stdio.h>
//  int *decimal_to_binary(int);
//  int main()
//  {
//      system("cls");
//      int input_number = 0;
//      int *output_array;
//      printf("Enter the decimal : ");
//      scanf("%d", &input_number);
//      printf("The decimal number : %d\n", input_number);
//      output_array = decimal_to_binary(input_number);
//      printf("The binary number : \n");
//      for (int j = 0; j < 8; j++)
//      {
//          printf("%d ", output_array[j]);
//      }
//      return 0;
//  }
//  int *decimal_to_binary(int number)
//  {
//      static int array[8];
//      int i = 0;
//      for (i = 0; i < 8; i++)
//      {
//          array[8 - i - 1] = number & 1;
//          number >>= 1;
//      }
//      return array;
//  }

// Method 2
//  #include <stdio.h>
//  int *decimal_to_binary(int);
//  int main()
//  {
//      system("cls");
//      int *array, input = 0;
//      printf("Enter the Number: ");
//      scanf("%d", &input);
//      printf("The input number is: %d\n", input);
//      array = decimal_to_binary(input);
//      for (int j = 0; j < 8; j++)
//      {
//          printf("%d", array[j]);
//      }
//  }
//  int *decimal_to_binary(int number)
//  {
//      static int array[8];
//      int i = 0;
//      for (i = 0; number > 0; i++)
//      {
//          array[8 - i - 1] = number % 2;
//          number = number / 2;
//      }
//      return array;
//  }

// Method 3
#include <stdio.h>
void getBinary(int);
int main()
{
    system("cls");
    int num = 0;
    printf("Enter an integer number :");
    scanf("%d", &num);
    printf("Binary value of %d is = \n", num);
    getBinary(num);
    return 0;
}
void getBinary(int n)
{
    int loop;
    for (loop = 7; loop >= 0; loop--)
    {
        if ((1 << loop) & n)
            printf("1");
        else
            printf("0");
    }
}
