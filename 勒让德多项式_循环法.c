#include<stdio.h>
int main(int argc, char const *argv[])
{
    float x=0,p0=1,p1=0,pn=0;
    int n=0;
    //输入
    scanf("%f %d",&x,&n);
    p1=x;

    if(n==0){
        printf("%.2f",1.00);
    }else if (n==1)
    {
        printf("%.2f",x);
    }else if (n>1)
    {
        for (int i = 2; i <=n; i++)
        {
            pn=((float)(2*i-1)/i)*x*p1-((float)(i-1)/i)*p0;
            p0=p1;
            p1=pn;
        }     
        printf("%.2f",pn);    
    }

    return 0;
}
