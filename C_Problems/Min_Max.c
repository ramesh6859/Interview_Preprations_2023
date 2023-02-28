#include<stdio.h>

void MinMax(int a[], int len, int *min, int *max)
{
    *min = *max = a[0];
    int i;
    for(i=0; i<len; i++)
    {
        if(a[i] > *max)
        {
            *max = a[i];
        }
        if(a[i] < *min)
        {
            *min = a[i];
        }
    }
}

void main()
{
    int a[] = {23, 4, 21, 98, 987, 45, 32, 10, 123, 986, 50, 3, 4, 5};
    int min, max;
    int len = sizeof(a)/sizeof(a[0]);
    printf("Number of elements: %d\n", len);
    MinMax(a, len, &min, &max);
    printf("Minimum value in the array is: %d\n", min);
    printf("Maximum value in the array is: %d\n", max);
}

