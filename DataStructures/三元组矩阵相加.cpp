#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

typedef pair<pair<int,int>,int32_t> yurzi;

struct cmp
{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)const{
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
};
int main(int argc, char const *argv[])
{
    map<pair<int,int>,int32_t,cmp> a;
    int n1=0,m1=0,t1=0;
    scanf("%d %d %d",&n1,&m1,&t1);
    getchar();
    int r=0,c=0;
    int32_t v=0;
    for(int i=0;i<t1;++i){
        scanf("%d %d %d",&r,&c,&v);
        getchar();
        a.insert(yurzi(pair<int,int>(r,c),v));
    }
    int n2=0,m2=0,t2=0;
    scanf("%d %d %d",&n2,&m2,&t2);
    getchar();
    if(t1>min(n1,m1)){
        printf("Illegal!");
    }
    if(n1==n2&&m1==m2&&t2>=0){
        for (int i = 0; i < t2; ++i)
        {
            scanf("%d %d %d",&r,&c,&v);
            getchar();
            auto iter=a.find(pair<int,int>(r,c));
            if(iter!=a.end()){
                iter->second=iter->second+v;
                if(iter->second==0){
                    a.erase(iter);
                }
            }
            else{
                a.insert(yurzi(pair<int,int>(r,c),v));
            }
        }
        map<pair<int,int>,int>::iterator p;
        p=a.begin();
        printf("%d %d %d\n",n1,m1,a.size());
        for (int i = a.size(); i >0; --i)
        {
            printf("%d %d %d\n",p->first.first,p->first.second,p->second);
            p++;
        }
        
    }else{
        printf("Illegal!");
    }
    
    return 0;
}
