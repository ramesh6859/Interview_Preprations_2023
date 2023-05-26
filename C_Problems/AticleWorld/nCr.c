// #include <stdio.h>
// #define FACTORIAL(n) \
//     ({ \
//         int fact = 1; \
//         for (int i = 1; i <= (n); ++i) \
//             fact *= i; \
//         fact; \
//     })
// #define NCR(n, r) \
//     (FACTORIAL(n) / \
//     (FACTORIAL(r) * FACTORIAL(n - r)))

// int main() {
//     int num, r;
//     printf("Enter the value of num = ");
//     scanf("%d",&num);
//     printf("Enter the value of r = ");
//     scanf("%d",&r);
//     int result = NCR(num, r);
//     printf("%dC%d = %d\n", num, r, result);
//     return 0;
// }

#include <stdio.h>
int fact(int n)
{
    int i;
    int res = 1;
    for (i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int getnCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int main()
{
    int num, r;
    long ncrValue;
    printf("Enter the value of num = ");
    scanf("%d",&num);
    printf("Enter the value of r = ");
    scanf("%d",&r);
    ncrValue = getnCr(num, r);
    printf("%d C %d = %ld\n", num, r, ncrValue);
    return 0;
}