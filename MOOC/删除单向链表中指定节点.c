#include <stdio.h>
#include <malloc.h>

typedef struct cell
{ //单链表结点结构体定义
    int x;
    struct cell *next;
} List;

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

List* delKeyNode(List* head,int key){
    List* p=head;
    //如果头节点是所删元素
    while (head->x==key)
    {
        head=head->next;
        free(p);
        p=head;
    }
    //若不是 遍历链表
    while (p!=NULL&&p->next!=NULL)
    {
        //找到指定节点
        if (p->next->x==key)
        {
            List* t=p->next;
            p->next=t->next;
            free(t);
        }
    }
    return head; 
}

void print(List *head)
{ //打印整个单链表,head是指向单链表首结点的指针
    List *p = head;
    while (1)
    {
        printf("%d", p->x);
        p = p->next;
        if (p == NULL)
            break;
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
    int key=0;
    List *head;
    head = build();
    scanf("%d",&key);
    head=delKeyNode(head,key);
    if (head != NULL)
        print(head);
    else
        printf("NULL");
    release(head);
}
