#include<stdio.h>
#include<math.h>
//判断自然数的位数
int toknowKeys(int n){
    int flag=1;
    int i=0;
    while (flag)
    {
        if (n/pow(10,i)<10)
        {
            return i+1;
        }else
        {
            i++;
        }
    }
}
//判断是否为降序数
int isDescending(int a[],int keys){
    int flag=0;
    for ( int i = 0; i<keys-1; i++)
    {
        //printf("%d ",a[i]);
        if (a[i]>=a[i+1])
        {
            //printf("哈");
            flag=1;
        }else
        {
        flag=0;
        break;
        }
    }
    //printf("%d",a[keys-1]);
    /*if (a[keys-2]>=a[keys-1])
    {
        flag=1;
    }*/
    
    return flag;
}
//计算乘方
int intpow(int x,int y){
    int sum=1;
    for (int i = 0; i < y; i++)
    {
        sum=sum*x;
    }
    return sum;
    
}


int main(int argc, char const *argv[])
{
    int keys=0;
    int n=0;
    //输入自然数
    scanf("%d",&n);
    //获取自然数位数
    keys=toknowKeys(n);
    //printf("自然数位数:%d",keys);
    //生成一个数组
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
         
        //printf("%d %d ",k,i);
        //printf("%d\n",n);
    }
    
    //输出数组
    /*for (int i = 0; i<keys; i++)
    {
        printf("%d ",arr[i]);
    }*/
    //printf("\n");
    
    //判断并输出
    int flag=isDescending(arr,keys);
    if (flag)
    {
        printf("YES");
    }else
    {
        printf("NO");
    }    
    return 0;
}
