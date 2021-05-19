#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> list;
    vector<int> left;
    vector<int> right;
    list.push_back(-(__INT32_MAX__-1));
    left.push_back(0);
    right.push_back(0);
    vector<long long> sum;
    stack<int> temp;
    sum.push_back(0);
    
    int n=0;
    scanf("%d",&n);
    getchar();
    
    int itemp=0;
    //输入数据
    for(int i=1;i<=n;++i){
        scanf("%d",&itemp);
        getchar();
        list.push_back(itemp);
        left.push_back(i);
        right.push_back(i);

        sum.push_back(sum[i-1]+itemp);  //使用前缀和数组优化计算
    }
    list.push_back(-(__INT32_MAX__-1));
    //从左侧使用单调栈遍历
    temp.push(0);
    for(int i=1;i<=n;++i){
        //使用严格的单调递增栈
        while (!temp.empty()&&list[temp.top()]>=list[i])
        {
            temp.pop();
        }

        left[i]=temp.top();
        temp.push(i);
    }
    //清空栈
    while (!temp.empty())
    {
        temp.pop();
    }
    temp.push(n+1);
    for (int i = n; i >= 1; --i)
    {
        //使用严格的单调递增栈
        while (!temp.empty()&&list[temp.top()]>=list[i])
        {
            temp.pop();
        }

        right[i]=temp.top();
        temp.push(i);
    }
    long long max=0,max_t=0;
    int max_l=0,max_r=0;

    for(int i=1;i<=n;++i){
        max_t=list[i]*(sum[right[i]-1]-sum[left[i]]);
        if(max_t>max){
            max=max_t;
            max_l=left[i]+1;
            max_r=right[i]-1;
        }else if (max==max_t){
           if(max_r-max_l<right[i]-1-left[i]-1){
                max_l=left[i]+1;
                max_r=right[i]-1;
           }else if(left[i]+1<max_l){
                max_l=left[i]+1;
                max_r=right[i]-1;
           } 
        }
        
    }
    printf("%lld\n%d %d",max,max_l,max_r);
    return 0;
}
