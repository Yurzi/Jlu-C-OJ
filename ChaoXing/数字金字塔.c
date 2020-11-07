//数字金字塔
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n=0;//存放用户输入的数

    //输入
    scanf("%d",&n);

    //层循环
    for (int layer = 1; layer <= n; layer++)
    {
        //打印空格
        for (int space = 1; space<=n-layer; space++)
        {
            printf("  ");
        }

        //打印前半数字
        for (int i = 1; i <=layer; i++)
        {
            //判断是否为十或者第一个
            if (i==10)
            {
                printf(" 0");
            }else if(i==1)
            {
                printf(" %d",i);
            }else
            {
                printf(" %d",i);
            }
                
        }
        //打印后半字符
        for (int j = layer-1; j > 0; j--)
        {
            printf(" %d",j);
        }
        
        
        //换行
        if (layer<n)
        {
            printf("\n");
        }
        
    }
    
    return 0;
}
