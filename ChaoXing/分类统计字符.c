#include<stdio.h>
#include<string.h>
#define N 1024
int main(int argc, char const *argv[])
{
    //定义字符串
    char str[N]={0};
    //定义计数器
    int n=0;
    int a=0,b=0,c=0,d=0,e=0;
    //读入字符串
    gets(str);
    //获取长度
    n=strlen(str);

    for (int i = 0; i < n; i++)
    {
        if ((str[i]>='A')&&(str[i]<='Z'))
        {
            ++a;
        }
        else if ((str[i]>='a')&&(str[i]<='z'))
        {
            ++b;
        }
        else if (str[i]==' ')
        {
            ++c;
        }
        else if ((str[i]>='0')&&(str[i]<='9'))
        {
            ++d;
        }else
        {
            ++e;
        }        
    }
    printf("%d %d %d %d %d",a,b,c,d,e);
    return 0;
}
