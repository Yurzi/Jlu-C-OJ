#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a,b,c,d;
    int first,second;
    scanf("%d",&first);
    d=first%10;
    c=(first/10)%10;
    b=(first/100)%10;
    a=(first/1000)%10;
    second=d*1000+c*100+b*10+a;
    if (first==second)
    {
        printf("OK");
    }else
    {
        printf("NO");
    }
    return 0;
}
