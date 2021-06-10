#include<iostream>
#include<queue>

using namespace std;

struct Object
{
    int u;
    int v;
    int cost;
    Object(){
        u=0;v=0;cost=0;
    }
    Object(const Object &x){
        u=x.u;v=x.v;cost=x.cost;
    }
    Object(int _u,int _v,int _cost):
    u(_u),v(_v),cost(_cost){
    }
    bool operator<(const Object& b)const{
        return cost>b.cost;
    }
};
//边集
priority_queue<Object> edges;

//并查集部分
vector<int> father;
//并查集初始化
void make_set(int n){
    for (int i = 0; i <=n; ++i)
    {
        father.push_back(0);
    }
}
//并查集查找
int Find(int v){
    if(father[v]<=0)return v;
    return father[v]=Find(father[v]);   //路径压缩
}
//并查集合并
void Union(int x,int y){
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy){
        father[fy]=fx;
    }
}


int main(int argc, char const *argv[])
{
    int n=0,m=0;
    scanf("%d %d",&n,&m);
    make_set(n);
    int u=0,v=0,cost=0;
    for(int i=0;i<m;++i){
        scanf(" %d %d %d",&u,&v,&cost);
        edges.push(Object(u,v,cost));
    }
    //Kruskal
    int res=0;
    while (!edges.empty())
    {
        Object t=edges.top();
        edges.pop();
        if(Find(t.u)!=Find(t.v)){
            Union(t.u,t.v);
        }
        if(Find(1)==Find(n)){
            res=t.cost;
            break;
        }
    }
    printf("%d\n",res);
    return 0;
}
