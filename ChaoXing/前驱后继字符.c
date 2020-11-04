#include<stdio.h>
int main(int argc, char const *argv[])
{
    char a,b,c;
    int temp=0;
    char In;
    scanf("%c",&In);
    temp=(int)In;
    a=temp-1;
    b=temp;
    c=temp+1;
    printf("%c%c%c",a,b,c);
    return 0;
}
