#include<stdio.h>
//求出勒德多多项式
float toSolvethe(float x,int n){
    if (n==0)
    {
        return 1.00;
    }else if (n==1)
    {
        return x;
    }else if (n>1)
    {
        return (((float)(2*n-1)/n)*x*toSolvethe(x,(n-1))-((float)(n-1)/n)*toSolvethe(x,n-2));
    }  
}

int main(int argc, char const *argv[])
{
    float x,pn;
    int n;
    scanf("%f %d",&x,&n);
    if(n==0){
        printf("%.2f",1.00);
    }else if (n==1)
    {
        printf("%.2f",x);
    }else if (n>1)
    {
        pn=toSolvethe(x,n);
        printf("%.2f",pn);   
    }
    
    return 0;
}
