#include<iostream>
#include<queue>

using namespace std;

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
int visited[50001]={0};     //标记是否被访问
int n=0,e=0;    //节点总数和边数


//使用深度优先搜索遍历一个连通分支
void DFS(int x){
    visited[x]=1;
    Node *t=list[x];
    while (t!=nullptr)
    {
        if(visited[t->info]==0)DFS(t->info);
        t=t->next;
    }
    
}

int main(int argc, char const *argv[])
{
     //读入数据
    scanf("%d %d",&n,&e);
    getchar();

    int u=0,v=0;
    for (int i = 0; i < e; ++i)
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

    
    int count=0;
    for(int i=1;i<=n;++i){
        if(visited[i]==0){
            DFS(i);
            ++count;
        }
    }

    printf("%d\n",count);
    return 0;
}
