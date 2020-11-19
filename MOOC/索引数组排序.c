#include<stdio.h>
#define N 5

//冒泡排序
void BubbleSort();
//建立结构体n
typedef struct unit
{
    int num;
    int var;

}Unit;
int main(int argc, char const *argv[])
{
    //定义结构数组
    Unit arr[N];

    //初始化数组
    for(int i=0;i<N;i++){
        arr[i].num=i;
        arr[i].var=0;
    }
     //输入数组
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i].var);
        getchar();
    }

    //输出值
    for (int i = 0; i < N; i++)
    {   
        printf("%d",arr[i].var);
    }
    //换行
    printf("\n");

    //排序
    BubbleSort(arr,N);

    //输出序号
    for (int i = 0; i < N; i++)
    {   
        printf("%d",arr[i].num);
    }

    return 0;
}
void BubbleSort(Unit arr[],int n){
    int flag=1;//标识是否进行交换
    Unit t1;
    while(flag){
        flag=0;//默认不存在交换 并扫描一次
        //扫描
        for(int i=0;i<n-1;i++){
            if(arr[i].var>arr[i+1].var)//如果前项大于后项怎后移
            {   
                //交换数值与记号
                t1=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=t1;

                //标记存在交换
                flag=1;
            }
        }
    }
}