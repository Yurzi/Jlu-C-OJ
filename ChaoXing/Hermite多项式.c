#include<stdio.h>

double Hermite(double x,int n){
    if (n==0)
    {
        return 1;
    }else if (n==1)
    {
        return 2*x;
    }else if (n>1)
    {
        return (2*x*Hermite(x,n-1)-2*(n-1)*Hermite(x,n-2));
    }
    
}

int main(int argc, char const *argv[])
{
    int n=0;
    double x=0;
    double res=0;

    scanf("%d %lf",&n,&x);

    res=Hermite(x,n);

    printf("%.2lf",res);


    return 0;
}
