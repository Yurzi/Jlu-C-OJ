#include<stdio.h>

int Ackerman(int,int);

int main(int argc, char const *argv[])
{
    int m=0;
    int n=0;
    int res=0;

    //输入
    scanf("%d %d",&m,&n);

    //处理
    res=Ackerman(m,n);

    //输出
    printf("%d",res);
    
    return 0;
}

int Ackerman(int m,int n){
    if (m==0)
    {
        return n+1;
    }
    if (n==0)
    {
        return Ackerman(m-1,1);
    }
    if (m>0&&n>0)
    {
        return Ackerman(m-1,Ackerman(m,n-1));
    }
    return -1;
}