#include<stdio.h>
int main(int argc, char const *argv[])
{
    float c=0;
    float temp1,temp2;
    float f=0;
    scanf("%f",&c);
    temp1=c*9;
    temp2=temp1/5;

    f=temp2+(float)32;

    printf("%.3f",f);

    return 0;
}

