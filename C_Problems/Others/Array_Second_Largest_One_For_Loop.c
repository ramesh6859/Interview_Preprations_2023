#include <stdio.h>
int main()
{
    system("cls");
    int arr[] = {5, 8, 2, 10, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int largest = arr[0];
    int secondLargest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
            secondLargest = arr[i];
    }
    printf("The second largest element is: %d\n", secondLargest);
    return 0;
}
