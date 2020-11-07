//计算e^x
#include <stdio.h>
#include<math.h>
//计算每一项的值
double unit(double x,int n){
    double sum=1;
    if (n>=1)
    {
        for (int i = 1; i <=n; i++)
        {
            sum=sum*(x/i);
        }
        return sum;
        
    }else if (n==0)
    {
        return 1;
    }
}
int main(int argc, char const *argv[])
{
    int n=100;
    double x,ex=0;
    
    scanf("%lf",&x);
    //计算序列和
    for (int i = 0; i <n; i++)
    {
        ex=ex+unit(x,i);
    }

    printf("%.2f",ex);
    
    return 0;
}