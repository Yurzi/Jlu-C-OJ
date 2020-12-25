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
//交换索引为m和n的两个结点，head是单链表首结点指针
List* swap(List* head,int m,int n) {

    if(head==NULL) return NULL;
    List* pm=head, *pn=head;
    List* pm0 = NULL, *pn0 = NULL;
    List* tmp;

    int i;
    for (i = 1;i < m && pm != NULL;i++) { 
    pm0 = pm;
    pm = pm->next;
    }
    for (i = 1;i < n && pn != NULL;i++) {
    pn0 = pn;
    pn = pn->next;
    }
    //索引为m,n的结点位于链表中间
    if (pm != NULL && pn != NULL && m != n) {

        //均不在头尾
        if (pm0 != NULL && pn0 != NULL) {
            tmp=pm->next;
            pm->next=pn->next;
            pn->next=tmp;
            pm0->next=pn;
            pn0->next=pm;
        }
        //m在头
        else if (pm0 == NULL && pn0 != NULL) {
            tmp=pn->next;
            pn->next=pm->next;
            head=pn;
            pn0->next=pm;
            pm->next=tmp;
        }
        //n在头
        else if (pm0 != NULL && pn0 == NULL) {
            tmp=pm->next;
            pm->next=pn->next;
            head=pm;
            pm0->next=pn;
            pn->next=tmp;
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
    int m=0,n=0;
    head = build();
    scanf("%d %d", &m, &n);
    head = swap(head,m,n);
    if (head != NULL)
        print(head);
    else
        printf("NULL");
    release(head);
}
