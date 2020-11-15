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
//快速排序
void QuickSort(int *arr, int low, int high)
{
    int i = low;
    int j = high;
    int key = arr[low];
    if (low >= high)  //如果low >= high说明排序结束了
    {
        return ;
    }
    while (low < high)  //该while循环结束一次表示比较了一轮
    {
        while (low < high && key <= arr[high])
        {
            --high;  //向前寻找
        }
        if (key > arr[high])
        {
            arr[low] = arr[high];  //直接赋值, 不用交换
            ++low;
        }
        while (low < high && key >= arr[low])
        {
            ++low;  //向后寻找
        }
        if (key < arr[low])
        {
            arr[high] = arr[low];  //直接赋值, 不用交换
            --high;
        }
    }
    arr[low] = key;  //查找完一轮后key值归位, 不用比较一次就互换一次。此时key值将序列分成左右两部分
    QuickSort(arr, i, low-1);  //用同样的方式对分出来的左边的部分进行同上的做法
    QuickSort(arr, low+1, j);  //用同样的方式对分出来的右边的部分进行同上的做法
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
    
    QuickSort(arr,0,N-1);
    toDelRepition(arr,N);


    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i<n-1){
            printf(" ");
        }
    }

    
    return 0;
}
