#include<iostream>
#define N 100001

using namespace std;

int parent[N];
int path[N]={0};

int main(int argc, char const *argv[])
{

    int n=0;
    scanf("%d",&n);getchar();
    int u=0,v=0;
    for (int i = 0; i < n-1; i++)
    {
        scanf("%d %d",&u,&v);getchar();
        parent[v]=u;
    }
    scanf("%d %d",&u,&v);
    int orgin_u=u;
    int up=0,down=0;
    //u向上走并更新path
    while (parent[u]!=0){
        path[parent[u]]=path[u]+1;
        if(parent[u]==v){
            up=path[u]+1;
            break;
        }
        u=parent[u];
    }
    //v向上走并更新path,若遇到已经大于0的path则证明找到通路
    while (parent[v]!=0&&up==0)
    {
        if(!path[parent[v]]){
            path[parent[v]]=path[v]+1;
        }else{
            up=path[parent[v]];
            down=path[v]+1;
            break;
        }
        if(parent[v]==orgin_u){
            down=path[v]+1;
            break;
        }
        v=parent[v];
    }
    printf("%lld\n",(long long)up*3+down*2);

    
    return 0;
}
