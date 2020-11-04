#include<stdio.h>
#include<math.h>
//累乘
long long Factorial(long n){
    long long result=1;
    for (long i = 1; i <=n; i++)
    {
        result=result*i;
    }
    return result;
}
//计算每项
    double getUnit(double x,int n){
    double result=0;
    if (n==1)
    {
        result=x;
    }else 
    {
    result=pow(x,(2*n-1))/Factorial((2*n-1));
    }
    return result;
}

int main(int argc, char const *argv[])
{
    double eps=0.00001;
    double x=0;//x的值
    double result=0;
    //输入
    scanf("%lf",&x);
    //循环相加
    long long i=1;//循环起点
    double temp=0;
    while (1)
    {
        temp=getUnit(x,i);    
        if (temp>0)
        {  
            if (temp<eps)
        {
            break;
        }
        
        }else if (temp<0)
        {
            if (-temp<-eps)
        {
            break;
        }
            temp=-temp;
        }
        
        result=result+temp;
        i++;
        
    }
    
    //输出
    printf("%.6lf",result);
    return 0;
}
