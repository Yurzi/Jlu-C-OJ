#include<stdio.h>
//定义函数以计算斐波纳契序列
int toSolve(int n){
    int a0=0;
    int a1=1;
    int a2=0;
    if (n==0)
    {
        return 1; 
    }else if (n==1)
    {
        return 1;
    }else if (n>=2)
    {
        for (int i = 1; i <=n; i++)
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
    int n=0;

    //输入
    scanf("%d",&n);

    //输出
    printf("%d",toSolve(n));
    return 0;
}
