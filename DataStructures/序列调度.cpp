#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> temp;
    int t=0, c=0;
    scanf("%d %d",&t,&c);getchar();
    for (int i = 0; i < t; ++i)
    {
        int top=1;
        bool flag=true;
        temp.clear();
        int n=0;
        scanf("%d",&n);
        int k=0;int j=0;
        for (j = 0; j < n; ++j){
            scanf("%d",&k);
            if(!flag)continue;
            while (k>=top){
                temp.push_back(top);
                ++top;
            }
            if(k==top){
                ++top;
                continue;
            }
            if(temp.size()>c){
                flag=false;
                continue;
            }
            if(k<top){
                if(k==temp.back()){
                    temp.pop_back();
                    continue;
                }else{
                    flag=false;
                    continue;
                }
            }
            
        }
        
        printf("%s",flag?"Yes":"No");
        printf("\n");
    }
    

    return 0;
}
