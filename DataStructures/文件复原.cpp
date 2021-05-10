#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

typedef pair<string,pair<int,int>> yurzi;

int main(int argc, char const *argv[])
{
    vector<int> paper;
    map<string,pair<int,int>> frags;
    vector<int> res;
    int n=0;;
    scanf("%d",&n);
    getchar();
    int itemp=0;
    for(int i=0;i<n;++i){
        scanf("%d",&itemp);
        getchar();
        paper.push_back(itemp);
    }
    int m=0;
    scanf("%d",&m);
    getchar();
    string frag_t;
    for (int i=1;i<=m;++i)
    {
        cin>>itemp;
        getchar();
        getline(cin,frag_t);
        frags.insert(yurzi(frag_t,pair<int,int>(i,0)));
    }
    string tofind;
    int j=0;
    for (int i = 0; i < m; ++i)
    {
        tofind.clear();
        for (int k=j;k<n;++k)
        {
            if(k!=j)tofind.append(" ");
            tofind.append(to_string(paper[k]));
            auto iter=frags.find(tofind);
            if(iter!=frags.end()){
                if(iter->second.second!=1){
                    iter->second.second=1;
                    res.push_back(iter->second.first);
                    j=k;
                    break;
                }
            }
        }
    }
    for (int i = 0; i <res.size(); ++i)
    {
        printf("%d",res[i]);
        if(i<res.size()-1)printf(" ");
    }
    return 0;
}
