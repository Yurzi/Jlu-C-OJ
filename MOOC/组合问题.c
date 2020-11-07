//组合问题
#include <stdio.h>
int Factorial(int n)
{
    int res = 1;
    if (n <= 0)
    {
        return 0;
    }
    for (size_t i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int n = 0, m = 0;
    int temp = 1;

    scanf("%d %d", &m, &n);
    if (m > 0 && n > 0)
    {
        if (m < n)
        {
            printf("0");
        }
        if (m == n)
        {
            printf("1");
        }
        if (m > n)
        {
            temp = Factorial(m) / (Factorial(n) * Factorial(m - n));
            printf("%d", temp);
        }
    }else{
        printf("-1");
        }
    return 0;
}
