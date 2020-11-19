//建立循环链表
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int num;
    struct Node * next;
}Person;
//创建循环链表
Person* initLink(int n){
    int i=0;
    Person* head=NULL,*cyclic=NULL;
    head=(Person*)malloc(sizeof(Person));
    head->num=1;
    head->next=NULL;
    cyclic=head;
    //建立n个节点的循环链表
    for(int i=2;i<=n;i++){
        Person* body=(Person*)malloc(sizeof(Person));
        body->num=i;
        body->next=NULL;
        cyclic->next=body;
        cyclic=cyclic->next;
    }
    cyclic->next=head;//首尾相连
    return head;
}
//删去报到的人
void findAndDel(Person* head,int s,int m){
    Person* point=NULL;
    Person* tail=head;
    //找到上一个节点
    while(tail->next!=head){
        tail=tail->next;
    }
    //从头开始
    point=head;
    //找到编号为s的人
    while(point->num!=s){
        tail=point;
        point=point->next;//将point移动到下一个链表元素
    }
    //从编号为s的人开始 只有符合point->next==point时,说明处P外全出列了
    while(point->next!=point){
        int i=0;
        //从point所指的人开始报数,找到报m-1的人,方便删除
        for(i=1;i<m;i++){
            tail=point;
            point=point->next;
        }
        //此时point所指的即为要杀死的人,摘除这个节点
        tail->next=point->next;
        printf("%d " ,point->num);
        //释放空间
        free(point);
        //将point指向下一个人
        point=tail->next;
        
    }
    //最后只剩下一个人
    printf("%d ",point->num);
    free(point);
}


int main(int argc, char const *argv[])
{
    int n=0,s=1,m=0;
    Person* head=NULL;
    scanf("%d %d",&n,&m);
    head=initLink(n);
    findAndDel(head,s,m);
    return 0;
}


