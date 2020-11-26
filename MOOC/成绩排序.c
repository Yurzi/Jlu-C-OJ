#include<stdio.h>
#define N 50
#define L 20

//定义学生类
typedef struct 
{
    char name[L];
    int mark;
    
}Student;

//冒泡排序
void BubbleSort(Student arr[],int n){
    int flag=1;//标识是否进行交换
    Student t;
    while(flag){
        flag=0;//默认不存在交换 并扫描一次
        //扫描
        for(int i=0;i<n-1;i++){
            if(arr[i].mark<arr[i+1].mark)//如果前项大于后项怎后移
            {   
                //交换
                t=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=t;
                //标记存在交换
                flag=1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{   
    Student arr[N]; //定义学生数组
    int n=0;    //学生数量
    //输入人数
    scanf("%d",&n);
    //输入学生成绩信息
    for (int i = 0; i < n; i++)//学生遍历
    {
        scanf("%s %d",&arr[i].name,&arr[i].mark);
        getchar();
    }

    //排序
    BubbleSort(arr,n);


    //输出
    for (int i = 0; i < n; i++)
    {
        printf("%s %d",arr[i].name,arr[i].mark);
        if (i<n-1)
        {
            printf("\n");
        }
    }
    return 0;
}

