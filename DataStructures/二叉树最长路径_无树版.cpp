#include<iostream>
#include<vector>

using namespace std;

int Max=0;
vector<int> path;
vector<int> t_path;

void createTree(int n){

    int itemp=0;
    scanf("%d",&itemp);
    getchar();
    if(itemp==-1){
        if(n>=Max){
            Max=n;
            path=t_path;
        }
        return;
    } 
    t_path.push_back(itemp);
    createTree(n+1);
    createTree(n+1);
    t_path.pop_back();
    return ;
}

int main(int argc, char const *argv[])
{
    int n=0;
    scanf("%d",&n);
    getchar();
    createTree(0);
    printf("%d\n",Max-1);
    for(int i=0;i<path.size();++i){
        printf("%d",path[i]);
        if(i<path.size()-1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
