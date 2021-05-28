#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef pair<long long,pair<int,int>> yurzi;
int a_list[100001];
int b_list[100001]; //不能用vector 爬
priority_queue<yurzi,vector<yurzi>,greater<yurzi>> section;  //将a与b的乘积存于一个区间中，充分利用乘积的二维方向上的递增关系

int main(int argc, char const *argv[])
{
    int n=0;
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&a_list[i]);
        getchar();
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&b_list[i]);
        getchar();
    }

    //可以先求出一维方向上最小的n个数
    for(int i=0;i<n;++i){
        section.push(yurzi(a_list[0]*b_list[i],pair<int,int>(0,i)));
    }

    //然后随着输出，逐渐拓展二维方向上的
    for (int i = 0; i < n; ++i)
    {
        printf("%lld",section.top().first);
        int a=section.top().second.first;
        int b=section.top().second.second;
        section.pop();
        if(a+1<n){
            section.push(yurzi(a_list[a+1]*b_list[b],pair<int,int>(a+1,b)));
        }
        if(i<n-1){
            printf(" ");
        }else{
            printf("\n");
        }

    }
    return 0;
}
