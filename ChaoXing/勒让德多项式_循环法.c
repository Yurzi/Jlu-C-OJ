#include<stdio.h>
int main(int argc, char const *argv[])
{
    double x=0,p0=1,p1=0,pn=0;
    int n=0;
    //输入
    scanf("%lf %d",&x,&n);
    p1=x;

    if(n==0){
        printf("%.2lf",1.00);
    }else if (n==1)
    {
        printf("%.2lf",x);
    }else if (n>1)
    {
        for (int i = 2; i <=n; i++)
        {
            pn=((double)(2*i-1)/i)*x*p1-((double)(i-1)/i)*p0;
            p0=p1;
            p1=pn;
        }     
        printf("%.2lf",pn);    
    }

    return 0;
}
