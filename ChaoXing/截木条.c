#include<stdio.h>

int res=0;//全局变量用于记录木条根数

void cutBranch(int,int);

int main(int argc, char const *argv[])
{
    int n=0;
    int k=0;

    //输入
    scanf("%d %d",&n,&k);

    //处理
    cutBranch(n,k);

    //输出
    printf("%d",res);


    return 0;
}

void cutBranch(int n,int k){

    if (n<=k)
    {
        res=res+1;
        return;
    }
    if (n>k)
    {
        int n1=(int)(((float)(n*2)/5)+0.5); //进行四舍五入
        cutBranch(n1,k);
        cutBranch(n-n1,k);
        return;
    } 
    return;
}
