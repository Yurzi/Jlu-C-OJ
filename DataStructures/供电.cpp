#include<iostream>
#include<vector>

using namespace std;

struct Edge{
    int u;
    int v;
    int cost;
    Edge* next;
    Edge(int _u_,int _v_,int _cost_):u(_u_),v(_v_),cost(_cost_){
        next=nullptr;
    }
    bool operator<(const Edge &b)const{
        return cost>b.cost;
    }
};
vector<int> pcost;
vector<int> dist;
vector<Edge*> list;
vector<bool> visited;
int n=0,m=0;
int cnt=1;    //记录边数
int res;

void prime(){
    //根据贪心选择建设发电站最小的代价的点
    int x=0;int min=__INT32_MAX__;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            if(pcost[i]<min){
                min=pcost[i];
                x=i;
            }
        }
    }
    //初始化轻边
    for(int i=1;i<=n;++i){
        dist[i]=pcost[i];
    }

    res+=pcost[x];
    //第一个点进入已选集合
    visited[x]=true;
    while (cnt<n)
    {
        //更新轻边
        for(Edge *i=list[x];i!=nullptr;i=i->next){
            if(i->cost<dist[i->v]){
                dist[i->v]=i->cost;
            }
        }
        min=__INT32_MAX__;
        int t=0;    //标记下一个节点
        for(int i=1;i<=n;++i){
            if(visited[i])continue;
            if(min>dist[i]){
                min=dist[i];
                t=i;
            }
        }
        res+=min;
        ++cnt;
        visited[t]=true;
        x=t;
    }
}

int main(int argc, char const *argv[]){

    scanf("%d %d",&n,&m);getchar();
    //输入建发电站的花费
    int t=0;
    pcost.reserve(n+1);list.reserve(n+1);visited.reserve(n+1);dist.reserve(n+1);
    pcost.push_back(0);
    list.push_back(nullptr);
    visited.push_back(false);
    dist.push_back(__INT32_MAX__);
    for(int i=1;i<=n;++i){
        scanf("%d",&t);getchar();
        pcost.push_back(t);
        list.push_back(nullptr);
        visited.push_back(false);
        dist.push_back(__INT32_MAX__);
    }
    //读入图
    int u=0,v=0,cost=0;
    for(int i=1;i<=m;++i){
        scanf("%d %d %d",&u,&v,&cost);
        //加入无向边
        Edge *t=list[u];
        list[u]=new Edge(u,v,cost);
        if(t!=nullptr){
            list[u]->next=t;
        }
        t=list[v];
        list[v]=new Edge(v,u,cost);
        if(t!=nullptr){
            list[v]->next=t;
        }
    }
    //寻找最小生成树

    prime();
    
    printf("%d\n",res);
    return 0;
}
