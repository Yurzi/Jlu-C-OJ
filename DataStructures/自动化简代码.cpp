#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

typedef pair<vector<int>,int> yurzi;
struct cmpValue
{
    bool operator()(const yurzi &a,const yurzi &b){
        //return a.second>b.second;
        if(a.second!=b.second){
            return a.second>b.second;
        }else{
            for (int i = 0; i <a.first.size(); ++i)
            {
                if(a.first[i]!=b.first[i]){
                    return a.first[i]<b.first[i];
                }
            }
            
        }
    }
};
int main(int argc, char const *argv[])
{
    map<vector<int>,int> mymap;
    vector<int> str;
    int n=0,m=0,itp;
    scanf("%d %d",&n,&m);
    getchar();
    for (n; n>0; --n)
    {
        str.clear();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d",&itp);
            getchar();
            str.push_back(itp);
        }
        auto iter=mymap.find(str);
        if(iter!=mymap.end()){
            iter->second+=1;
        }else{
            mymap.insert(yurzi(str,1));
        }
        
    }
    vector<yurzi> pre(mymap.begin(),mymap.end());
    sort(pre.begin(),pre.end(),cmpValue());
    
    printf("%d",mymap.size());
    for(int i=0;i!=pre.size();++i){
        printf("\n%d",pre[i].second);
        for (int j = 0; j <m; ++j)
        {
            printf(" %d",pre[i].first[j]);
        }
    }
    return 0;
}
