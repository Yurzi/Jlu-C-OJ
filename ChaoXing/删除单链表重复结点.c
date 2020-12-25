#include <stdio.h>
#include <malloc.h>

typedef struct cell
{ //单链表结点结构体定义
    int x;
    struct cell *next;
}List;

List *build(void)
{ //新建单链表，并将建好的单链表首结点地址返回
    List *head, *tmp, *p;
    head = tmp = p = NULL;
    int n;
    //输入
    scanf("%d", &n);
    getchar();
    if (n == 0)
        return head;
    //头节点
    head = (List *)malloc(sizeof(List));
    p = head;
    p->x = n;
    p->next = NULL;
    while (1)
    {
        scanf("%d", &n);
        getchar();
        if (n == 0)
            break;
        tmp = (List *)malloc(sizeof(List));
        p->next = tmp;
        p = p->next;
        p->x = n;
        p->next = NULL;
    }
    return head; //返回单链表头
}

List* del2one(List* head) {//删除重复结点只保留一个，head是单链表首结点指针
    int flag=1;
    List* p=head;
    //遍历链表
    while (p!=NULL&&p->next!=NULL)
    {
        List* tmp=p;
        while (1)
        {
            if (tmp->next==NULL)break;
            if (p->x==(tmp->next)->x)
            {
                //删除tmp所指节点
                List* del=tmp->next;
                tmp->next=del->next;
                free(del);
                flag=0;
            }  
            if(flag){
                tmp=tmp->next;
            }
            flag=1;   
        }
        p=p->next;
    }
    return head;//返回删除重复结点的单链表头
}

void print(List *head)
{ //打印整个单链表,head是指向单链表首结点的指针
    List *p = head;
    while (1)
    {
        printf("%d",p->x);
        p = p->next;
        if (p == NULL)
            break;
        printf(" ");
    }
}

void release(List *head)
{ //释放单链表空间,head是指向单链表首结点的指针

    List *p = head;
    List *tmp = NULL;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

int main(void)
{
    List *head;
    head=build();
    head=del2one(head);
    if (head != NULL)
        print(head);
    else
        printf("NULL");
    release(head);
}
