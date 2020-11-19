#include<stdio.h>
#define N 10
int main(int argc, char const *argv[])
{
    int arr[N];

    //输入
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        getchar();
    }

    //输出
    for (int i = N-1; i>=0; i--)
    {
        printf("%d",arr[i]);
        if (i>0)
        {
            printf(" ");
        }
        
        
    }

    return 0;
}
