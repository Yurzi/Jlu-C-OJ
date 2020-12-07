#include<stdio.h>

int combinatorial_Number(int,int);

int main(int argc, char const *argv[])
{
    int m=0;
    int n=0;
    int res=0;

    //输入
    scanf("%d %d",&m,&n);

    //组合函数
    res=combinatorial_Number(m,n);

    //输出
    printf("%d",res);

    return 0;
}

int combinatorial_Number(int m,int n){
    if (n<0)
    {
        return 0;
    }
    if (n==0)
    {
        return 1;    
    }
    if (n==1)
    {
        return m;
    }
    if (m<2*n)
    {
        return combinatorial_Number(m,m-n);
    }else
    {
        return combinatorial_Number(m-1,n-1)+combinatorial_Number(m-1,n);
    }   
}