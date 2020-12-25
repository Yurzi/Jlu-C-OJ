#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define K 16
#define N 4

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
int k=0;

//判断是否合法
int isRigth(List* head){
    List* p=head;
    char arr[K][N];
	int flag=1;
	//判断中间两两是否符合
	int q=0;
	//取遍所有可能
    while (1)
    {
        List* t=p;
        for (int i = 0; i < n; i++)
        {
            arr[q][i]=(t->var)+48;
			t=t->next;
		}
		q++;
        p=p->next;
		if(p==HEAD)break;
    }
	//判断是否有重复
	for (int i = 0; i < k; i++){
		for (int j = i+1; j < k; j++){
			int sum=0;
			for (int k = 0; k < n; k++)
			{
				sum=sum+abs(arr[i][k]-arr[j][k]);
			}
			if(sum==0){
				flag=0;
				break;
			}
		}
		if(!flag)break;
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
			exit(0);  
        }
        return;
    }

    toslove(p->next,0);

    toslove(p->next,1);
    return;
}


//主函数 程序入口
int main(int argc, char const *argv[])
{

    scanf("%d",&n); //输入n
	k=(int)powf(2,n);
	
    //创建链表
    HEAD=initList(k);

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
	printf("%d",p->var);
    printf("\n");
}