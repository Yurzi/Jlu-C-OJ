#include<iostream>
#include<queue>
using namespace std;

priority_queue<long long,vector<long long>,less<long long>> big;
priority_queue<long long,vector<long long>,greater<long long>> small;

int main(int argc, char const *argv[])
{
    int n=0,t=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&t);
        big.push(t);
        small.push(t);
    }
    while (big.size()!=1)
    {
        long long a=big.top();
        big.pop();
        long long b=big.top();
        big.pop();
        big.push(a*b+1);
    }
    while (small.size()!=1)
    {
        long long a=small.top();
        small.pop();
        long long b=small.top();
        small.pop();
        small.push(a*b+1);
    }
    printf("%lld\n",small.top()-big.top());
    
    return 0;
}
