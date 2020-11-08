//超新逆序数
#include<stdio.h>
int main(int argc, char const *argv[])
{
    long long n=0;//存储输入的数
    //输入
    scanf("%lld",&n);
    //判断是否为自然数
    if(n<0){printf("NULL");return 0;}
    if (n==0) { printf("0");return 0;}
    int arr[100]; //定义数组存放每一位数
    //将每一位数放进数组
    int i=0;
    while(1){
        if(n==0)break;
        arr[i]=n%10;
        n=n/10;
        i++;
    }
    //输出
    int flag = 1;
    for(int j=0;j<i;j++){
        if(flag){
            if(arr[j]!=0){
                printf("%d",arr[j]);
                flag=0;
            }
        }else{
            printf("%d",arr[j]);
        }
    }
    return 0;
}
