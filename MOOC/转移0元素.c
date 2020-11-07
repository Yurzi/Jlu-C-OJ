#include<stdio.h>
int main()
{
    int key=10;
    int a[key],b[key];
    int temp=0;
    for(int i=0;i<key;i++){
        scanf("%d",&a[i]);
        getchar();
    }
    //初始化数组b
    for (size_t i = 0; i < key; i++)
    {
        b[i]=0;
    }
    
    //进行排序
    //逐一遍历每个元素
    int j=0;
    for (int i = 0; i < key; i++)
    {
        if (a[i]!=0)
        {
            b[j]=a[i];
            j++;
        }
        
    }
    
    //输出数组
    for (int i = 0; i<key; i++)
    {
        printf("%d",b[i]);
    }
    return 0;
}
