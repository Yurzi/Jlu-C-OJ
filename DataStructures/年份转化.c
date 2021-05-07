#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n=0,m=0;;
    scanf("%d",&n);
    if(n<100001){
        if(n<2201){
            n=200000+n;
        }else if (n>=2201)
        {
            n=190000+n;
        }
    }
    m+=n%10;
    n=n/10;
    m+=10*(n%10);
    n=n/10;
    printf("%d-%0.2d",n,m);

}
