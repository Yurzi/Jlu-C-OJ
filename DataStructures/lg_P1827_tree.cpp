#include<iostream>
#include<vector>

using namespace std;

struct node
{
    char info;
    int left;
    int right;
    node(char _c,int _left, int _right){
        info=_c;
        left=_left;
        right=_right;
    }
};

vector<node> postOrder;
vector<node> inOrder;
int count=-1;


int createTreebyPostAndIn(int l,int r){
    int root=-1;
    if(l<=r){
        ++count;
        for(int i=l;i<=r;++i){
            if(inOrder[i].info==postOrder[count].info){
                root=i;
                break;
            }
        }
        if(count<postOrder.size()&&root>-1){
            inOrder[root].left=createTreebyPostAndIn(l,root-1);
            inOrder[root].right=createTreebyPostAndIn(root+1,r);
        }
    }
    return root;
}

void printafterOrder(int i){
    if(i==-1){
        return;
    }
    printafterOrder(inOrder[i].left);
    printafterOrder(inOrder[i].right);

    printf("%c",inOrder[i].info);
    return;
}



int main(int argc, char const *argv[])
{
    char ctemp=0;
    while ((ctemp=getchar())!='\n')
    {
        if(ctemp!=' ')inOrder.push_back(node(ctemp,-1,-1));
    }

    while ((ctemp=getchar())!='\n'&&ctemp!=' ')
    {
        if(ctemp!=' ')postOrder.push_back(node(ctemp,-1,-1));
    }

    int root=createTreebyPostAndIn(0,inOrder.size()-1);

    printafterOrder(root);

    return 0;
}
