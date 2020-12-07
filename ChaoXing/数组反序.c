#include<stdio.h>
#define N 128

void Reverse(int*,int);

int main(int argc, char const *argv[])
{
    int n=0;
    int arr[N]={0};

    //输入
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        getchar();
    }
    //处理并输出
    Reverse(arr,n);

    return 0;
}

void Reverse(int* arr,int n){
    if (n<=0)
    {
        return;
    }

    Reverse(arr+1,n-1);
    if (n==1)
    {
        printf("%d",*arr);
        return;
    }
    printf(" %d",*arr);
}
