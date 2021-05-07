#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

//当前已知最长路长度
int maxlen;	

//temp是用于暂存路径的数组，ans为最终搜索到的最长路
int temp[100005],ans[100005];

//in数组记录每个点的入度，用于查找源点
int in[100005];	 

//End数组用于记录该点的是否为终点
bool End[100005];

//前向星建图
int cur,head[100005];
struct Edge{
	int nxt,to;
}edge[100005];
void build(int u,int v){
	edge[++cur].nxt=head[u];
	edge[cur].to=v;
	head[u]=cur;
}

//递归搜索每条道路
void dfs(int len,int e){//len代表当前路径长，e为当前所在节点
	if(End[e]){	//当前结点已经是某条路径的终点
		if(maxlen<len){	//若最大路径长度小于当前路径，更新
			maxlen=len;
			for(int i=0;i<len;++i)//更新ans数组
				ans[i]=temp[i];
		}
		return ;
	}

	for(int i=head[e];i;i=edge[i].nxt){
		temp[len-1]=edge[i].to;	//先将路径暂存在temp数组中
		dfs(len+1,edge[i].to);	//递归查找下一个结点
	}
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k,a[10005],s;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>k;

		//k为0说明该病毒不能变异成别的什么了，即为路径终点
		if(k==0)	//变更End状态为true
			End[i]=true;
		for(int j=0;j<k;++j)
			cin>>a[j];
		
		//由于是前向星建图所以要先将结点从大到小排序后建图才能做到先搜结点小的边
		//greater<int>()让sort可以从大到小排序而非从小到大
		sort(a,a+k,greater<int>());

		for(int j=0;j<k;++j){
			++in[a[j]];	//入度自增一
			build(i,a[j]);//前向星建图
		}
	}
	for(int i=0;i<n;++i){
		if(!in[i]){//说明没有父节点，该点为源点
			s=i;
			break;
		}//由于题目说了只有一个源点，所以找到一个源点即可跳出循环
	}
	dfs(1,s);//初始长度为1，源点是s
	cout<<maxlen<<endl;

	//由于在递归过程中并不会经过源点，所以ans数组中是没有源点的，所以在这里直接输出源点
	cout<<s;
	for(int i=1;i<maxlen;++i){//格式控制，防止最后有多余的空格
		cout<<" "<<ans[i-1];
	}
}