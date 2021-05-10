#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<pair<int,int>> list;
    map<int,int> tofind;
    int n=0;
    scanf("%d",&n);
    getchar();
    int itemp=0;
    int t=0;
    for(int i=0;i<n;++i){
        scanf("%d",&itemp);
        getchar();
        auto iter=tofind.find(itemp);
        if(iter==tofind.end()){
            tofind.insert(pair<int,int>(itemp,t));
            list.push_back(pair<int,int>(itemp,1));
            ++t;
        }else{
            list[iter->second].second+=1;
        }
    }
    for (int i = 0; i < list.size(); ++i)
    {
        printf("%d %d",list[i].first,list[i].second);
        if(i<list.size()-1)printf("\n");
    }
    return 0;
}
