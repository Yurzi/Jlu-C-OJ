#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],b[N], dp[N];;
int n ;
int ans ;
const int INF = 0x3f3f3f; 

int main()
{
	int n;
	cout<<"please input size"<<endl;
	cin>>n;
	cout<<"please input data"<<endl;
	for(int i =1;i<=n;++i)
	{
		cin>>a[i];
	}
	dp[1] = a[1];
	int ans =0;
	for(int i =2;i<=n;++i)
	{
		if(dp[i-1]>0)
			dp[i] =dp[i-1] + a[i];
		else
			dp[i] = a[i];
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;

	 system("pause");
    return 0;
   
}