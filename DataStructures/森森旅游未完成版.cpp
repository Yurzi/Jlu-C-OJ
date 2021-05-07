#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef struct arc
{
    int weight_c;
    int weight_t;
    arc(int _w_c = __INT_MAX__, int _w_t = __INT_MAX__)
    {
        weight_c = _w_c;
        weight_t = _w_t;
    }
} Arc;
typedef pair<int, int> pathnode;

int main(int argc, char const *argv[])
{
    int n = 0, m = 0, q = 0;
    scanf("%d %d %d", &n, &m, &q);
    getchar();
    vector<int> rate;
    vector<vector<Arc>> edge;
    vector<vector<pathnode>> path;
    vector<Arc> et;
    vector<pathnode> pt;
    stack<pair<int, int>> c_path;
    for (int i = 0; i < n; ++i)
    {
        et.push_back(Arc());
        pt.push_back(pathnode());
    }
    for (int i = 0; i < n; ++i)
    {
        edge.push_back(et);
        path.push_back(pt);
    }
    et.clear();
    pt.clear();
    //构建图
    int u = 0, v = 0, wc = 0, wt = 0;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d %d", &u, &v, &wc, &wt);
        u -= 1;
        v -= 1;
        getchar();
        if (u != v)
        {
            if (wc < edge[u][v].weight_c)
                edge[u][v].weight_c = wc;
            if (wt < edge[u][v].weight_t)
                edge[u][v].weight_t = wt;
        }
    }
    int r = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &r);
        getchar();
        rate.push_back(r);
    }

    //floryds
    //初始化path
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j && edge[i][j].weight_c < __INT_MAX__)
            {
                path[i][j].first = i;
                path[i][j].second = i;
            }
            else
            {
                path[i][j].first = -1;
                path[i][j].second = -1;
            }
        }
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i != k)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (j != k && j != i && edge[i][k].weight_c < __INT_MAX__ && edge[k][j].weight_c < __INT_MAX__)
                    {
                        if (edge[i][j].weight_c > edge[i][k].weight_c + edge[k][j].weight_c)
                        {
                            edge[i][j].weight_c = edge[i][k].weight_c + edge[k][j].weight_c;
                            path[i][j].first = path[k][j].first;
                        }
                        if (edge[i][j].weight_t > edge[i][k].weight_t + edge[k][j].weight_t)
                        {
                            edge[i][j].weight_t = edge[i][k].weight_t + edge[k][j].weight_t;
                            path[i][j].second = path[k][j].second;
                        }
                    }
                }
            }
        }
    }
    //得到使用现金的路径
    int target=0;int rate_t=0;
    for (q; q > 0; --q)
    {
        scanf("%d %d",&target,&rate_t);
        getchar();
        rate[target-1]=rate_t;
        int p = n-1;
        int u = 0;
        double mincost = 0;
        stack<pair<int,int>>().swap(c_path);
        while (u!=p)
        {
            c_path.push(pair<int, int>(path[u][p].first, p));
            mincost += edge[path[u][p].first][p].weight_c;
            p = path[u][p].first;
        }
        double cost_t = 0;
        double cost_c = 0;
        int i=-1;
        while(!c_path.empty())
        {
            if (i == -1)
            {
                p = n-1;
                u = 0;
            }
            else
            {
                p = n-1;
                u = c_path.top().second;
            }
            cost_t=0;
            while (u!=p)
            {

                cost_t += edge[path[u][p].second][p].weight_t;
                p = path[u][p].second;
            }
            cost_t /= rate[u];
            if (i == -1)
            {
                if (mincost > cost_t)
                {
                    mincost = cost_t;
                }
            }
            else
            {
                cost_c += edge[c_path.top().first][c_path.top().second].weight_c;
                c_path.pop();
                if (mincost > cost_c + cost_t)
                {
                    mincost = cost_c + cost_t;
                }
            }
            ++i;
        }
        printf("%d",(int)(mincost+0.6));
        if(q>1)printf("\n");
    }

    return 0;
}