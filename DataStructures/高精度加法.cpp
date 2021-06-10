#include<iostream>
#include<string>
#define N 111
using namespace std;


void add(int x[],int y[],int z[]){
    for(int i=0;i<N;++i){
        z[i+1]=(x[i]+y[i]+z[i])/10;
        x[i]=(x[i]+y[i]+z[i])%10;
    }
}

int a[N]={0};
int b[N]={0};
int t[N]={0};
string temp;
int main(int argc, char const *argv[])
{
    temp.clear();
    int n=0;
    cin>>n;
    for(int i=0;i<n;++i){
        int j=0;
        cin>>temp;
        for (int i = temp.size()-1; i>=0; --i)
        {
            b[j]=temp[i]-48;
            ++j;
        }
        add(a,b,t);
        for(int i=0;i<j;++i){
            b[i]=0;
        }
    }
    bool flag=true;
    for(int i=N-1;i>=0;--i){
        if(flag&&a[i]!=0){
            printf("%d",a[i]);
            flag=false;
        }else if (!flag)
        {
            printf("%d",a[i]);
        }
    }
    printf("\n");
    return 0;
}
