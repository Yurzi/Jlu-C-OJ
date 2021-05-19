#include <iostream>
#include <vector>
using namespace std;

int res[10001];
int toslove(int n){
    if(n==1){
        return res[n];
    }
    if(res[n]<=0){
        res[n]=(toslove(n-1)*(double)11/10);
    }
    return res[n];
}

int main(){
    res[1]=10;
    int n=0;
    scanf("%d",&n);
    getchar();
    int t=0;
    for (int i = 0; i <n; ++i)
    {
        scanf("%d",&t);
        getchar();
        printf("%d",toslove(t));
        if(i<n-1)cout<<"\n";
    }
}