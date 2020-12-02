#include<stdio.h>
#define N 1024
//删除重复元素
int toDelRepition(int* arr, int n){
    int total=n;
    int j=1;int flag=1;
    int point=0;
    for(int i=0;i<total;i++)//遍历每个元素
    {   point=i+1;
        while(flag&&point<total){
            if (arr[i]==arr[point]){
            //删去元素 向前移动数组 指针不动
            for(int l=point;l<total-1;l++){
                    arr[l]=arr[l+1];
            }
            total-=1;
            }else{
                point++;
            }
        }
    }
    return total;
}

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
    int arr[N]={0};
    int x=1;
    int n=1;
    int i=1,j=1,point=0;
    arr[0]=x;
    //输入
    scanf("%d",&n);
    //生成数列
    while(1){
        x=arr[point];
        arr[i]=2*x+1;
        i++;
        if (i>N)break;
        arr[i]=3*x+1;
        i++;
        if (i>N)break;
        point++;
    }
    
    BubbleSort(arr,N);
    toDelRepition(arr,N);

    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i<n-1){
            printf(" ");
        }
    }
    return 0;
}
