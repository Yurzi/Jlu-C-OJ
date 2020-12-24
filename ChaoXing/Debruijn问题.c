#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//链表节点
typedef struct ListNode
{
    int var;
    struct ListNode* next;
}List;

//初始化生成循环链表,n位循环链表长度
List* initList(int n);
//打印链表
void displayList(List* head);

List* HEAD=NULL;
int n=0;

//判断是否合法
int isRigth(List* head){
    List* p=head;
    int a[n];
    int b[n];
    int flag=0;
    while (p->next!=HEAD)
    {
        List* t=p;
        for (int i = 0; i < n; i++)
        {
            a[0]=t->var;
            b[0]=t->next->var;
            if (a[0]!=b[0])
            {
                flag=1;
                break;
            }
        }
        if(!flag){
            break;
        }
        p=p->next;
    }
    return flag;
}

void toslove(List* p,int var){
    p->var=var;
    //递归出口
    if(p->next==HEAD){
        if (isRigth(HEAD))
        {
            displayList(HEAD);  
        }
        return;
    }

    toslove(p->next,var);

    toslove(p->next,!var);
    return;
}


//主函数 程序入口
int main(int argc, char const *argv[])
{
    int n=0;
    scanf("%d",&n); //输入n
    
    //创建链表
    HEAD=initList((int)powf(2,n));

    //处理
    toslove(HEAD,0);
    return 0;
}

//初始化生成循环链表,n位循环链表长度
List* initList(int n){
    if(n<=0){
        return NULL;
    }
    List* head=NULL;
    List* cyclic=NULL;
    //创建头节点
    head=(List*)malloc(sizeof(List));
    head->var=0;
    head->next=NULL;
    cyclic=head;
    
    int i=0;
    //建立节点数n的链表
    for (i = 1; i < n; i++)
    {
        List* body=(List*)malloc(sizeof(List));
        body->var=0;
        body->next=NULL;
        cyclic->next=body;
        cyclic=cyclic->next;
    }
    //首位相连
    cyclic->next=head;
    return head;
}
//打印链表
void displayList(List* head){
    List* p=head;
    while (p->next!=HEAD)
    {
        printf("%d ",p->var);
        p=p->next;
    }
    printf("\n");
}