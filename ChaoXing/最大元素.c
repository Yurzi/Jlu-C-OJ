#include<stdio.h>
#define N 128

int toFindMAX(int*,int);

int main(int argc, char const *argv[])
{
    int n=0;
    int arr[N]={0};
    int res=0;

    //输入
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        getchar();
    }

    //处理
    res=toFindMAX(arr,n);

    //输出
    printf("%d",res);

    return 0;
}

int toFindMAX(int* arr,int n){
    if (n==0)
    {
        return *arr;
    }
    int max=*arr;
    int temp=toFindMAX(arr+1,n-1);

    if (max<temp)
    {
        max=temp;
    }

    return max;
    
}