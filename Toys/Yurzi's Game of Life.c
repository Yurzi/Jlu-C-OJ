/*
元胞自动机 其中地图的坐标轴
1 1
    --------------------> x轴
    |
    |
    |
    |
    |
    v
    y轴
*/

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

 //地图大小
int x=0;
int y=0;

//设置窗口颜色和背景 输入颜色值 前景 背景
void SetColor(UINT uFore,UINT uBack) {
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle,uFore+uBack*0x10);
}

//细胞结构体
typedef struct cell
{
    int isLive;     //是否存活
    //与其他细胞链接
    struct cell* up;    
    struct cell* right;
    struct cell* down;
    struct cell* left;
}Cell;

//生成一张链式表格
Cell* init(int x,int y){
    int x_count=0;
    int y_count=0;

    //判断合法
    if (x<=0&&y<=0)
    {
        return NULL;
    }

    Cell* head=(Cell*)malloc(sizeof(Cell));    //表头
    head->up=head->right=head->down=head->left=NULL;
    head->isLive=0;
    x_count++;  //第一行加一

    Cell* now=head; //当前节点
    Cell* before=now;   //当前节点前一节点
    Cell* firstOfLine=head;
    Cell* preLine=firstOfLine; //上一行的指针
    
    int isFirst=0; //是否为该行第一个
    int isFirstLine=1;  //是否为第一行
    
    //行循环
    while (y_count<y)
    {
        //列循环
        while (x_count<x)
        {
            now=(Cell*)malloc(sizeof(Cell));    //创建一个新的节点
            now->up=now->right=now->down=now->left=NULL;
            now->isLive=0;
            //将同行节点相连
            if(!isFirst){
                before->right=now;
                now->left=before;
            }else{
                firstOfLine=now;
                isFirst=0;  //此时不是该行第一个节点
            }
            //移动指针
            before=now;
            
            //将不同行对应节点相连
            if(!isFirstLine){
                preLine->down=now;
                now->up=preLine;
                //移动上一行的指针使之与下一个潜在节点对齐
                preLine=preLine->right;
            }
            x_count++;  //行计数加一
        }
        isFirst=1;  //一行结束，此时会出现行首
        if(isFirstLine)isFirstLine=0;//创建完一行后将首行标记置否
        preLine=firstOfLine;
        x_count=0;  //计数置零
        y_count++;  //行计数加一
    }

    return head;
}

//判断细胞生死
int changLive(Cell* cell){
    //计数周围的细胞
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
    //判断生死
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

//确定下一张表状态
void toDecideNextMap(Cell* nowdisplyMap,Cell* nextdisplyMap){
    Cell* nowMapHead=nowdisplyMap;
    Cell* nextMapHead=nextdisplyMap;
    //遍历表
    Cell* nowMapPointer=nowMapHead;
    Cell* nextMapPointer=nextMapHead;
    Cell* nowMapFirstOfLine=nowMapHead;
    Cell* nextMapFirstOfLine=nextMapHead;

    //行遍历
    while (nowMapFirstOfLine!=NULL)
    {
        nowMapPointer=nowMapFirstOfLine;
        nextMapPointer=nextMapFirstOfLine;
        //列遍历
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

//找到对应位置并设置细胞
void findAndSet(Cell* head,int x,int y){
    Cell* pointer=head;
    //在x轴上前进的步数
    for(int i=0;i<x-1;i++){
        pointer=pointer->right;
    }
    //在y轴上前进的步数
    for (int j=0; j<y-1; j++){
        pointer=pointer->down;
    }
    pointer->isLive=1;
}

//判断是否全部死亡
int isAllDead(Cell* nowdisplyMap){
    int flag=1; //默认全部死亡
    Cell* firstOfLine=nowdisplyMap;
    Cell* now=firstOfLine;
    //行
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

//打印表格
void printMap(Cell* head){
    Cell* firstOfLine=head;
    Cell* now=firstOfLine;

    //行
    while (firstOfLine!=NULL)
    {
        now=firstOfLine;
        firstOfLine=firstOfLine->down;
        while (now!=NULL)
        {
            if (now->isLive)
            {
                printf("■");
            }else{
                printf("□");
            }
            now=now->right;
        }
        printf("\n");
    }

}

//设置初始细胞
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
            printf("坐标输入错误，请重新输入\n");
            continue;
        }
        findAndSet(nowdisplyMap,x1,y1);
        printMap(nowdisplyMap);
    }
}

//运行
int run(Cell* nowdisplayMap,Cell* nextdisplayMap){
    char control=0;
    int autoflag=0;
    Cell* temp=NULL;
    while (1)
    {
        
        if(!autoflag){
            printf("输入1开始/继续分步模拟，输入2自动模拟,输入0退出\n");
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
        //确定下一张表的状态
        toDecideNextMap(nowdisplayMap,nextdisplayMap);
        //交换表
        temp=nowdisplayMap;
        nowdisplayMap=nextdisplayMap;
        nextdisplayMap=temp;
        printMap(nowdisplayMap);
        printf("\n");

        //检查当前表是否有存活细胞
        if(isAllDead(nowdisplayMap))break;
    }
    if(autoflag==3)printf("游戏结束，是否以当前地图大小重新开始？\n若是请输入y，否请输入n来退出游戏\n");
    else printf("细胞已经全部死亡，是否以当前地图大小重新开始？\n若是请输入y，否请输入n来退出游戏\n");
    control=getchar();
    getchar();
    if (control=='y')return 1;
    else return 0;
}

//主函数
int main(int argc, char const *argv[])
{
    Cell* nowdisplyMap=NULL;
    Cell* nextdisplyMap=NULL;
    
    printf("欢迎游玩元胞自动机\n");
    printf("请输入地图大小（NxM）\n");
    scanf("%d",&x);
    getchar();
    scanf("%d",&y);
    getchar();

    printf("正在生成地图...\n");
    nowdisplyMap=init(x,y);
    nextdisplyMap=init(x,y);
    printMap(nowdisplyMap);
    //设置初始细胞
    printf("生成完毕，请输入初始细胞位置\n格式：x y以数字0结束,起始点为左上角,坐标 1 1\n向右为x轴，向下为y轴\n");
    setOriginCell(nowdisplyMap);
    getchar();

    while (run(nowdisplyMap,nextdisplyMap))
    {
        //todo
    }
    
    printf("游戏结束,感谢游玩！");
    system("pause");
    return 0;
}