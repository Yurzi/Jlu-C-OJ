#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a=0;
    scanf("%d",&a);
    if (a>=90)
    {
        printf("A");
    }else if (a>=80)
    {
        printf("B");
    }else if (a>=70)
    {
        printf("C");
    }else if (a>=60)
    {
        printf("D");
    }else
    {
        printf("E");
    }
    
    return 0;
}

