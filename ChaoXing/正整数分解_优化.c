#include<stdio.h>

#define N 16

int key=0;
int sum=0;
int res[N]={0};
int length=0;

//可通过设置函数参数优化
void solution(){
    
    //排除后数大于前数
    if (length>=2)
    {
        if(res[length-2]<res[length-1])return;
    }

    if (sum==key)
    {
        //打印数组
        printf("%d=",key);
        for (int i = 0; i <length; i++)
        {
            printf("%d",res[i]);
            if (i<length-1)
            {
                printf("+");
            }
        }
        printf("\n");
        return;
    }
    if(sum>key)return;

    //展开
    for (int i =key-1; i >=1; i--)
    {
        sum=sum+i;
        res[length]=i;
        length++; 
        
        //展开下一层
        solution();

        //还原现场
        sum=sum-i;
        res[length]=0;
        length--;
    }
}


int main(int argc, char const *argv[])
{
    scanf("%d",&key);
    solution();
    return 0;
}
