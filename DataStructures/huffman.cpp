#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<bitset>

using namespace std;

class node{
    public:
        int weight;
        char info;
        bool visited;
        int left;
        int right;
        node(int _weight,char _info){
            weight=_weight;
            info=_info;
            left=-1;
            right=-1;
            visited=false;
        }
    /*bool operator < (const node & a) const
	{
		return weight>a.weight;
	}*/
};

int toCompress();
int toRelease();
int getMin(vector<node> &arr);
void DFS(vector<node> &tree,string &path,vector<pair<char,string>> &Map,int i);

int main(int argc, char const *argv[])
{
    int choice=0;
    //模式选择
    while (1)
    {
        printf("请选择模式：\n");
        printf("1.压缩 2.解压 0.退出\n");
        while (1!=scanf("%d",&choice))
        {
            fflush(stdin);
            printf("请重新输入\n");
        }
        if(choice!=0&&choice!=1&&choice!=2){
            printf("选择不支持\n");
            getchar();
            continue;
        }
        int staus=0;
        if(choice==0){
            break;
        }else if(choice==1){
            staus=toCompress();
            if(staus==-1)continue;
            printf("压缩成功\n");
        }else if (choice==2){
            staus=toRelease();
            if(staus==-1)continue;
            printf("解压成功\n");
        }
    }
    return 0;
}
//压缩
int toCompress(){
    //读取文件路径
    system("cls");
    fflush(stdin);
    printf("请输入文件路径(可直接拖拽文件到此窗口)\n");
    string address="";
    getline(cin,address);
    FILE *fp=fopen(address.c_str(),"r");
    if(fp==NULL){
        fclose(fp);
        printf("文件不存在！\n");
        Sleep(200);
        return -1;
    }
    //统计字符
    vector<node> arr;
    char ctemp=0;
    bool isnoexist=true; //标记是否不存在
    while (!feof(fp))
    {
        isnoexist=true;
        ctemp=fgetc(fp);
        //检查并计数字符
        for(int i=0;i<arr.size();++i){
            if(arr[i].info==ctemp){
                ++arr[i].weight;
                isnoexist=false;
            }
        }
        if (isnoexist&&ctemp!=-1)
        {
            node *temp=new node(1,ctemp);
            arr.push_back(*temp);
            delete temp;
        }
    }
    //建立哈夫曼树
    int a=0;
    int b=0;
    while (1)
    {
        a=getMin(arr);
        arr[a].visited=true;
        b=getMin(arr);
        if(b==-1)break;
        arr[b].visited=true;

        node *temp=new node(arr[a].weight+arr[b].weight,-1);
        if(arr[a].weight>=arr[b].weight){
            temp->left=a;
            temp->right=b;
        }else{
            temp->left=b;
            temp->right=a;
        }
        arr.push_back(*temp);
        delete temp;
    }
    //生成编码表
    vector<pair<char,string>> map;
    string path;
    //遍历树
    DFS(arr,path,map,a);
    //压缩文件
    rewind(fp);
    fstream outfile("out.xjh",ios::out|ios::binary);
    //将内容编码
    string codestream;
    while (!feof(fp))
    {
        ctemp=fgetc(fp);
        if(ctemp==-1)break;
        for (int i = 0; i < map.size(); ++i)
        {
            if(ctemp==map[i].first){
                codestream+=map[i].second;
            }
        }
    }
    fclose(fp);
    //写入树信息
    outfile<<static_cast<int>(a)<<static_cast<char>(' ')<<static_cast<int>(arr.size())<<static_cast<char>(' ');
    for(int i=0;i<arr.size();++i){
        outfile<<arr[i].weight<<"~"<<static_cast<int>(arr[i].info)<<"~"<<arr[i].left<<"~"<<arr[i].right<<" ";
    }
    //outfile<<static_cast<char>('<');
    while (codestream.size()>=8)
    {
        bitset<8> bits(codestream,0,8);
        codestream.erase(0,8);
        outfile<<static_cast<char>(bits.to_ulong());
    }
    if(!codestream.empty())   //结尾长度不够八位，用0补齐，记录剩余的长度将其放在文件末尾，在读取时转换为下标位置还原本来的字符串
    {
        unsigned long loc = codestream.size();
        bitset<8> bits(codestream,0,loc);
        outfile << static_cast<char>(bits.to_ulong());
        outfile << static_cast<char>(loc);
    }
    outfile.close();

    //计算压缩比
    FILE *origin=fopen(address.c_str(),"rb");
    fseek(origin,0,SEEK_END);
    long orginsize=ftell(origin);
    fclose(origin);

    FILE *out=fopen("out.xjh","rb");
    fseek(out,0,SEEK_END);
    long outsize=ftell(out);
    fclose(out);

    double rate=(double)outsize/orginsize;
    printf("压缩率为：%.2lf%%",rate*100);
    printf("%\n");


    return  0;
}
//解压
int toRelease(){
    //读取文件路径
    system("cls");
    fflush(stdin);
    printf("请输入文件路径(可直接拖拽文件到此窗口)\n");
    string address="";
    getline(cin,address);
    fstream infile(address,ios::in|ios::binary);
    if (infile.bad())
    {
        infile.close();
        printf("文件不存在！\n");
        Sleep(200);
        return -1;
    }
    //文件存在
    //从文件中读入哈夫曼树
    int root=0;
    int n=0;
    char ctemp;
    int weight,left,right,info_n;
    char info;
    infile>>root;
    infile.read(&ctemp,1);
    infile>>n;
    infile.read(&ctemp,1);
    string strline;
    vector<node> tree;
    for (int i = 0; i < n; ++i)
    {
        strline.clear();
        infile>>strline;
        infile.read(&ctemp,1);
        sscanf(strline.c_str(),"%d~%d~%d~%d",&weight,&info_n,&left,&right);
        info=(char)info_n;
        node *temp=new node(weight,info);
        temp->left=left;
        temp->right=right;
        tree.push_back(*temp);
        delete temp;
    }
    //infile.read(&ctemp,1);
    string codestream;
    bitset<8> temp;
    while (1)
    {
        if(infile.peek()==EOF){
            break;
        }
        infile.read(&ctemp,1);
        temp=ctemp;
        codestream+=temp.to_string();
    }

    string end = codestream.substr(codestream.size()-16,16);  //处理末尾不够八位的情况
    bitset<8> loc(end,8,16);  
    unsigned long add = loc.to_ulong();
    if(add<8){
        end = end.substr(8-add,add);
        codestream.erase(codestream.size()-16,codestream.size());
        codestream += end;
    }
    fstream outfile("out.txt",ios::out);
    int p=root;
    for (auto i:codestream)
    {
        if(i=='0'){
            p=tree[p].left;
        }
        if (i=='1')
        {
            p=tree[p].right;
        }
        if (tree[p].left==-1&&tree[p].right==-1)
        {
            outfile<<tree[p].info;
            p=root;
        }   
    }
    return 0;
}

//找到权值最小的
int getMin(vector<node> &arr){
    bool flag=true;
    int min=-1;
    for (int i = 0; i < arr.size(); ++i)
    {
        if(flag&&!arr[i].visited){
            min=i;
            flag=false;
        }
        if(!flag){
            if(!arr[i].visited&&(arr[i].weight<arr[min].weight)){
                min=i;
            }
        }
    }
    return min;
}
void DFS(vector<node> &tree,string &path,vector<pair<char,string>> &Map,int i){
    if(tree[i].left==-1&&tree[i].right==-1){
        pair<char,string> temp;
        temp.first=tree[i].info;
        temp.second=path;
        Map.push_back(temp);
        return ;
    }
    if(tree[i].left>=0){
        path+="0";
        DFS(tree,path,Map,tree[i].left);
        path.pop_back();
    }
    if(tree[i].right>=0){
        path+="1";
        DFS(tree,path,Map,tree[i].right);
        path.pop_back();
    }
}