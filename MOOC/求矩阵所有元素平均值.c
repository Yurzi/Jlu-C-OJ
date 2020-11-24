#include<stdio.h>
#define N 4
int main(int argc, char const *argv[])
{
    //创建一个数组
    int arr[N*N]={0};
    //行数 列数
    int h=0,l=0;
    int* p=NULL;
    int sum=0;
    float res=0;

    //输入
    scanf("%d %d",&h,&l);
    getchar();
    for (int i = 0; i < h*l; i++)
    {
        scanf("%d",&arr[i]);
    }
    p=arr;
    for (int i = 0; i < h*l; i++)
    {
        sum=sum+*(p+i);
    }
    p=arr;

    res=(float)sum/(h*l);

    printf("%.2f ",res);
    for (int i = 0; i < h*l; i++)
    {
        printf("%d",*(p+i));
        if (i<h*l-1)
        {
            printf(" ");
        }
        
    }
    return 0;
}
