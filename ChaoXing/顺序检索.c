#include<stdio.h>
#define N 100

int* sequentialSearch(int*,int,int);

int main(int argc, char const *argv[])
{
    int n=0;
    int arr[N]={0};
    int key=0;
    int* res=NULL;

    //输入
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        getchar();
    }
    scanf("%d",&key);
    
    //处理
    res=sequentialSearch(arr,key,n);

    if (res==NULL)
    {
        printf("NULL");
    }else
    {
        printf("%d",res-arr);
    }
    
    return 0;
}

int* sequentialSearch(int* arr,int key,int n){
    if (n<0)
    {
        return NULL;
    }    
    if (*arr==key)
    {
        return arr;
    }else
    {
        return sequentialSearch(arr+1,key,n-1);
    }        
}
