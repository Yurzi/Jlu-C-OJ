#include<stdio.h>
#define keys 3
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
    int arr[keys];
    int n=0;

    //输入自然数
    scanf("%d",&n);

    //将输入的数每一位写入数组
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
    //输出英文字符
    //百位
    if(arr[0]>0){
        switch (arr[0]){
            case 1:printf("one ");break;
            case 2:printf("two ");break;
            case 3:printf("three ");break;
            case 4:printf("four ");break;
            case 5:printf("five ");break;
            case 6:printf("six ");break;
            case 7:printf("seven ");break;
            case 8:printf("eight ");break;
            case 9:printf("nine ");break;
        }
        if(arr[1]!=0||arr[2]!=0){
            printf("hundred and ");
        }else{
            printf("hundred");
        }
    }
    //十位
    if(arr[1]>1){
        switch (arr[1]){
            case 2:printf("twenty-");break;
            case 3:printf("thirty-");break;
            case 4:printf("forty-");break;
            case 5:printf("fifty-");break;
            case 6:printf("sixty-");break;
            case 7:printf("seventy-");break;
            case 8:printf("eighty-");break;
            case 9:printf("ninety-");break;
        }
    }else if(arr[1]==1){
        switch (arr[2]){
            case 0:printf("ten");break;
            case 1:printf("eleven");break;
            case 2:printf("twelve");break;
            case 3:printf("thirteen");break;
            case 4:printf("fourteen");break;
            case 5:printf("fifteen");break;
            case 6:printf("sixteen");break;
            case 7:printf("seventeen");break;
            case 8:printf("eighteen");break;
            case 9:printf("nineteen");break;
        }
    }
    //个位
    if(arr[1]!=1){
        switch (arr[2]){
            case 0:if(arr[0]==0&&arr[1]==0){printf("zero");}break;
            case 1:printf("one");break;
            case 2:printf("two");break;
            case 3:printf("three");break;
            case 4:printf("four");break;
            case 5:printf("five");break;
            case 6:printf("six");break;
            case 7:printf("seven");break;
            case 8:printf("eight");break;
            case 9:printf("nine");break;
        }
    }
    
    return 0;
}
