//组合问题
//超星中应使用long long 类型
#include <stdio.h>
long long Factorial(int n)
{
    long long res = 1;
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
    long long temp = 1;

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
            temp = (long long)(Factorial(m) / (Factorial(n) * Factorial(m - n)));
            printf("%lld", temp);
        }
    }else{
        printf("-1");
        }
    return 0;
}
