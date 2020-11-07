//公式累加
#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    //定义变量
    const double eps=0.00001; //偏移值
    double x=0; 
    double result=0; //存放结果
    double temp=0; //中间变量
    int k=2; //用于阶乘
    
    //读入x
    scanf("%lf",&x);
    
    temp=x;
    //循环累加
    while (fabs(temp)>=eps)
    {   
        result=result+temp;
        temp=temp*x*x;
        temp=temp/((double)k*(k+1.00));
        k=k+2;
    }
    
    //输出
    printf("%.6lf",result);

    return 0;
}
