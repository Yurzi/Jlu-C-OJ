#include<stdio.h>
//计算
double getPI(int n){
    double PI=1;
    for (int i = 1; i <=n; i++)
    {
        PI=PI*((double)(2*i)/(2*i-1))*((double)(2*i)/(2*i+1));
    }
    return PI*2;
}
int main(int argc, char const *argv[])
{
    int n=0; //输入正整数
    //输入
    scanf("%d",&n);
    //输出
    printf("%.10lf",getPI(n));
    return 0;
}