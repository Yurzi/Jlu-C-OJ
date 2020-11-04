#include<stdio.h>
//定义嵌套函数
float function(float x,int n){
    if (n>0)
    {
        x=1+1/x;
        return function(x,n-1);
    }else
    {
        return x;
    }
}

int main(int argc, char const *argv[])
{
    int n=5;
    float x=0;

    //输入
    scanf("%f",&x);
    //计算
    x=function(x,n);
    //输出
    printf("%.3f",x);
    
    return 0;
}
