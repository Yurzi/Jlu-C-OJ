#include<stdio.h>
#define N 50

//定义学生类
typedef struct 
{
    int ch;
    int math;
    int en;
}Student;

int main(int argc, char const *argv[])
{
    Student master[2];
    for (size_t i = 0; i < 2; i++)
    {
        master[i].ch=0,master[i].en=0,master[i].math=0;
    }
    
    Student arr[N]; //定义学生数组
    int n=0;    //学生数量
    //输入人数
    scanf("%d",&n);
    //输入学生成绩信息
    for (size_t i = 0; i < n; i++)//学生遍历
    {
        scanf("%d %d %d",&arr[i].ch,&arr[i].math,&arr[i].en);
        getchar();
    }
    //求和
    for (size_t i = 0; i < n; i++)
    {
        master[0].ch+=arr[i].ch;
        master[0].math+=arr[i].math;
        master[0].en+=arr[i].en;
    }
    //求平均值
    master[1].ch+=(master[0].ch/n);
    master[1].math+=(master[0].math/n);
    master[1].en+=(master[0].en/n);

    //输出
    for (size_t i = 0; i < 2; i++)
    {
        printf("%d %d %d",master[i].ch,master[i].math,master[i].en);
        printf("\n");
    }
    


    return 0;
}

