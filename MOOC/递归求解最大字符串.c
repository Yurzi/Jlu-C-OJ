#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 128
#define L 128

char* StrMax();

int main(int argc, char const *argv[])
{
    char* strP[N]={NULL};
    int n=0;
    char* res=NULL;

    //输入n
    scanf("%d",&n);
    //输入字符串
    for (int i = 0; i < n; i++)
    {
        strP[i]=(char*)malloc(sizeof(char[L]));
        scanf("%s",strP[i]);
        getchar();
    }
    //比较
    res=StrMax(strP,n);

    //打印输出
    puts(res);
    return 0;
}

char* StrMax(char* strArr[],int n){
    //将最后的字符串和前面的进行比较
    if (n==1)return strArr[0];

    char* p = StrMax(strArr, n-1);
    if (strcmp(p, strArr[n-1])>=0){
        return p;
    }else{ 
        return strArr[n-1];
    }
}
