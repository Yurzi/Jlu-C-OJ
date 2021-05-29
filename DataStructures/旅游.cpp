#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct Edge
{
    int dist;
    int u;
    Edge(int cost,int now){
        dist=cost;
        u=now;
    }
    bool operator <(const Edge& b) const {
        return dist>b.dist;
    }

};

//邻接表节点
struct Node{
    int v;
    int w;
    Node *next;
    Node(){
        v=0;
        w=0;
        next=nullptr;
    }
    Node(int _v,int _w){
        v=_v;
        w=_w;
        next=nullptr;
    }
};

Node *list[10001]={nullptr};        //邻接表头指针
Node *rearList[10001]={nullptr};    //邻接表尾指针
int cityCount[10001]={0};   //计数到达某个城市能经过的节点数
int visited[10001]={0}; //标记是否访问过的数组

priority_queue<Edge> temp;

int main(int argc, char const *argv[])
{
    //读入数据
    int n=0,m=0,s=0;
    scanf("%d %d %d",&n,&m,&s);
    //读入边表
    int u=0,v=0,w=0;
    for (int i = 0; i <m; ++i)
    {
        scanf(" %d %d %d",&u,&v,&w);

        Node *t=rearList[u];
        if(t==nullptr){
            list[u]=new Node(v,w);
            rearList[u]=list[u];
        }else{
            rearList[u]->next=new Node(v,w);
            rearList[u]=rearList[u]->next;
        }
        
        t=rearList[v];
        if(t==nullptr){
            list[v]=new Node(u,w);
            rearList[v]=list[v];
        }else{
            rearList[v]->next=new Node(u,w);
            rearList[v]=rearList[v]->next;
        }
    }

    //使用dijkstra
    //初始化
    int dist[10001];
    for (int i = 0; i <= n; ++i)
    {
        dist[i]=__INT32_MAX__;
    }
    
    dist[s]=0;
    temp.push(Edge(0,s));   //使用堆来寻找cost最小的目标
    while (!temp.empty())
    {
        Edge cur=temp.top();    //取出下一个目标
        temp.pop();
        if(visited[cur.u]==1)continue;  //若已经被访问则不再访问
        else visited[cur.u]=1;  //否则标记并进入松弛流程;
        //遍历该节点能到达的所有节点
        for(Node *p=list[cur.u];p!=nullptr;p=p->next){
            if(p->w+dist[cur.u]<dist[p->v]){
                dist[p->v]=p->w+dist[cur.u];    //进行松弛
                temp.push(Edge(dist[p->v],p->v));   //将已经松弛的节点入队
                cityCount[p->v]=cityCount[cur.u]+1; //将目标城市的可经历的节点数加一；
            }else if (p->w+dist[cur.u]==dist[p->v])
            {   
                //若花费相同
                if(cityCount[p->v]<cityCount[cur.u]+1){
                    cityCount[p->v]=cityCount[cur.u]+1;
                }
            }
        }
    }

    //输出
    for(int i=1;i<=n;++i){
        printf("%d%c",dist[i],i==n?'\n':' ');
    }
    for (int i = 1; i<=n; ++i)
    {
        printf("%d%c",cityCount[i],i==n?'\n':' ');
    }
    return 0;
}