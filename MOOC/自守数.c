#include<stdio.h>
#include<math.h>

//获取一个自然数的位数
int getDigits(int n){
    int k=0;
    while (1)
    {
        n=n/10;
        k++;
        if (n==0)
        {
            return k;
        }
        
    }
}
//判断是否为自守数
int isRes(int n){
    int t=n*n-n;
    if (t%(int)powf(10,getDigits(n))==0)
    {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int n=0;
    scanf("%d",&n);
    int flag=0;
    for (int i = 1; i <=n; i++)
    {
        if (isRes(i))
        {
            if (flag)
            {
                printf("\n");
            }else
            {
                flag=1;
            }        
            printf("%d",i);
        }
        
    }
    return 0;
}
