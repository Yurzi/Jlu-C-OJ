#include<stdio.h>
int main()
{
    int key=3;
    float a[key];

    for(int i=0;i<key;i++){
        scanf("%f",&a[i]);
        getchar();
    }

    //进行排序（冒泡排序）
    //逐一遍历每个元素
    for (int i = 0; i < key; i++)
    { 
        // 将每一个数与后一个数比较
        for (int j = i+1; j < key; j++)
        {
            //如果a[i]大于于a[j]则互换
            if (a[i]>a[j])
            {
                float temp=0;
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
            
        }

    }
    //输出数组
    for (int i = 0; i<key; i++)
    {
        printf("%.1f ",a[i]);
    }
    return 0;
}
