#include<iostream>
#include<stack>
#include<queue>

using namespace std;
int count=0;
int n=0;

vector<pair<char,int>> list;

struct layer
{
    queue<char> list;
    layer* next;
    layer(){
        next=NULL;
    }
};

layer * initForest(layer * root,int x){
    if(count>=n){
        return NULL;
    }
    if(root==NULL)root=new layer;
    for(int i=0;count<n&&i<x;++i){
        int target=count;
        ++count;
        root->list.push(list[target].first);
        if(list[target].second>0){
            root->next=initForest(root->next,list[target].second);
        }
    }
    return root;
}
int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    getchar();

    char ctemp=0;
    for(int i=0;i<n;++i){
        scanf(" %c",&ctemp);
        list.push_back(pair<char,int>(ctemp,0));
    }
    int itemp=0;
    for (int i = 0; i < n; ++i)
    {
        scanf(" %d",&itemp);
        list[i].second=itemp;
    }
    layer* root=NULL;
    root=initForest(root,n);
    bool flag=true;
    while (root!=NULL)
    {
        while (!root->list.empty())
        {
            
            if(flag){
                printf("%c",root->list.front());
                flag=false;
            }else{
                printf(" %c",root->list.front());
            }
            root->list.pop();
        }
        root=root->next;
    }
    printf("\n");
    return 0;
}
