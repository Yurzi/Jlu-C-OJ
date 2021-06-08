#include<iostream>
#include<queue>
using namespace std;

struct Circle{
    int x;
    int y;
    int r;
    Circle(){
        x=0;
        y=0;
        r=0;
    }
    Circle(int _x,int _y,int _r):x(_x),y(_y),r(_r){}
    void operator()(int _x,int _y,int _r){
        x=_x;
        y=_y;
        r=_r;
    } 
};
struct Node
{
    int v;
    Node* next;
    Node(int _v):v(_v),next(nullptr){}
};


Node* list[8001]={nullptr}; //邻接表
Circle store[8001];
int visited[8001]={0};

//使用深度优先搜索遍历一个连通分支
void DFS(int x){
    visited[x]=1;
    Node *t=list[x];
    while (t!=nullptr)
    {
        if(visited[t->v]==0)DFS(t->v);
        t=t->next;
    }
}
//广度优先搜索
queue<int> temp;
void BFS(int x){
    temp.push(x);
    visited[x]=1;
    while (!temp.empty())
    {
        int v=temp.front();
        temp.pop();
        for (Node*p = list[v];p!=nullptr;p=p->next)
        {
            if(visited[p->v]==0){
                temp.push(p->v);
                visited[p->v]=1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    int n=0;
    scanf("%d",&n);
    getchar();
    int x=0,y=0,r=0;
    for (int i = 1; i <=n ; ++i)
    {
        scanf("%d %d %d",&x,&y,&r);
        getchar();
        store[i](x,y,r);
        //寻找连通项
        for(int j=1;j<i;++j){
            long long dis=(long long)(store[i].x-store[j].x)*(store[i].x-store[j].x)+(long long)(store[i].y-store[j].y)*(store[i].y-store[j].y);
            long long tr=(long long)(store[i].r+store[j].r)*(store[i].r+store[j].r);
            if(dis<=tr){
                Node* t=list[i];
                list[i]=new Node(j);
                if(t!=nullptr){
                    list[i]->next=t;
                }
                t=list[j];
                list[j]=new Node(i);
                if(t!=nullptr){
                    list[j]->next=t;
                }
            }
        }
    }
    
    int count=0;
    for(int i=1;i<=n;++i){
        if(visited[i]==0){
            DFS(i);
            ++count;
        }
    }
    
    printf("%d",count);

    return 0;
}
