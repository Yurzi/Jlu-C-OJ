#include<iostream>
#include<queue>

using namespace std;

int n=0;int k=0;
int count=0;

vector<int> res;

int toslove(int x,int _k,int q,int sum){
    if(_k==0){
        if(sum==n){
            ++count;
            for (int i=0;i<res.size();++i)
            {
                printf("%d",res[i]);
                if(i<res.size()-1)printf(" ");
            }
            printf("\n");
            return 0;
        }else{
            return 0;
        }
    }
    for(int i=q;i<=x/_k;++i){
        res.push_back(i);
        toslove(x-i,_k-1,i,sum+i);
        res.pop_back();
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    
    scanf("%d %d",&n,&k);
    toslove(n,k,1,0);
    printf("%d\n",count);
    return 0;
}
