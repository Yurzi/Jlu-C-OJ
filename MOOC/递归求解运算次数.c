#include<stdio.h>
#include<stdlib.h>

void JGFun(int InData,int *Nums){
    if (InData==1)
    {
        printf("1\n");
        printf("%d",*Nums);
        return;
    }
    if (InData%2==0)
    {
        printf("%d(除2)->",InData);
        InData=InData/2;
        *Nums=*Nums+1;
    
        return JGFun(InData,Nums);     
    }else
    {
        printf("%d(乘3加1)->",InData);
        InData=InData*3+1;
        *Nums=*Nums+1;

        return JGFun(InData,Nums);
    }
    
}

int main(int argc, char const *argv[])
{
    int n=0;
    int* Nums=(int*)malloc(sizeof(int));
    *Nums=0;
    //输入
    scanf("%d",&n);

    //进行计数
    JGFun(n,Nums);
    return 0;
}
