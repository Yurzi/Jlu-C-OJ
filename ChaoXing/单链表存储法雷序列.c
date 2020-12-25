#include <stdio.h>
#include <malloc.h>
struct farlei_item
{
    int numerator, denominator; // 分子、分母
    struct farlei_item *next;   // 连接部分
};
typedef struct farlei_item *farleipointer;

/*  求最大公约数 */
int gcd(int x, int y){
    if (x%y==0)
    {
        return y;
    }else{
        return gcd(y,x%y);
    }
}

/*构造法雷序列,并返回序列头指针*/
farleipointer farlei(int n)
{
    int i, j;
    farleipointer fn, r, r0, p;
    fn = r = r0 = p = NULL;
    if (n < 1)
        return NULL;                                        //如果n<=0,则没有法雷序列
    fn = (farleipointer)malloc(sizeof(struct farlei_item)); //构造0/1
    fn->numerator = 0;
    fn->denominator = 1;
    p = (farleipointer)malloc(sizeof(struct farlei_item)); //构造1/1
    p->numerator = 1;
    p->denominator = 1;
    fn->next = p;
    p->next = NULL;

    //生成分数
    for (i = n; i > 1; i--)
    {
        for (j = 0; j<=i; j++)
        {
            if (gcd(j,i)==1)
            {
                //生成节点
                r=(farleipointer)malloc(sizeof(struct farlei_item));
                r->numerator=j;
                r->denominator=i;

                //插入节点
                //遍历链表找到合适位置
                r0=fn;
                while (r0!=NULL&&r0->next!=NULL)
                {
                    if (((double)r->numerator/r->denominator)<((double)r0->next->numerator/r0->next->denominator))
                    {
                        //插入r到r0.next之前
                        r->next=r0->next;
                        r0->next=r;
                        break;
                    }
                    r0=r0->next;
                }
            }
        }     
    }
    
    return fn;
}
//输出fn引导的法雷序列
void print(farleipointer fn)
{   
    farleipointer p = fn;
    while (1)
    {
        printf("%d/%d",p->numerator,p->denominator);
        p = p->next;
        if (p == NULL)
            break;
        printf(" ");
    }
}
//释放单链表空间,head是单链表首结点指针
void release(farleipointer head) 
{ //释放单链表空间,head是指向单链表首结点的指针

    farleipointer p = head;
    farleipointer tmp = NULL;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}
int main(void)
{
    int n;
    farleipointer fn;
    scanf("%d", &n);
    fn = farlei(n); //生成n级法雷序列
    if (fn != NULL)
        print(fn);
    else
        printf("NULL");
    release(fn);
    return 0;
}