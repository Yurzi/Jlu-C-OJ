#include<stdio.h>
#define N 16
#define L 24
//教师类型
typedef struct teacher
{
    char name[L];
    int sex;
    int age;
}tec;

//输入
void tecIn(tec* a){
    scanf("%s %d %d",a->name,&(a->sex),&(a->age));
    getchar();
    return;
}
//输出
void tecDisp(tec* a){
    if (a->sex==0)
    {
        printf("%s Female %d ",a->name,a->age);
    }else if (a->sex==1)
    {
        printf("%s Male %d ",a->name,a->age);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n=0;
    tec arr[N];
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        tecIn(&arr[i]);
    }
    tecDisp(&arr[n/2]);
    /*
    不存只输出
    tec temp;
    int i=0;
    while (1)
    {
        tecIn(&temp);
        if (i==n/2)
        {
            tecDisp(&temp);
            break;
        }   
        i++;
    }
    */
    return 0;
}
