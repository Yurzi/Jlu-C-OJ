#include<stdio.h>
#include<math.h>

void toPrint(int n,int k){
    if (k>0)
    {
        int num=n/powf(10,k-1);
        n=n-num*powf(10,k-1);
        printf("%d\n",num);
        return toPrint(n,k-1);
    }
}

int main(int argc, char const *argv[])
{
    int n=0;
    int temp=0;
    int k=0;
    scanf("%d",&n);
    temp=n;
    while (temp>0)
    {
        temp=temp/10;
        k++;
    }
    
    toPrint(n,k);
    return 0;
}
