#include<stdio.h>
//定义函数递归法计算斐波纳契序列
long long toSolve(int n){ 
    if (n==0)
    {
        return 1;   
    }else if (n==1)
    {
        return 1;
    }
    else if (n>=2)
    {
        return toSolve(n-1)+toSolve(n-2);
        
    }
}

int main(int argc, char const *argv[])
{
    int n=0;

    //输入n;
    scanf("%d",&n);

    //输出
    printf("%lld",toSolve(n));
    return 0;
}

