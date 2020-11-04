#include<stdio.h>
//求出勒德多多项式
double toSolvethe(double x,int n){
    if (n==0)
    {
        return 1.00;
    }else if (n==1)
    {
        return x;
    }else if (n>1)
    {
        return (((double)(2*n-1)/n)*x*toSolvethe(x,(n-1))-((double)(n-1)/n)*toSolvethe(x,n-2));
    }  
}

int main(int argc, char const *argv[])
{
    double x,pn;
    int n;
    scanf("%lf %d",&x,&n);
    if(n==0){
        printf("%.2lf",1.00);
    }else if (n==1)
    {
        printf("%.2lf",x);
    }else if (n>1)
    {
        pn=toSolvethe(x,n);
        printf("%.2lf",pn);   
    }
    
    return 0;
}
