#include<stdio.h>
//计算乘方
int intpow(int x,int y){
    int sum=1;
    for (int i = 0; i < y; i++)
    {
        sum=sum*x;
    }
    return sum;
    
}
//判断自然数的位数
int toknowKeys(int n){
    int flag=1;
    int i=0;
    while (flag)
    {
        if (n/intpow(10,i)<10)
        {
            return i+1;
        }else
        {
            i++;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n=0,keys=0;

    scanf("%d",&n);
    keys=toknowKeys(n);

    if (keys!=4)
    {
        printf("0");
        return 0;
    }
    //获取自然数的位数并生成一个数组
    keys=toknowKeys(n);
    int arr[keys];
    //将自然数的每一位写入数组
    for (int i = 0; i <keys; i++)
    {
        int k=intpow(10,keys-i-1);
        if (i==keys-1)
        {
            arr[i]=n;
        }else
        {
            arr[i]=n/k;
            n=n%k;
        }
    }
    //反向输出
    for (int j = keys-1; j >= 0; j--)
    {
        printf("%d",arr[j]);
    }
    

    return 0;
}
