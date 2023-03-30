#include <stdio.h>
int main(void)
{
    system("cls");
    float miles, km;
    printf("Enter the distance in miles : ");
    scanf("%f", &miles);
    km = miles * 1.609;
    printf("%f Mile equals %f Kilometer\n", miles, km);
    return 0;
}