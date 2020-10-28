#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a,b;
    scanf("%d %d",&a,&b);
    int sum,minus,multi,quotient,mod;
    sum=a+b;
    minus=a-b;
    quotient=a/b;
    multi=a*b;
    mod=a%b;

    printf("%d %d %d %d %d",sum,minus,multi,quotient,mod);

    return 0;
}