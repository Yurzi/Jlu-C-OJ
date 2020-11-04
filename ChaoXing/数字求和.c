#include<stdio.h>
int main(int argc, char const *argv[])
{   
    //定义变量
    int sum=0,i=0;
    int a[5],n;
    //输入
    scanf("%d %d %d %d %d %d",&n,&a[0],&a[1],&a[2],&a[3],&a[4]);
    //判断并求和
    while (i<5)
    {
        if (a[i]%n==0)
        {
            sum=sum+a[i];
        }
        
        i++;
    }

    //输出
    printf("%d",sum);
    
    return 0;
}
