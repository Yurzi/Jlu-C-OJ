#include<stdio.h>
#define N 50
#define L 20

//定义学生类
typedef struct 
{
    char name[L];
    int math;
    int en;
    int total;
    
}Student;

int main(int argc, char const *argv[])
{   
    Student arr[N]; //定义学生数组
    int n=0;    //学生数量
    //输入人数
    scanf("%d",&n);
    //输入学生成绩信息
    for (int i = 0; i < n; i++)//学生遍历
    {
        scanf("%s %d %d",&arr[i].name,&arr[i].math,&arr[i].en);
        arr[i].total=arr[i].en+arr[i].math;
        getchar();
    }
    //输出
    for (int i = 0; i < n; i++)
    {
        printf("%s %d",arr[i].name,arr[i].total);
        if (i<n-1)
        {
            printf("\n");
        }
    }

    return 0;
}

