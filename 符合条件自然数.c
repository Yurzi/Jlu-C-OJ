#include<stdio.h>
//寻找小于且能被整除的数
int main(int argc, char const *argv[])
{
    //定义变量
    int key=11; //除数
    int date=0; //被除数
    int temp[1000];  //用作缓存
    int n=0;
    //输入
    scanf("%d",&date);
    //寻找小于且能被整除的数
    for (int i = 0; i < date; i++)
    {
        if (i%key==0)
        {
            temp[n]=i;
            n++;
        }
    }

    //输出
    for (int i = 0; i <n; i++)
    {
        if (i==(n-1))
        {
            printf("%d",temp[i]);
        }else
        {
            printf("%d ",temp[i]);
        }
    }
    
    return 0;
}
