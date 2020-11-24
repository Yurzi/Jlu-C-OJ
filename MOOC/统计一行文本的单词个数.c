#include<stdio.h>
#include<string.h>
#define N 128
int main(int argc, char const *argv[])
{
    char arr[N]={0};
    gets(arr);
    int flag=0;//标记有效空格
    int k=1;
    if (arr[0]==0||arr[0]==' ')
    {
        k=0;
    }
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i]!=' ')
        {
            flag=1;//有效化
        }
        
        if (arr[i]==' '&&flag)
        {
            ++k;
            flag=0;
        }
    }
    
    printf("%d",k);
    
    return 0;
}
