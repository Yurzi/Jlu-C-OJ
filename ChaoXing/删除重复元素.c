#include<stdio.h>
#define N 100

//删除重复元素
int toDelRepition(int* arr, int n){
    int total=n;
    int j=1;int flag=1;
    int point=0;
    for(int i=0;i<total;i++)//遍历每个元素
    {   point=i+1;
        while(flag&&point<total){
            if (arr[i]==arr[point]){
            //删去元素 向前移动数组 指针不动
            for(int l=point;l<total-1;l++){
                    arr[l]=arr[l+1];
            }
            total-=1;
            }else{
                point++;
            }
        }
    }
    return total;
}
//输出数组
void display(int* arr, int n){
    for(int i=0;i<n;i++){
            printf("%d",arr[i]);
        if(i<n-1){
            printf(" ");
        }
    }
}

int main(int argc, char const *argv[])
{
    int n=0;
    int arr[N]={0};
    char temp[N]={0};

    //输入
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        //temp[i]=(char)arr[i];
        getchar();
    }


    n=toDelRepition(arr,n);
    display(arr,n);

    
    return 0;
}
