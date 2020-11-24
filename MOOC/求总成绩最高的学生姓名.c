#include<stdio.h>
#define N 200
#define L 20
typedef struct stduent
{
    char name[L];
    int mark;
    int mark2;
}Std;

int main(int argc, char const *argv[])
{
    //学生组
    Std arr[N];
    int n=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d",&(arr[i].name),&(arr[i].mark),&(arr[i].mark2));
    }
    //输出
    Std* p=arr;
    for (int i = 0; i < n; i++)
    { 
        if (p->mark+p->mark2<arr[i].mark+arr[i].mark2)
        {
            p=&arr[i];
        }
    }

    printf("%s",p->name);
    
    
    return 0;
}
