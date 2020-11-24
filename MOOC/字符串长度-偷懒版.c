#include<string.h>
#include<stdio.h>
#define N 1024
int main(int argc, char const *argv[])
{
    char arr[N]={0};
    int res=0;
    gets(arr);
    res=strlen(arr);
    printf("%d",res);
    return 0;
}
