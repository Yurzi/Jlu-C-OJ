#include<stdio.h>
#define false 0
#define true 1
int main(int argc, char const *argv[])
{
    int flag1=false,flag2=false,flag3=false;    //用于标记
    int n;
    //输入
    scanf("%d",&n);
    //判断整除与否
    if (n%3==0)
    {
        flag1=true;
    }
    if (n%5==0)
    {
        flag2=true;
    }
    if (n%7==0)
    {
        flag3=true;
    }    
    
    //输出
    if (flag1)
    {
        if (flag1&&(!flag2)&&(!flag3))
        {
            printf("3");
        }else
        {
            printf("3,");
        }
    }
    if (flag2)
    {
        if ((!flag1)&&(flag2)&&(!flag3))
        {
            printf("5");
        }else if ((flag1)&&(flag2)&&(!flag3))
        {
            printf("5");
        }
        else
        {
            printf("5,");
        }
    }
    if (flag3)
    {
        printf("7");
    }
    if ((!flag1)&&(!flag2)&&(!flag3))
    {
        printf("NULL");
    }
    
    
    
    return 0;
}
