#include <stdio.h>
void printNos(unsigned int n)
{
  if(n > 0)
  {
    printNos(n-1);
    printf("%d ",  n);
  } 
}

int main()
{
    int number = 10;
    printNos(number);
    return 0;
}
