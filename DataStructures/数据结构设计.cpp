#include<iostream>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

multiset<int,greater<int>> temp;
multiset<int,greater<int>> temp_n;
deque<int> list;
deque<int> list_n;

int main(int argc, char const *argv[])
{
    bool flag=true;
    int n=0;
    scanf(" %d",&n);
    //操作
    char choice=0;
    int x=0;
    for(int i=0;i<n;++i){
        scanf(" %c",&choice);
        if(choice=='I'){
            scanf("%d",&x);getchar();
            list.push_front(flag?x:-x);
            list_n.push_front(flag?-x:x);
            temp.insert(flag?x:-x);
            temp_n.insert(flag?-x:x);
        }else if(choice=='D'){
            if(!list.empty()){
                auto target=temp.find(list.back());
                auto target_n=temp_n.find(list_n.back());
                temp.erase(target);
                temp_n.erase(target_n);
                list.pop_back();
                list_n.pop_back();
            }
        }else if (choice=='R')
        {
            flag=!flag;

        }else if (choice=='M')
        {
            if(!list.empty()){
                printf("%d\n",flag?*temp.begin():*temp_n.begin());
            }
        }
    }
    return 0;
}
