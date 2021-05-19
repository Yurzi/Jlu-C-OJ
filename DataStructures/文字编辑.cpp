#include<iostream>

using namespace std;

struct node
{
	int prv;
	int next;
};

node list[10001];

void refresh(int n){
	for(int i=1;i<=n;++i){
		if(i==1){
			list[i].prv=n;
		}else{
			list[i].prv=i-1;
		}
		if(i==n){
			list[i].next=1;
		}else{
			list[i].next=i+1;
		}
	}
}
int main(int argc, char const *argv[])
{
	int t=0;
	scanf("%d",&t);
	while (getchar()!='\n')
	{
	}
	
	for (int i = 0; i <t; ++i)
	{
		int n=0,m=0;
		scanf("%d %d",&n,&m);
		while (getchar()!='\n')
		{
		}
		refresh(n);
		char ctemp=0;
		int ope1=0,ope2=0;
		for (int j = 0;j<m; ++j)
		{
			scanf("%c %d %d",&ctemp,&ope1,&ope2);
			while (getchar()!='\n')
			{
			}
			if(ctemp=='A'){
				//从链中摘除节点
				list[list[ope1].prv].next=list[ope1].next;
				list[list[ope1].next].prv=list[ope1].prv;
				//将节点加入链中到ope2之前
				list[ope1].prv=list[ope2].prv;
				list[ope1].next=ope2;
				list[list[ope1].prv].next=ope1;
				list[ope2].prv=ope1;
			}else if (ctemp=='B')
			{
				//从链上摘下节点
				list[list[ope1].prv].next=list[ope1].next;
				list[list[ope1].next].prv=list[ope1].prv;
				//将节点加入到链中，ope2之后
				list[ope1].prv=ope2;
				list[ope1].next=list[ope2].next;
				list[list[ope1].next].prv=ope1;
				list[ope2].next=ope1;
			}else if (ctemp=='Q')
			{
				if(ope1){
					printf("%d\n",list[ope2].next);
				}else{
					printf("%d\n",list[ope2].prv);
				}
			}
		}
	}
	return 0;
}
