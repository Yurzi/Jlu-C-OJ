#include<stdio.h>
#define N 200
#define L 20
typedef struct stduent
{
    char name[L];
    int mark;
}Std;

int main(int argc, char const *argv[])
{
    //学生组
    Std arr[N];
    int n=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d",&(arr[i].name),&(arr[i].mark));
    }
    //输出
    for (int i = 0; i < n; i++)
    {
        if (arr[i].mark<60)
        {
            printf("%s",arr[i].name);
            printf(" %d",arr[i].mark);
        if (i<n-1)
        {
            putchar('\n');
        }
        }   
    }
    
    
    return 0;
}
