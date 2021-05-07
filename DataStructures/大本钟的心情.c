#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[24]={0};
    int i;char flag=0;
    //读入心情
    for (i = 0; i < 24; ++i)
    {
        scanf("%d",&arr[i]);
        getchar();
    }
    while(scanf("%d",&i))
    {
        if(i<0||i>23)break;
        if(flag)printf("\n");
        if(arr[i]>50){
            printf("%d Yes",arr[i]);
        }else{
            printf("%d No",arr[i]);
        }
        flag=1;
        i=0;
    }
    return 0;
}
