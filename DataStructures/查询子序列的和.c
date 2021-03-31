#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

int main(int argc, char const *argv[])
{
    int n = 0; //整数的个数
    int q = 0; //查询的次数
    int i = 0; //存放区间头
    int j = 0; //存放区间尾
    long temp=0; //暂存
    long res = 0;
    //读入N和Q
    scanf("%d %d",&n,&q);
    getchar();

    //创建数组
    long A[SIZE+1];
    
    //读入整数序列
    int k = 0;
    A[k++]=0;
    while (0<k<n)
    {
        scanf("%ld",&temp);
        A[k]=A[k-1]+temp;
        if(getchar()=='\n')break;
        k++;
    }
    
    //读入区间
    for(k=0;k<q;k++){
        scanf("%d %d",&i,&j);
        printf("%ld",(A[j]-A[i-1]));
        if (k<q-1)
        {
            printf("\n");
        }
    }

    return 0;
}
