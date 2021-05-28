//使用动态规划，更具子树的高度来确定是否选择
#include<iostream>
#include<vector>

using namespace std;

pair<int,int> tree[100001]; //构建树
int heigth[100001]; //保存对应子树的高度,默认高度为1;即自身
int best[100001]={0};    //保存最优的选择。

//构建树
int initTree(){
    int itemp=0;
    scanf("%d",&itemp);
    getchar();
    if(itemp!=-1){
        tree[itemp].first=initTree();
        tree[itemp].second=initTree();
    }
    return itemp;
}

void dfs(int root){
    if(root==-1){
        return; //代表到达底部了
    }else{
        heigth[root]=1; //全局变量只能初始化为0 爬；
        //如果有左子树，从左侧开始遍历，以确保最后的结果是最右侧的
        if(tree[root].first!=-1){
            dfs(tree[root].first);  //在左子树中求最优选择和高度
            heigth[root]=max(heigth[root],heigth[tree[root].first]+1);  //更新该节点的高度
            best[root]=tree[root].first;    //认为最优的是左子树。
        }
        //若右子树存在
        if(tree[root].second!=-1){
            dfs(tree[root].second); //求右子树的最优选择和高度
            heigth[root]=max(heigth[root],heigth[tree[root].second]+1);
            //如果左子树不存在，或者右侧树更高则选择右侧，相等也选择右侧，因为要右侧的结果
            if(tree[root].first==-1||heigth[tree[root].second]>=heigth[tree[root].first]){
                best[root]=tree[root].second;   //置为右子树
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n=0;
    scanf("%d",&n);
    getchar();
    int root=initTree();    //输入并构建树
    dfs(root);  //进行求解

    printf("%d\n",heigth[root]-1);  //因为默认一个节点高度为1所以减一
    //best中的就是最优路径
    while (root!=0)
    {
        printf("%d",root);
        root=best[root];    //走向下一个
        if(root!=0)printf(" "); //若下一个节点不是0则就还没到最后 打印空格
    }
    
    printf("\n");
    return 0;
}