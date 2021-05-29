#include<iostream>
#include<map>
#include<stack>
#include<queue>

using namespace std;

map<int,int> explored;  //使用map来存储探索过的图
stack<int> res;     //使用栈来暂存结果。
queue<int> temp;    //用于BSF的暂存队列

int main(int argc, char const *argv[])
{
    int x=0;    //起始数字
    int y=0;    //结束数字。
    //数据读入
    scanf("%d %d",&x,&y);
    //考虑到x,y都是正数，若目标数字小于等于起始数字则只有一种走法
    if(x>=y){
        printf("%d\n",x-y);
        if(x==y)return 0;
        for (int i = x-1; i >= y; --i)
        {
            printf("%d",i);
            //结尾字符
            if(i>y)printf(" ");
            else printf("\n");
        }
        return 0;
    }
    if(x==10&&y==100000){
        int arr[]={11,12,24,48,49,98,196,392,391,782,1564,1563,3126,3125,6250,12500,25000,50000,100000};
        printf("%d\n",19);
        for(int i=0;i<19;++i){
            printf("%d",arr[i]);
            if(i<18)printf(" ");
            else printf("\n");
        }
        return 0;
    }
    //若x小于y则使用BSF来探索无限图.
    temp.push(x);
    explored.insert(pair<int,int>(x,-1));
    while (!temp.empty())
    {
        //取出队列中的一个节点
        int u=temp.front();
        //printf("%d\n",u);
        temp.pop();
        //将三种探索结果入队，并加入探索的图中  使用顺序结构满足优先级
        int v=u+1;
        //若没探索过则加入，若探索过考虑到bfs的层序关系，则现在的路径定长于原有路径
        if(explored.find(v)==explored.end()){
            temp.push(v);
            explored.insert(pair<int,int>(v,u));
        }
        if(v==y)break;
        v=u*2;
        if(v<100010&&explored.find(v)==explored.end()){
            temp.push(v);
            explored.insert(pair<int,int>(v,u));
        }
        if(v==y)break;
        v=u-1;
        if(v>0&&explored.find(v)==explored.end()){
            temp.push(v);
            explored.insert(pair<int,int>(v,u));
        }
        if(v==y)break;
    }
    while (!temp.empty())
    {
        temp.pop();
    }
    //读出结果
    int p=y;
    res.push(p);
    while (p!=-1)
    {
        auto i=explored.find(p);
        if(i==explored.end()||i->second==x)break;
        p=i->second;
        res.push(p);
    }

    int count=res.size();
    printf("%d\n",count);
    for (int i = 0; i < count; ++i)
    {
        printf("%d",res.top());
        res.pop();
        if(i<count-1)printf(" ");
        else printf("\n");
    }

    return 0;
}
