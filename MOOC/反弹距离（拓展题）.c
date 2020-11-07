//反弹距离
//注意精度应为float
#include<stdio.h>
int main(int argc, char const *argv[])
{
    //定义变量
    const double eps=0.00001;   //偏移值
    float x=0; //输入的x
    int n=0;    //输入的n
    float temp=0;  //中间变量
    float sum=0;   //总的长度
    float xn=0;    //n时的反弹高度
    int i=0;

    //输入
    scanf("%f %d",&x,&n);
    
    temp=x;

    //循环计算反弹
    while (temp>eps)
    {
        i++;    //记录第几次反弹
        sum=sum+temp;
        temp=temp/2;    
        sum=sum+temp;
        if (i==n)
        {
            xn=temp;
        }
    }

    //输出
    printf("%.6f %.6f",xn,sum);
    return 0;
}
