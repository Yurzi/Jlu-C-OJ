#include<iostream>
#include<queue>


using namespace std;

typedef pair<int,int> yurzi;
struct Node{
    int info;
    Node* next;
    Node(){
        info=0;
        next=nullptr;
    }
    Node(int v){
        info=v;
        next=nullptr;
    }
};

Node* list[50001]={nullptr};    //邻接表头
Node* ptrList[50001]={nullptr};     //邻接表尾指针
int visited[50001]={false}; //标记是否访问过
int mytime=0; //计时器
int di[50001]={0};     //记录发现时间
int fi[50001]={0};      //记录结束时间
priority_queue<yurzi,vector<yurzi>,greater<yurzi>> edge;

void DFS(int x,int ftime){
    visited[x]=1;
    di[x]=++ftime;
    ++mytime;
    //标记邻接节点发现时间
    for (Node *p=list[x];p!=nullptr;p=p->next)
    {
        if(visited[p->info]!=1){
            di[p->info]=mytime;
        }
    }
    //向下搜素
    for (Node* p =list[x];p!=nullptr;p=p->next){
        if(visited[p->info]!=1){
            edge.push(yurzi(p->info,x));
            DFS(p->info,mytime);
        }
    }
    //该节点搜完毕;    
    fi[x]=++mytime;
}


int main(int argc, char const *argv[])
{
    //数据输入
    int n=0,m=0;
    scanf("%d %d",&n,&m);
    getchar();
    
    int u=0,v=0;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d",&u,&v);
        getchar();

        Node *t=ptrList[u];
        if(t==nullptr){
            list[u]=new Node(v);
            ptrList[u]=list[u];
        }else{
            ptrList[u]->next=new Node(v);
            ptrList[u]=ptrList[u]->next;
        }
        
        t=ptrList[v];
        if(t==nullptr){
            list[v]=new Node(u);
            ptrList[v]=list[v];
        }else{
            ptrList[v]->next=new Node(u);
            ptrList[v]=ptrList[v]->next;
        }
    }

    //遍历连通分量
    for(int i=1;i<=n;++i){
        if(visited[i]!=1){
            DFS(i,mytime);
        }
    }
    for (int i = 1; i <=n; ++i)
    {
        printf("%d %d%c",di[i],fi[i],'\n');
    }
    printf("%d\n",edge.size());
    while (!edge.empty())
    {
        printf("%d %d\n",edge.top().second,edge.top().first);
        edge.pop();
    }
    return 0;
}
