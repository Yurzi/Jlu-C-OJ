#include <stdio.h>
int main(){
	int n,d;
	scanf("%d %d",&n,&d);
	int a[1024],k=0;
	while(n){
		a[k]=n%d;
		n=n/d;
        k++;
	}
	for(int i=k-1;i>=0;i--){
		printf("%d",a[i]);
	}
	return 0;
}