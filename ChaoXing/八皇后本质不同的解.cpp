#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int ans=0,n;
int nhangyouhuanghou[20]={0},gailiehuanghouhanghao[20];
struct quanbujie{
	int booll,xx[20];
}a[100];
void nhuanghou(int lie){
	if(lie==n+1){
		ans++;
		for(int i=1;i<=n;i++){
			a[ans].xx[i]=gailiehuanghouhanghao[i];
		}
		return;
	}
	int flag;
	for(int i=1;i<=n;i++){//第i行 
		if(!nhangyouhuanghou[i]){//第i行还没有皇后 
			flag=1;//表示未发生冲突 
			for(int zhiqian=1;zhiqian<lie;zhiqian++){//遍历之前的皇后 
				if(abs(lie-zhiqian)==abs(i-gailiehuanghouhanghao[zhiqian])){//对角线 第lie列行号为i，第zhiqian列行号为gailiehuanghouhanghao[zhiqian] 
					flag=0;//发生冲突 
					break;
				}
			}
			if(flag){//如果没有冲突 
				gailiehuanghouhanghao[lie]=i;//第lie列行号为i
				nhangyouhuanghou[i]=1;//第i行已经有皇后
				nhuanghou(lie+1);//下一列 
				nhangyouhuanghou[i]=0;//恢复，第i行再次没有皇后了 
			}
		}
	}
}
bool cmp(const struct quanbujie &x,const struct quanbujie &y){
	return x.xx[1]<y.xx[1];
}
int main(){
	n=8;
	nhuanghou(1);//从第一列开始  
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=ans;i++){
		a[i].booll=1;
	}
	for(int i=1;i<ans;i++){
		for(int j=i+1;j<=ans;j++){
			if(a[j].booll){
				for(int k=1;k<=n;k++){
					if(k!=a[j].xx[a[i].xx[k]]){
						a[j].booll=1;
						break;
					}else a[j].booll=0;
				}
				if(!a[j].booll)break;//主对角线
				
				for(int k=1;k<=n;k++){
					if(k+a[j].xx[n+1-a[i].xx[k]]!=n+1){
						a[j].booll=1;
						break;
					}else a[j].booll=0;
				}
				if(!a[j].booll)break;//副对角线  
				
				for(int k=1;k<=n;k++){
					if(a[i].xx[k]!=a[j].xx[n+1-k]){
						a[j].booll=1;
						break;
					}else a[j].booll=0;
				}
				if(!a[j].booll)break;//左右
				
				
				for(int k=1;k<=n;k++){
					if(a[i].xx[k]+a[j].xx[k]!=n+1){
						a[j].booll=1;
						break;
					}else a[j].booll=0;
				}
				if(!a[j].booll)break;//上下 
				
				for(int k=1;k<=n;k++){
					if(a[i].xx[k]+a[j].xx[n+1-k]!=n+1){
						a[j].booll=1;
						break;
					}else a[j].booll=0;
				}
				if(!a[j].booll)break;//旋转180°
					
				for(int k=1;k<=n;k++){
					if(k+a[j].xx[a[i].xx[k]]!=n+1){
						a[j].booll=1;
						break;
					}else a[j].booll=0;
				}
				if(!a[j].booll)break;//逆时针旋转90°
					
				for(int k=1;k<=n;k++){
					if(k!=a[j].xx[n+1-a[i].xx[k]]){
						a[j].booll=1;
						break;
					}else a[j].booll=0;
				}
				if(!a[j].booll)break;//逆时针旋转270°	
			}
		}
	}
	int jishu=0;
	for(int i=1;i<=ans;i++){
		if(a[i].booll){
			if(jishu)printf("\n");
			printf("No%d:",++jishu);
			for(int j=1;j<=n;j++){
				printf("%d ",a[i].xx[j]);
			}
			
		}
	}
	return 0;
}