#include<stdio.h>
//快速排序
void QuickSort(int *a, int low, int high)
{
    int i = low;
    int j = high;
    int key = a[low];
    if (low >= high)  //如果low >= high说明排序结束了
    {
        return ;
    }
    while (low < high)  //该while循环结束一次表示比较了一轮
    {
        while (low < high && key <= a[high])
        {
            --high;  //向前寻找
        }
        if (key > a[high])
        {
            a[low] = a[high];  //直接赋值, 不用交换
            ++low;
        }
        while (low < high && key >= a[low])
        {
            ++low;  //向后寻找
        }
        if (key < a[low])
        {
            a[high] = a[low];  //直接赋值, 不用交换
            --high;
        }
    }
    a[low] = key;  //查找完一轮后key值归位, 不用比较一次就互换一次。此时key值将序列分成左右两部分
    QuickSort(a, i, low-1);  //用同样的方式对分出来的左边的部分进行同上的做法
    QuickSort(a, low+1, j);  //用同样的方式对分出来的右边的部分进行同上的做法
}
//判断存在几个符合倍数
int getRightNum(int a[],int length,int n){
    //从第一个数开始
    int res=0;
    for(int i=0;i<length;i++){
        for(int j=i+1;j<length;j++){
            if(n>=1){
                if((a[i]*n)==a[j]){
                    res++;
                }
            }else if(n<1){
                if((a[j]*n)==a[i]){
                    res++;
                }
            }
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int t;  //暂存数字
    int n;  //记录倍数
    int line=0;    //记录行数
    int i=0;    //用于遍历a数组
    int flag[100]={0};  //用于存放每行的结果
    int a[100]={0}; //用于存放每行
    //输入倍数
    scanf("%d",&n);
    //输入接下的行数
    while(t!=-1){
        i=0;
        //获得一行输入
        while(1){
            scanf("%d",&a[i]);
            t=a[i];
            i++;
            if(t==0||t==-1){break;}
            getchar();
        }
        if(t==-1){break;}
        //准备 排序数组
        QuickSort(a,0,i-1);
        //获得数对数
        flag[line]=getRightNum(a,i,n);
        line++;
    }

    //输出
    for(int k=0;k<line;k++){
        printf("%d",flag[k]);
        if(k<line-1){printf("\n");}
    }
    return 0;
}
