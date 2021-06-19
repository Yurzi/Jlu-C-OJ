#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

/*<---------------------高精度加法------------------------->*/
class BigInteger
{
private:
    vector<int> content;
public:
    BigInteger();
    BigInteger(long long origin);
    BigInteger(const BigInteger& b);
    ~BigInteger();
    unsigned long long size() const;
    BigInteger operator+(const BigInteger& b);
    BigInteger& operator=(const BigInteger& b);
    void resize(unsigned long long n); 
    const int& operator[](unsigned long long i)const;
    int& operator[](unsigned long long i);
    string toString();

};
BigInteger::BigInteger(){
    content.reserve(128);
    for (int i = 0; i < 128; ++i){
        content.push_back(0);
    }
    
}

BigInteger::BigInteger(long long origin){
    content.reserve(128);
    while (origin>0)
    {
        content.push_back(origin%10);
        origin=origin/10;
    }
}
BigInteger::BigInteger(const BigInteger& b){
    content.clear();
    for(int i=0;i<b.size();++i){
        content.push_back(b[i]);
    }
}

BigInteger::~BigInteger(){
    content.clear();
}

BigInteger BigInteger::operator+(const BigInteger& b){
    BigInteger t;
    BigInteger res;
    unsigned long long maxsize=max(this->size(),b.size());
    t.resize(maxsize+1);
    res.resize(maxsize+1);
    for (int i = 0; i < maxsize; ++i){
        int num1=i<this->size()?content[i]:0;
        int num2=i<b.size()?b[i]:0;
        res[i]=(num1+num2+t[i])%10;
        t[i+1]=(num1+num2+t[i])/10;
    }
    if(t[maxsize]!=0){
        res[maxsize]=t[maxsize];
    }else{
        res.resize(maxsize);
    }
    return res;
}
BigInteger& BigInteger::operator=(const BigInteger& b){
    if(this==&b){
        return *this;
    }else{
        content.clear();
        content.reserve(b.size());
        for(int i=0;i<b.size();++i){
            content.push_back(b[i]);
        }
    }
    return *this;
}
unsigned long long BigInteger::size()const{
        return content.size();
}
const int& BigInteger::operator[](unsigned long long i)const{
    if(i>content.size())return *content.end();
    return (*(content.begin()+i));
}
int& BigInteger::operator[](unsigned long long i){
    if(i>content.size())return *content.end();
    return (*(content.begin()+i));
}
void BigInteger::resize(unsigned long long n){
    if(n>this->size()){
        for (unsigned long long i = this->size(); i <n; ++i){
            content.push_back(0);
        }
    }else{
        for (unsigned long long i = this->size(); i>n; --i){
            content.pop_back();
        }
    }
}
string BigInteger::toString(){
    bool flag=true;
    string res;
    for (int i = this->size()-1; i >=0; --i){
        if(flag&&content[i]==0){
            continue;
        }else{
            if(flag&&content[i]!=0){
                flag=false;
            }
            res.push_back(content[i]+48);
        }
    }
    if(flag)res.push_back('0');
    return res;
}
/*<!--------------------高精度加法------------------------->*/
#define MAXN 10010
int n=0;
int m=0;
/*<---------------------读入AOV图-------------------------->*/
struct Edge
{
    int u;
    int v;
    int w;
    Edge* next;
    Edge(){v=0;w=0;next=nullptr;}
    Edge(int _u,int _v,int _w){u=_u;v=_v;w=_w;next=nullptr;}
};
struct Node
{
    int inDegree;
    int inDegree_for_bfs;
    int outDegree;
    int cost;
    int ES;
    int LS;
    Edge *next;
    Node(){
        inDegree=0;outDegree=0;
        cost=0;
        ES=0;LS=__INT32_MAX__;  //初始化最早和最晚开始时间
        next=nullptr;
    }
};

Node head[MAXN];
void addEdge(int u,int v,int cost){
    Edge* t=head[u].next;
    head[u].next=new Edge(u,v,cost);
    if(t!=nullptr){
        head[u].next->next=t;
    }
    head[u].outDegree+=1;
    head[v].inDegree+=1;
    head[v].inDegree_for_bfs+=1;
}
void input_map(){
    for (int i = 1; i <=n; ++i){
        scanf("%d",&head[i].cost);
    }
    int u=0,v=0;
    for (int i = 0; i < m; ++i){
        scanf("%d %d",&u,&v);
        addEdge(u,v,head[v].cost);  //将点权前推到边上
    }
    //引入虚源虚汇
    for (int i=1;i<=n;++i){
        if(head[i].inDegree==0){
            //将虚源指向入度为0的点
            addEdge(0,i,head[i].cost);
        }
        if(head[i].outDegree==0){
            //将出度为0点指向虚汇
            addEdge(i,n+1,0);
        }
    }
}
/*<!--------------------读入AOV图-------------------------->*/

/*<---------------------拓扑排序与关键路径---------------------------->*/

//拓扑排序
vector<int> topRes; //存放拓扑排序的结果
void topOder(){
    //初始化
    queue<int> q;
    topRes.reserve(MAXN);
    q.push(0);  //虚源定入度为0
    //开始拓扑
    while (!q.empty()){
        int cur=q.front();
        q.pop();
        topRes.push_back(cur);
        //遍历
        for (auto i = head[cur].next; i!=nullptr;i=i->next){
            int v=i->v;int w=i->w;
            if((--head[v].inDegree)==0){
                q.push(v);
                //cout << v << endl;
            }
            head[v].ES=max(head[cur].ES+w,head[v].ES);  //顺着拓扑排序，求出最活动的最早开始时间
            //cout<<head[v].ES<<endl;
        }
    }
}

//关键路径算法
void CritiaclPath(){
    topOder();  //顺推求出所有的最早发生时间
    head[n+1].LS=head[n+1].ES;  //将顺推的结果作为逆推的开头
    //开始逆推
    for(int i=topRes.size()-1;i>=0;--i){
        int cur=topRes[i];
        for (auto j = head[cur].next; j!=nullptr;j=j->next){
            int v=j->v;int w=j->w;
            head[cur].LS=min(head[v].LS-w,head[cur].LS);    //逆拓扑序，求出活动的最迟开始时间
            //cout<<head[cur].LS<<endl;
        }
    }
}

/*<!--------------------拓扑排序与关键路径---------------------------->*/

/*<---------------------利用BFS递推来求出结果------------------------->*/
BigInteger temps[MAXN]; //用于存放到达每个节点的关键路径
BigInteger final;   //存放最终结果
int visited[MAXN];  //用于区分节点是否已经被计算过

void BFS(int x){
    queue<int> q;   //暂存层
    q.push(x);
    visited[x]=1;
    while (!q.empty()){
        int cur=q.front();
        q.pop();
        visited[cur]=1;
        for (auto i = head[cur].next; i!=nullptr;i=i->next){
            int v=i->v;
            head[v].inDegree_for_bfs-=1;
            //则指向节点为关键节点，该路径为关键路径
            if(head[v].ES==head[v].LS){
                temps[v]=temps[cur]+temps[v];
            }
            if(head[v].inDegree_for_bfs==0){
                q.push(v);
            } 
        }
        
    }
}



/*<!--------------------利用BFS递推来求出结果------------------------->*/

int main(int argc, char const *argv[])
{
    scanf("%d %d",&n,&m);
    input_map();    //读入AOV图
    CritiaclPath(); //求出关键路径上的时间
    temps[0]=1; //认为到虚源有一条关键路径
    BFS(0);
    long long res=head[n+1].ES;
    final=temps[n+1];
    if(final.toString()!="0")cout<<res<<endl;
    cout<<final.toString()<<endl;
    return 0;
}
