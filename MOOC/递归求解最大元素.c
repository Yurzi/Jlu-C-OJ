#include<stdio.h>
#define N 10

int* toFindMax(int arr[],int* now,int n){
    if (n>=N)
    {
        return now;
    }else if (*now<arr[n])
    {
        now=&arr[n];
        return toFindMax(arr,now,n+1);
    }else if (*now>=arr[n])
    {
        return toFindMax(arr,now,n+1);
    }
    
}


int main(int argc, char const *argv[])
{
    int arr[N];
    int* p=NULL;
    for (int i = 0; i <N ; i++)
    {
        scanf("%d",&arr[i]);
        getchar();
    }
    p=arr;
    p=toFindMax(arr,p,1);

    printf("%d",*p);
    return 0;
}
