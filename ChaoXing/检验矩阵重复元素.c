#include<stdio.h>
#define N 100
//查重
int isRepeated(int* arr,int n){
    int flag =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                flag=1;
                break;
            }
        }
        if(flag){break;}
    }
    return flag;
}
int main(int argc, char const *argv[])
{
    int arr[N]={0}; //初始化数组
    int n=0;
    int total=0;
    int flag=0;

    //输入
    scanf("%d", &n);
    total=n*n;
    //输入数组
    for(int i=0;i<total;i++){
        scanf("%d",&arr[i]);
        getchar();
    }
    flag=isRepeated(arr,total);
    //输出
    if(flag){
        printf("YES");
    }else if(!flag){
        printf("NO");
    }


    return 0;
}
