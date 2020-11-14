#include<stdio.h>
#define N 10
//转置
/*void toTranspose(int arr[],int n){
    int temp=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i=j)continue;
            temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
}*/
int main(int argc, char const *argv[])
{
    int n=0;
    int arr[N][N]={0};
    //输入
    scanf("%d",&n);
    //输入数组
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            getchar();
        }
        //getchar();
    }
    //检验
    int temp=0;
    int flag=1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j)continue;
            if (arr[i][j]!=arr[j][i]){
                flag=0;
                break;
            }
        }
        if(flag==0){break;}
    }
    //输出
    if(flag){
        printf("YES");
    }else if(!flag){
        printf("NO");
    }
    return 0;
}
