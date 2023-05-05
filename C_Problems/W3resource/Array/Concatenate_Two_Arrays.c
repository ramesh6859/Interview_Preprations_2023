// ({ 10, 20, 30, 40, 50, 60 }, { 70, 80, 90, 100, 110, 120 }) -> "10 20 30 40 50 60 70 80 90 100 110 120"
#include<stdio.h>
void main()
{
    int first[] = { 10, 20, 30, 40, 50, 60 };
    int second[] = { 70, 80, 90, 100, 110, 120 };
    
    int first_size, second_size, result_size;
    int i;

    first_size = sizeof(first) / sizeof(first[0]);
    second_size = sizeof(second) / sizeof(second[0]);
    result_size = first_size + second_size;
    
    int result[result_size];

    printf("%d\n", first_size);
    printf("%d\n", second_size);
    
    for(i=0;i<first_size;i++)
        printf("%d\t", first[i]);
    printf("\n");
    for(i=0;i<second_size;i++)
        printf("%d\t", second[i]);
    printf("\n");
    
    for(i=0;i<first_size;i++)
        result[i] = first[i];
    for(int i = 0; i < second_size; i++)     
        result[i + first_size] = second[i];
    for(i=0;i<result_size;i++)
        printf("%d\t", result[i]);
    
    // for (i = 0; second[i] != '\0'; i++, first_size++)
    //     first[first_size] = second[i];    
    // for(i=0;i<result_size;i++)
    //     printf("%d\t", first[i]);

    printf("\n");
    
}