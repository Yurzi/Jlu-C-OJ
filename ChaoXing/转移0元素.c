#include<stdio.h>
int main()
{
    int key=100;
    int a[100],b[100];
    int temp=0;
    
    scanf("%d",&key);

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
        if(i<key-1){
            printf(" ");
        }
    }
    return 0;
}
