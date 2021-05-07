#include<iostream>
#include<vector>
using namespace std;


int main(int argc, char const *argv[])
{
    vector<vector<int>> Plots;  //存储全部剧情点
    vector<int> plotline_t; //存储一个剧情点的内容的传递数组
    int save[100]={0};   //存档点
    int n=0; //剧情点总数
    int m=0;    //操作总数
    scanf("%d %d",&n,&m);
    getchar();
    //导入剧情
    int k=0;    //暂存一个剧情点的内容个数
    int temp=0;
    for (n;n>0;--n)
    {
        scanf("%d",&k);
        getchar();
        //读入剧情点内容
        for(k;k>0;--k){
            scanf("%d",&temp);
            getchar();
            plotline_t.push_back(temp-1);
        }
        Plots.push_back(vector<int>(plotline_t.begin(),plotline_t.end()));
        plotline_t.clear();
    }
    //读入操作
    int p_plot=0;
    for (m;m>0;--m)
    {
        scanf("%d %d",&k,&temp);
        temp-=1;
        getchar();
        switch (k)
        {
        case 0:
        p_plot=Plots[p_plot][temp];
            break;
        case 1:
        save[temp]=p_plot;
        printf("%d\n",p_plot+1);
            break;
        case 2:
        p_plot=save[temp];
        default:
            break;
        }
    }
    printf("%d",p_plot+1);    
    return 0;
}
