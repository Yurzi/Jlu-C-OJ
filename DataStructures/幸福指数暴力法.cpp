#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> list;
    vector<long long> sum;
    list.push_back(-(__INT32_MAX__-1));
    sum.push_back(0);

    int n=0;
    scanf("%d",&n);
    getchar();
    int itemp=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&itemp);
        getchar();
        list.push_back(itemp);
        sum.push_back(sum[i-1]+itemp);
    }
    list.push_back(-(__INT32_MAX__-1));
    int left_t=0; int right_t=0;
    long long max=0,max_t=0;
    int max_l=0,max_r=0;
    for (int i = 1; i <=n; ++i)
    {
        left_t=0;right_t=n+1;
        //往左侧找
        for(int l=i;l>=0;--l){
            if(list[l]<list[i]){
                left_t=l;
                break;
            }
        }
        //往右侧找
        for (int r = i; r<=n+1; ++r)
        {
            if(list[r]<list[i]){
                right_t=r;
                break;
            }
        }
        //判断
        max_t=list[i]*(sum[right_t-1]-sum[left_t]);
        if(max_t>max){
            max=max_t;
            max_l=left_t+1;
            max_r=right_t-1;
        }else if (max==max_t){
           if(max_r-max_l<right_t-left_t-2){
                max_l=left_t+1;
                max_r=right_t-1;
           }else if(left_t+1<max_l){
                max_l=left_t+1;
                max_r=right_t-1;               
           } 
        }
    }
    printf("%lld\n%d %d",max,max_l,max_r);
    return 0;
}
