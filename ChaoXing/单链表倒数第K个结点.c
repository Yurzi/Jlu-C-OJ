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

//求链表倒数第k个结点，head是单链表首结点指针
List* back(List* head, int k) {
    if (k==0)
    {
        return NULL;
    }
    
    int n=0;//统计有多少节点
    List* p=head;
    while (p!=NULL)
    {
        n++;
        if (p->next==NULL)
        {
            break;
        }
        p=p->next;
    }
    if (k>n)
    {
        return NULL;
    }
    List* res=head;
    for (int i = 0; i <n-k; i++)
    {
        res=res->next;
    }
    return res;
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
    List *head,*result;
    head = build();
    int k=0;
    scanf("%d",&k);
    result=back(head,k);
    if (result!= NULL)
        printf("%d",result->x);
    else
        printf("NULL");
    release(head);
}
