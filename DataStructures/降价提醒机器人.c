#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n=0;float m=0;
    float temp=0;
    scanf("%d %f",&n,&m);
    for (n; n>0 ; --n)
    {
        scanf("%f",&temp);
        getchar();
        if(temp<m){
            printf("On Sale! %.1f",temp);
            if(n>1)printf("\n");
        }
    }
    return 0;
}
