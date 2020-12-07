#include<stdio.h>

int gcd(int,int);

int main(int argc, char const *argv[])
{
    int m=0;
    int n=0;
    int res=0;

    //输入
    scanf("%d %d",&m,&n);

    //处理
    res=gcd(m,n);

    //输出
    printf("%d",res);

    return 0;
}

//求最大公因数
int gcd(int x,int y){
    if (x%y==0)
    {
        return y;
    }else
    {
        return gcd(y,x%y);
    }
}