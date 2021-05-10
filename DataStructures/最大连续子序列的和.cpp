#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(int argc, char const *argv[])
{
    int n=0;int m=0;    //用来存放输入的n和m
    vector<int> preSum; //保存前缀和    并不需要保存喜欢值序列
    deque<pair<int,int>> MQueue;    //单调队列  first 存储数据 second 存储下标
    int Max=0;
    int left=0;int right=0;

    //读入数据
    scanf("%d %d",&n,&m);
    getchar();  //去除回车 以防万一
    int itemp=0;    //暂存读入的数据，用来加入vector
    preSum.push_back(0);
    for(int i=1;i<=n;++i){
        scanf("%d",&itemp);
        getchar();
        preSum.push_back(preSum[i-1]+itemp);
    }
    for(int i=0;i<=n;++i){
        //入队并维持单调性
        if(MQueue.empty()||preSum[i]>=MQueue.back().first){
            MQueue.push_back(pair<int,int>(preSum[i],i));
        }else{
            while (!MQueue.empty()&&MQueue.back().first>preSum[i])
            {
                MQueue.pop_back();
            }
            MQueue.push_back(pair<int,int>(preSum[i],i));
        }
        //维护区间
        if(i>=m){
            while (!MQueue.empty()&&MQueue.front().second<i-m)
            {
                MQueue.pop_front();
            }
        }

        //与max进行比较
        if(Max<MQueue.back().first-MQueue.front().first){
            Max=MQueue.back().first-MQueue.front().first;
            left=MQueue.front().second;
            right=MQueue.back().second;
        }

    }
    printf("%d %d %d",Max,left+1,right);
    return 0;
}