#include<iostream>
#include<vector>

using namespace std;

vector<int> father;

void make_set(int n){
    for (int i = 0; i <=n; ++i)
    {
        father.push_back(0);
    }
}
int Find(int v){
    if(father[v]<=0)return v;
    return father[v]=Find(father[v]);   //路径压缩
}

void Union(int x,int y){
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy){
        father[fy]=fx;
    }
}

int main(int argc, char const *argv[])
{
    //输入数据
    int n=0,m=0,p=0;
    scanf("%d %d %d",&n,&m,&p);
    make_set(n);
    int x=0,y=0;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d",&x,&y);
        getchar();
        Union(x,y);
    }
    for (int i = 0; i < p; ++i)
    {
        scanf("%d %d",&x,&y);
        if(Find(x)==Find(y)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    
    
    
    return 0;
}
