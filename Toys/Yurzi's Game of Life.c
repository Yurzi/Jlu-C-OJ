/*
Ԫ���Զ��� ���е�ͼ��������
1 1
    --------------------> x��
    |
    |
    |
    |
    |
    v
    y��
*/

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

 //��ͼ��С
int x=0;
int y=0;

//���ô�����ɫ�ͱ��� ������ɫֵ ǰ�� ����
void SetColor(UINT uFore,UINT uBack) {
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle,uFore+uBack*0x10);
}

//ϸ���ṹ��
typedef struct cell
{
    int isLive;     //�Ƿ���
    //������ϸ������
    struct cell* up;    
    struct cell* right;
    struct cell* down;
    struct cell* left;
}Cell;

//����һ����ʽ���
Cell* init(int x,int y){
    int x_count=0;
    int y_count=0;

    //�жϺϷ�
    if (x<=0&&y<=0)
    {
        return NULL;
    }

    Cell* head=(Cell*)malloc(sizeof(Cell));    //��ͷ
    head->up=head->right=head->down=head->left=NULL;
    head->isLive=0;
    x_count++;  //��һ�м�һ

    Cell* now=head; //��ǰ�ڵ�
    Cell* before=now;   //��ǰ�ڵ�ǰһ�ڵ�
    Cell* firstOfLine=head;
    Cell* preLine=firstOfLine; //��һ�е�ָ��
    
    int isFirst=0; //�Ƿ�Ϊ���е�һ��
    int isFirstLine=1;  //�Ƿ�Ϊ��һ��
    
    //��ѭ��
    while (y_count<y)
    {
        //��ѭ��
        while (x_count<x)
        {
            now=(Cell*)malloc(sizeof(Cell));    //����һ���µĽڵ�
            now->up=now->right=now->down=now->left=NULL;
            now->isLive=0;
            //��ͬ�нڵ�����
            if(!isFirst){
                before->right=now;
                now->left=before;
            }else{
                firstOfLine=now;
                isFirst=0;  //��ʱ���Ǹ��е�һ���ڵ�
            }
            //�ƶ�ָ��
            before=now;
            
            //����ͬ�ж�Ӧ�ڵ�����
            if(!isFirstLine){
                preLine->down=now;
                now->up=preLine;
                //�ƶ���һ�е�ָ��ʹ֮����һ��Ǳ�ڽڵ����
                preLine=preLine->right;
            }
            x_count++;  //�м�����һ
        }
        isFirst=1;  //һ�н�������ʱ���������
        if(isFirstLine)isFirstLine=0;//������һ�к����б���÷�
        preLine=firstOfLine;
        x_count=0;  //��������
        y_count++;  //�м�����һ
    }

    return head;
}

//�ж�ϸ������
int changLive(Cell* cell){
    //������Χ��ϸ��
    int live_count=0;
    if(cell->right!=NULL){
        live_count+=cell->right->isLive;
        if(cell->right->up!=NULL)live_count+=cell->right->up->isLive;
        if(cell->right->down!=NULL)live_count+=cell->right->down->isLive;
    }
    if(cell->down!=NULL)live_count+=cell->down->isLive;
    if(cell->left!=NULL){
        live_count+=cell->left->isLive;
        if(cell->left->up!=NULL)live_count+=cell->left->up->isLive;
        if(cell->left->down!=NULL)live_count+=cell->left->down->isLive;
    }
    if(cell->up!=NULL)live_count+=cell->up->isLive;
    //�ж�����
    if (cell->isLive)
    {
        if(live_count<2)return 0;
        if(live_count>=2&&live_count<=3)return 1;
        if(live_count>3)return 0;
    }else{
        if (live_count==3)return 1;        
    }
    return 0;
}

//ȷ����һ�ű�״̬
void toDecideNextMap(Cell* nowdisplyMap,Cell* nextdisplyMap){
    Cell* nowMapHead=nowdisplyMap;
    Cell* nextMapHead=nextdisplyMap;
    //������
    Cell* nowMapPointer=nowMapHead;
    Cell* nextMapPointer=nextMapHead;
    Cell* nowMapFirstOfLine=nowMapHead;
    Cell* nextMapFirstOfLine=nextMapHead;

    //�б���
    while (nowMapFirstOfLine!=NULL)
    {
        nowMapPointer=nowMapFirstOfLine;
        nextMapPointer=nextMapFirstOfLine;
        //�б���
        while (nowMapPointer!=NULL)
        {
            nextMapPointer->isLive=changLive(nowMapPointer);
            nowMapPointer=nowMapPointer->right;
            nextMapPointer=nextMapPointer->right;
        }
        nowMapFirstOfLine=nowMapFirstOfLine->down;
        nextMapFirstOfLine=nextMapFirstOfLine->down;
    }    
}

//�ҵ���Ӧλ�ò�����ϸ��
void findAndSet(Cell* head,int x,int y){
    Cell* pointer=head;
    //��x����ǰ���Ĳ���
    for(int i=0;i<x-1;i++){
        pointer=pointer->right;
    }
    //��y����ǰ���Ĳ���
    for (int j=0; j<y-1; j++){
        pointer=pointer->down;
    }
    pointer->isLive=1;
}

//�ж��Ƿ�ȫ������
int isAllDead(Cell* nowdisplyMap){
    int flag=1; //Ĭ��ȫ������
    Cell* firstOfLine=nowdisplyMap;
    Cell* now=firstOfLine;
    //��
    while (firstOfLine!=NULL)
    {
        now=firstOfLine;
        firstOfLine=firstOfLine->down;
        while (now!=NULL)
        {
            if (now->isLive==1)
            {
                flag=0;
                return flag;
            }         
            now=now->right;
        }
    }
    return flag;
}

//��ӡ���
void printMap(Cell* head){
    Cell* firstOfLine=head;
    Cell* now=firstOfLine;

    //��
    while (firstOfLine!=NULL)
    {
        now=firstOfLine;
        firstOfLine=firstOfLine->down;
        while (now!=NULL)
        {
            if (now->isLive)
            {
                printf("��");
            }else{
                printf("��");
            }
            now=now->right;
        }
        printf("\n");
    }

}

//���ó�ʼϸ��
void setOriginCell(Cell* nowdisplyMap){
    int x1=0;
    int y1=0;
    while(1){
        scanf("%d",&x1);
        if (x1==0)
        {
            break;
        }
        scanf(" %d",&y1);
        if (x1>x||y1>y||x1<=0||y1<=0)
        {
            printf("���������������������\n");
            continue;
        }
        findAndSet(nowdisplyMap,x1,y1);
        printMap(nowdisplyMap);
    }
}

//����
int run(Cell* nowdisplayMap,Cell* nextdisplayMap){
    char control=0;
    int autoflag=0;
    Cell* temp=NULL;
    while (1)
    {
        
        if(!autoflag){
            printf("����1��ʼ/�����ֲ�ģ�⣬����2�Զ�ģ��,����0�˳�\n");
            control=getchar();
            getchar();
            if (control=='2')
            {
                autoflag=1;
            }
            if(control=='0'){
                autoflag=3;
                break;
            }
        }
        Sleep(500);
        //ȷ����һ�ű��״̬
        toDecideNextMap(nowdisplayMap,nextdisplayMap);
        //������
        temp=nowdisplayMap;
        nowdisplayMap=nextdisplayMap;
        nextdisplayMap=temp;
        printMap(nowdisplayMap);
        printf("\n");

        //��鵱ǰ���Ƿ��д��ϸ��
        if(isAllDead(nowdisplayMap))break;
    }
    if(autoflag==3)printf("��Ϸ�������Ƿ��Ե�ǰ��ͼ��С���¿�ʼ��\n����������y����������n���˳���Ϸ\n");
    else printf("ϸ���Ѿ�ȫ���������Ƿ��Ե�ǰ��ͼ��С���¿�ʼ��\n����������y����������n���˳���Ϸ\n");
    control=getchar();
    getchar();
    if (control=='y')return 1;
    else return 0;
}

//������
int main(int argc, char const *argv[])
{
    Cell* nowdisplyMap=NULL;
    Cell* nextdisplyMap=NULL;
    
    printf("��ӭ����Ԫ���Զ���\n");
    printf("�������ͼ��С��NxM��\n");
    scanf("%d",&x);
    getchar();
    scanf("%d",&y);
    getchar();

    printf("�������ɵ�ͼ...\n");
    nowdisplyMap=init(x,y);
    nextdisplyMap=init(x,y);
    printMap(nowdisplyMap);
    //���ó�ʼϸ��
    printf("������ϣ��������ʼϸ��λ��\n��ʽ��x y������0����,��ʼ��Ϊ���Ͻ�,���� 1 1\n����Ϊx�ᣬ����Ϊy��\n");
    setOriginCell(nowdisplyMap);
    getchar();

    while (run(nowdisplyMap,nextdisplyMap))
    {
        //todo
    }
    
    printf("��Ϸ����,��л���棡");
    system("pause");
    return 0;
}