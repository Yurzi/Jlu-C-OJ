#include<stdio.h>
//计算乘方
int intpow(int x,int y){
    int sum=1;
    for (int i = 0; i < y; i++)
    {
        sum=sum*x;
    }
    return sum;
    
}
int main(int argc, char const *argv[])
{
    //定义缓存数组
    int a=0,b=0,c=0,t=0,n=0;
    int temp[1000];

    for (int i = 100; i < 1000; i++)
    {
        //分开每位数
        t=i;
        c=t%10;
        t=t/10;
        b=t%10;
        t=t/10;
        a=t%10;
        //找到符合的数
        if ((intpow(a,3)+intpow(b,3)+intpow(c,3))==i)
        {
            temp[n]=i;
            n++;
        }
    }

    //输出
    for (int i = 0; i < n; i++)
    {
        if (i==(n-1))
        {
            printf("%d",temp[i]);
        }else
        {
            printf("%d ",temp[i]);
        }
        
        
    }
    
    
    return 0;
}
