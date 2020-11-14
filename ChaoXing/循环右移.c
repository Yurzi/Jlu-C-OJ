#include <stdio.h>
int main()
{
    int key;
    int a[100], b[100];
    int temp = 0;
    int j = 0; //偏移量
    scanf("%d %d",&key,&j);
    for (int i = 0; i < key; i++)
    {
        scanf("%d", &a[i]);
        getchar();
    }

    j=j%key;
    //进行排序
    //逐一遍历每个元素
    for (int k = 0; k < j; k++)
    {

        temp = a[key - 1];
        for (int i = key - 1; i >= 0; i--)
        {
            if (i >= 1)
            {
                a[i] = a[i - 1];
            }
            else
            {
                a[i] = temp;
            }
        }
    }
    //输出数组
    for (int i = 0; i < key; i++)
    {
        printf("%d", a[i]);
        if (i<key-1){
            printf(" ");
        }
    }
    return 0;
}
