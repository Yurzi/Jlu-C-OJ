#include<iostream>
#include<queue>
#include<stack>
using namespace std;

stack<char> content;
vector<queue<char>> allline;
queue<char> res;
int main(int argc, char const *argv[])
{
    int n=0;int m=0; int s=0;
    scanf("%d %d %d",&n,&m,&s);
    getchar();
    char ctemp=0;
    queue<char>* line_t;
    for (int i = 0; i <n; ++i)
    {
        line_t=new queue<char>;
        for (int j = 0; j < m; ++j)
        {
            scanf("%c",&ctemp);
            line_t->push(ctemp);
        }
        getchar();
        allline.push_back(*line_t);
        delete line_t;
    }
    int ope=0;
    while (1)
    {
        scanf("%d",&ope);
        getchar();
        if(ope==-1)break;
        ope=ope-1;
        if(0<=ope&&ope<n){
            if(!allline[ope].empty()){
                if(s==content.size()){
                    res.push(content.top());
                    content.pop();
                }
                content.push(allline[ope].front());
                allline[ope].pop();
            }
        }else if (ope==-1)
        {
            if(!content.empty()){
                res.push(content.top());
                content.pop();
            }  
        }
    }
    while (!res.empty())
    {
        printf("%c",res.front());
        res.pop();
    }  
}