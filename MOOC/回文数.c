#include<stdio.h>
#include<string.h>
#define N 10

int main(int argc, char const *argv[])
{
    int length=0;
    char arr[N];    //用于存储输入的数字
    //输入
    gets(arr);
    length=strlen(arr);
    int head=0;
    int tail=length-1;
    int flag=0;
    while (head<=tail)
    {
        if (arr[head]!=arr[tail])
        {
            flag=1;
            break;
        }
        head++;
        tail--;      
    }
    if (flag)
    {
        printf("NO");
    }else
    {
        printf("YES");
    }
    
    
    
    return 0;
}
