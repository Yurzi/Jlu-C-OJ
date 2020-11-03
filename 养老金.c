#include<stdio.h>
int main(int argc, char const *argv[])
{
    //定义变量
    int sex=0;
    int age=0;
    //输入
    scanf("%d %d",&sex,&age);
    if (sex==1)
    {
        if (age>65&&age<=70)
        {
            printf("50");
        }else if (age>70)
        {
            printf("70");
        }else
        {
            printf("NULL");
        }
        
    }else if (sex==2)
    {
        if (age>60&&age<=65)
        {
            printf("45");
        }else if (age>65)
        {
            printf("70");
        }else
        {
            printf("NULL");
        }
        
    }
    return 0;
}
