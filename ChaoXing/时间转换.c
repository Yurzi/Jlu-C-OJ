#include<stdio.h>
int main(int argc, char const *argv[])
{
    long Ins;
    long s,m,h;
    long temp1,temp2,temp3;
    //输入
    scanf("%li",&Ins);
    
    //计算
    
    h=Ins/3600;
    m=(Ins%3600)/60;
    s=Ins-3600*h-60*m;
    if (Ins>86400);
    {
        temp3=Ins/86400;
        h=h-24*temp3;
    }
    
    //输出
    if (h<=9)
    {
        if (m<=9)
        {
            if (s<=9)
            {
                printf("0%li:0%li:0%li",h,m,s);
            }else
            {
                printf("0%li:0%li:%li",h,m,s);
            }
        }else
        {
            if (s<=9)
            {
                printf("0%li:%li:0%li",h,m,s);
            }else
            {
                printf("0%li:%li:%li",h,m,s);
            }   
        }
    }else
    {
         if (m<=9)
        {
            if (s<=9)
            {
                printf("%li:0%li:0%li",h,m,s);
            }else
            {
                printf("%li:0%li:%li",h,m,s);
            }
        }else
        {
            if (s<=9)
            {
                printf("%li:%li:0%li",h,m,s);
            }else
            {
                printf("%li:%li:%li",h,m,s);
            }
        }
        
    }
    return 0;
}
