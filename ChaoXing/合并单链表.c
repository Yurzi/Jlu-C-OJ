#include <stdio.h>
#include <malloc.h>

typedef struct cell
{ //单链表结点结构体定义
    int x;
    struct cell *next;
} List;
List *build(void)
{
    //新建单链表，并将建好的单链表首结点地址返回
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
List *combine(List *p, List *q)
{ //合并两个链表p和q
    List *head = NULL, *p0 = NULL, *q0 = NULL, *r = NULL;
    if (p == NULL && q != NULL)
        return q;
    if (p != NULL && q == NULL)
        return p;
    if (p == NULL && q == NULL)
        return NULL;

    p0 = p->next;
    q0 = q->next;
    int firstFlag=1;
    //初始化
    if (p->x <= q->x)
    {
        head = p;
        head->next = q;
    }
    else
    {
        head = q;
        head->next = p;
        firstFlag=0;
    }

    
    //插入节点
    //遍历链表找到合适位置
    while (p0 != NULL&&firstFlag)
    {
        int flag=1;
        r= head;
        while (r != NULL && r->next != NULL)
        {           
            if (p0->x<=r->next->x)
            {
                //插入r到r.next之前
                p=p0->next;
                p0->next=r->next;
                r->next=p0;
                flag=0;
                break;
            }
            r = r->next;
        }
        if (flag)
        {
            r->next=p0;
            p=p0->next;
        }
        
        if (p0->next == NULL)
            break;
        p0=p;
    }

    while (q0 != NULL&&(!firstFlag))
    {
        int flag=1;
        r= head;
        while (r != NULL && r->next != NULL)
        {           
            if (q0->x<=r->next->x)
            {
                //插入r到r.next之前
                q=q0->next;
                q0->next=r->next;
                r->next=q0;
                flag=0;
                break;
            }
            r = r->next;
        }
        if (flag)
        {
            r->next=q0;
            q=q0->next;
        }
        
        if (q0->next == NULL)
            break;
        q0=q;
    }

    return head;
}

//打印
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

//释放空间
void release(List *head)
{
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
    List *head1, *head2, *result;
    head1 = build();
    head2 = build();
    result = combine(head1, head2);
    if (result != NULL)
        print(result);
    else
        printf("NULL");
    release(result);
    return 0;
}