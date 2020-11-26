#include<stdio.h>
#include<string.h>
#define L 512
#define N 64
typedef struct student
{
    char name[L];
}Std;
//冒泡排序
void BubbleSort(Std  arr[],int n){
    int flag=1;//标识是否进行交换
    Std t;
    while(flag){
        flag=0;//默认不存在交换 并扫描一次
        //扫描
        for(int i=0;i<n-1;i++){
            if(strcmp(arr[i].name,arr[i+1].name)>0)//如果前项大于后项怎后移
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
    int n=0;
    Std arr[N];
    char temp[L];
    //输入
    scanf("%d",&n);
    getchar();

    for (int i = 0; i <n; i++)
    {
        gets(arr[i].name);    
    }
    //排序
    BubbleSort(arr,n);
    //输出
    for (int i = 0; i < n; i++)
    {
        printf("%s",arr[i].name);
        if (i<n-1)
        {
            printf("\n");
        }
        
    }
    return 0;
}
