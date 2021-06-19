#include<iostream>
#define N 20010

using namespace std;

int Left[N];
int Right[N];
int weight[N];
int res[N];
int a[N];
int b[N];

int n=0;
int p=0;

int initTree(int al,int ar){
    if(al>ar){
        return 0;
    }
    ++p;
    if(al==ar){
        return b[ar];
    }

    int root=0;
    int mid=0;
    for(mid=al;mid<=ar;++mid){
        if(b[mid]==a[p]){
            root=a[p];
            break;
        }
    }
    //建立左子树
    Left[root]=initTree(al,mid-1);
    Right[root]=initTree(mid+1,ar);
    return root;
}

void DFS(int root,int cost){
    if(root==0)return;
    res[root]=cost+weight[root];
    DFS(Left[root],res[root]);
    DFS(Right[root],res[root]);
}


int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    for (int i = 1; i <=n; ++i){
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <=n; ++i){
        scanf("%d",&b[i]);
    }
    int root=initTree(1,n);
    for (int i = 1; i <=n; ++i)
    {
        scanf("%d",&weight[i]);
    }
    DFS(root,0);
    for (int i = 1; i <=n; ++i){
        printf("%d%c",res[i],i<n?' ':'\n');
    }
    
    return 0;
}
