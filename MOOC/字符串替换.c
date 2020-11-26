#include<stdio.h>
#include<string.h>
#define N 128
int main(int argc, char const *argv[])
{
    char str[N]={0};//定义字符串

    //输入
    gets(str);
    //遍历字符串

    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i]>='A')&&(str[i]<='Z'))
        {
            str[i]=('A'+'Z')-str[i];
        }
    }
    //输出
    puts(str);
    return 0;
}
