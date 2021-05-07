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
    //ģʽѡ��
    while (1)
    {
        printf("��ѡ��ģʽ��\n");
        printf("1.ѹ�� 2.��ѹ 0.�˳�\n");
        while (1!=scanf("%d",&choice))
        {
            fflush(stdin);
            printf("����������\n");
        }
        if(choice!=0&&choice!=1&&choice!=2){
            printf("ѡ��֧��\n");
            getchar();
            continue;
        }
        int staus=0;
        if(choice==0){
            break;
        }else if(choice==1){
            staus=toCompress();
            if(staus==-1)continue;
            printf("ѹ���ɹ�\n");
        }else if (choice==2){
            staus=toRelease();
            if(staus==-1)continue;
            printf("��ѹ�ɹ�\n");
        }
    }
    return 0;
}
//ѹ��
int toCompress(){
    //��ȡ�ļ�·��
    system("cls");
    fflush(stdin);
    printf("�������ļ�·��(��ֱ����ק�ļ����˴���)\n");
    string address="";
    getline(cin,address);
    FILE *fp=fopen(address.c_str(),"r");
    if(fp==NULL){
        fclose(fp);
        printf("�ļ������ڣ�\n");
        Sleep(200);
        return -1;
    }
    //ͳ���ַ�
    vector<node> arr;
    char ctemp=0;
    bool isnoexist=true; //����Ƿ񲻴���
    while (!feof(fp))
    {
        isnoexist=true;
        ctemp=fgetc(fp);
        //��鲢�����ַ�
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
    //������������
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
    //���ɱ����
    vector<pair<char,string>> map;
    string path;
    //������
    DFS(arr,path,map,a);
    //ѹ���ļ�
    rewind(fp);
    fstream outfile("out.xjh",ios::out|ios::binary);
    //�����ݱ���
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
    //д������Ϣ
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
    if(!codestream.empty())   //��β���Ȳ�����λ����0���룬��¼ʣ��ĳ��Ƚ�������ļ�ĩβ���ڶ�ȡʱת��Ϊ�±�λ�û�ԭ�������ַ���
    {
        unsigned long loc = codestream.size();
        bitset<8> bits(codestream,0,loc);
        outfile << static_cast<char>(bits.to_ulong());
        outfile << static_cast<char>(loc);
    }
    outfile.close();

    //����ѹ����
    FILE *origin=fopen(address.c_str(),"rb");
    fseek(origin,0,SEEK_END);
    long orginsize=ftell(origin);
    fclose(origin);

    FILE *out=fopen("out.xjh","rb");
    fseek(out,0,SEEK_END);
    long outsize=ftell(out);
    fclose(out);

    double rate=(double)outsize/orginsize;
    printf("ѹ����Ϊ��%.2lf%%",rate*100);
    printf("%\n");


    return  0;
}
//��ѹ
int toRelease(){
    //��ȡ�ļ�·��
    system("cls");
    fflush(stdin);
    printf("�������ļ�·��(��ֱ����ק�ļ����˴���)\n");
    string address="";
    getline(cin,address);
    fstream infile(address,ios::in|ios::binary);
    if (infile.bad())
    {
        infile.close();
        printf("�ļ������ڣ�\n");
        Sleep(200);
        return -1;
    }
    //�ļ�����
    //���ļ��ж����������
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

    string end = codestream.substr(codestream.size()-16,16);  //����ĩβ������λ�����
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

//�ҵ�Ȩֵ��С��
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