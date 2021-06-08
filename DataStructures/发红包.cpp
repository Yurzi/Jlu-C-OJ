#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
struct person
{
    int v;
    person *next;
    person(int _v_):v(_v_){
        next=nullptr;
    }
};
long long total_cost=0;
pair<int,pair<int,person*>> head[10001];

int main(int argc, char const *argv[]){
    int n=0,m=0;
    scanf("%d %d",&n,&m);getchar();
    //初始化

    //逆向建图
    int u=0,v=0;
    for(int i=0;i<m;++i){
        scanf("%d %d",&v,&u);getchar();
        person *t=head[u].second.second;
        head[u].second.second=new person(v);
        if(t!=nullptr){
            head[u].second.second->next=t;
        }
        //被指向节点入度加一
        head[v].second.first++;
    }

    //进行拓扑排序
    //初始化
    int count=0;
    queue<int> temp;
    for(int i=1;i<=n;++i){
        if(head[i].second.first==0){
            temp.push(i);
        }
    }
    //开始拓扑
    while (!temp.empty()){
        int cur=temp.front();
        total_cost+=(head[cur].first+888);
        ++count;    //记录已经摘除的点数
        temp.pop();
        //遍历该点的连接点
        for (person* i = head[cur].second.second; i!=nullptr; i=i->next){
            //进行"松弛"
            head[i->v].first=max(head[i->v].first,head[cur].first+1);
            head[i->v].second.first--;  //入度减一
            if(head[i->v].second.first==0){
                temp.push(i->v);    //若入度为0则入队
            }
        }        
    }

    printf("%d\n",count==n?total_cost:-1);

    return 0;
}
