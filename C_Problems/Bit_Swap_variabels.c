// Online C compiler to run C program online
#include <stdio.h>
int main (){
    /*
    // Using Extra Memory Space:
    int num1=20, num2=30, temp;
    printf("Numbers before swapping:%d and %d\n", num1, num2);
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("Numbers after swapping:%d and %d\n", num1, num2);

    // Using Arithmetic Operators:
    int num1=20, num2=30;
    printf("Numbers before swapping:%d and %d\n", num1, num2);
    num1=num1 + num2;
    num2=num1 - num2;
    num1=num1 - num2;
    printf("Numbers after swapping:%d and %d\n", num1, num2);
    
    // Using Bit-Wise Operators:
    int num1=20, num2=30;
    printf("Numbers before swapping:%d and %d\n", num1, num2);
    num1=num1 ^ num2;
    num2=num2 ^ num1;
    num1=num1 ^ num2;
    printf("Numbers after swapping:%d and %d\n", num1, num2);

    // Using One-liner Bit-wise Operators:
    int num1=20, num2=30;
    printf("Numbers before swapping:%d and %d\n", num1, num2);
    num1^=num2^=num1^=num2;
    // The order of evaluation here is right to left.
    printf("Numbers after swapping:%d and %d\n", num1, num2);
    */
    
    // Using One-liner Arithmetic Operators:
    int num1=20, num2=30;
    printf("Numbers before swapping:%d and %d\n", num1, num2);
    num1 = (num1+num2)-(num2=num1);
    // Here the order of evaluation is from left to right.
    printf("Numbers after swapping:%d and %d\n", num1, num2);
    
    return 0;
}