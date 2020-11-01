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
    int flag=1;
    for ( int i = keys-1; i>=1; i--)
    {
        if (a[i]<=a[i-1])
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
    }
    return flag;
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
    for (int i = 0; i < keys; i++)
    {
        int k=pow(10,keys-i-1);
        if (i==(keys-1))
        {
            arr[i]=n;
        }else
        {
            arr[i]=n/k;
            n=n%k;
        }
    }
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
