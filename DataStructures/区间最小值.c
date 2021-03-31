#include<stdio.h>

#define SIZE 100002    



int main(int argc, char const *argv[])
{
    //队列
    int arr[SIZE]={0};
    int top=1;
    int rear=1;

    int n=0;    //整数的个数
    int m=0;    //区间的长度
    int num[SIZE]={0};
    int temp=0;
    //读入数据
    scanf("%d %d",&n,&m);

    //读入数据
    int k=1;
    while (k<=n)
    {
        //读入
        scanf("%d",&temp);
        num[k]=temp;
        k++;
        if(getchar()=='\n')break;
    }

    //遍历
    for (int i = 1; i <=n; i++)
    {   
        //加入队列并维持区间单调性
        if(num[i]>=num[arr[rear-1]]||top==rear){
            //入列
            arr[rear]=i;
            rear++;

        }else{
            //弹出至对空或者大于等于队尾元素
            while (top!=rear&&num[i]<num[arr[rear-1]])
            {
                rear--;
            }
            //入列
            arr[rear]=i;
            rear++;
        }

        //维护区间
        if(i>=m){
            while ((top!=rear)&&(arr[top]<(i-m+1)))
            {
                top++;
            }

            printf("%d",num[arr[top]]);
            if(i<n)printf(" ");
        }
    }
    return 0;
}