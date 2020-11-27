#include<stdio.h>
#define N 1024

int halfSearch(int* arr,int head,int tail,int now,int key){
    if (tail<=head)
    {
        return -1;
    }else if (arr[now]==key)
    {
        return now;
    }else if (arr[now]>key)
    {
        tail=now-1;
        now=(tail+head)/2;
        return(arr,head,tail,now,key);
    }else if (arr[now]<key)
    {
        head=now+1;
        now=(head+tail)/2;
        return(arr,head,tail,now,key);
    }
}

int main(int argc, char const *argv[])
{
    int n=0;
    int arr[N]={0};
    int key=0;
    int p=0;

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        getchar();
    }
    scanf("%d",&key);

    p=halfSearch(arr,0,n-1,(n-1)/2,key);

    printf("%d",p);

    return 0;
}
