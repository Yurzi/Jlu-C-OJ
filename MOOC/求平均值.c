#include<stdio.h>
int main(int argc, char const *argv[])
{
    float In1,In2,In3,averges;
    scanf("%f %f %f",&In1,&In2,&In3);
    averges=(In1+In2+In3)/3;
    printf("%.3f",averges);
    return 0;
}
