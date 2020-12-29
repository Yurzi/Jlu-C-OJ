#include<stdio.h>
#include<string.h>
#define N 6
#define L 1024
int main(int argc, char const *argv[])
{
    //定义一个字符串数组
    char arr[N][L]={0};
    char *key=NULL;//要对比的字符串
    int k=0;  //计数器

    //读入字符串
    for (int i = 0; i < N; i++)
    {
        scanf("%s",&arr[i]);
        getchar();//除去空格
    }
    key=arr[N-1];
    for (int i = 0; i < N-1; i++)
    {
        if(strcmp(arr[i],key)==0){
            ++k;
        }
    }

    //输出
    printf("%d",k);
    

    return 0;
}
