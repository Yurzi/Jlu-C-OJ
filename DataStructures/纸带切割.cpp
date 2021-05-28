#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct node
{
    long long info;
    node(long long _info){
        info=_info;
    }
    friend bool operator< (const node& a,const node& b){
        return a.info>b.info;
    }
};

//堆优化
priority_queue<node> list;

int main(int argc, char const *argv[])
{
    //输入
    long long cost=0;
    stack<long long> res_list;
    int n=0;
    scanf("%d",&n);
    getchar();
    int itemp=0;
    //入堆
    for(int i=0;i<n;i++){
        scanf("%d",&itemp);
        list.push(node(itemp));
    }
    //取堆中2个元素构建哈夫曼树
    long long a=0;long long b=0; 
    while (list.size()>1)
    {
        //构建逻辑哈夫曼树
        a=list.top().info;
        list.pop();
        b=list.top().info;
        list.pop();
        long long res_t=a+b;
        list.push(res_t);
        //将结果存入栈方便倒序输出
        res_list.push(res_t);
        cost+=res_t;
    }

    //输出结果
    printf("%lld\n",cost);
    while (!res_list.empty())
    {
        printf("%lld",res_list.top());
        res_list.pop();
        if(res_list.empty()){
            printf("\n");
        }else{
            printf(" ");
        }
    }    
    return 0;
}

