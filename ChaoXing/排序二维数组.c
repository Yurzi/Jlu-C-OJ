#include<stdio.h>
#define N 512

//冒泡排序
void BubbleSort(int arr[],int n){
    int flag=1;//标识是否进行交换
    int t=0;
    while(flag){
        flag=0;//默认不存在交换 并扫描一次
        //扫描
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1])//如果前项大于后项怎后移
            {   
                //交换
                t=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=t;
                //标记存在交换
                flag=1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int m=0,n=0;
    int arr[N];
    
    scanf("%d %d",&m,&n);
    //输入数组
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i*n+j]);
            getchar();
        }        
    }

    //排序
    BubbleSort(arr,m*n);

    //输出
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d",arr[i*n+j]);
            if (j<n-1)
            {
                printf(" ");
            }
        }
        if (i<m-1)
        {
            printf("\n");
        }
    }
    
    return 0;
}
