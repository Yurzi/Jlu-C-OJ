#include<stdio.h>
//定义函数以计算斐波纳契序列
long long toSolve(int n){
    long long a0=0;
    long long a1=1;
    long long a2=0;
    if (n==0)
    {
        return 1; 
    }else if (n==1)
    {
        return 1;
    }else if (n>=2)
    {
        for (long i = 1; i <=n; i++)
        {
            a2=a0+a1;
            a0=a1;
            a1=a2;
        }
        return a2;
        
    }     
}
int main(int argc, char const *argv[])
{
    long n=0;

    //输入
    scanf("%ld",&n);

    //输出
    printf("%lld",toSolve(n));
    return 0;
}
