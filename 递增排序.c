#include<stdio.h>
int main(int argc, char const *argv[])
{
    //定义变量
    float a,b,c;
    int key=3;

    //输入
    scanf("%f %f %f",&a,&b,&c);
    //定义数组
    float temp[3]={a,b,c};

    //进行排序（冒泡排序）
    //逐一遍历每个元素
    for (int i = 0; i < key; i++)
    { 
        // 将每一个数与后一个数比较
        for (int j = i+1; j < key; j++)
        {
            //如果a[i]大于于a[j]则互换
            if (temp[i]>temp[j])
            {
                float t=0;
                t=temp[j];
                temp[j]=temp[i];
                temp[i]=t;
            }
            
        }

    }
    //输出
    printf("%.1f %.1f %.1f",temp[0],temp[1],temp[2]);
    
    
    return 0;
}
