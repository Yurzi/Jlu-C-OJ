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

//寻找链表中间位置结点地址并返回，head是单链表首结点指针    
List* mid(List* head) {
    int n=0;//记录链表总长
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

    int k=(n+1)/2;
    List* half=head;
    for (int i = 1; i < k; i++)
    {
        half=half->next;
    }

    return half;
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
    List *head,*half;
    head = build();
    half=mid(head);
    if (half != NULL)
        print(half);
    else
        printf("NULL");
    release(head);
}
