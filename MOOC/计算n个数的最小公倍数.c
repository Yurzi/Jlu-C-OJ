#include<stdio.h>
#include<math.h>
//求最大公约数
int gcd(int x,int y){
    if (x%y==0)
    {
        return y;
    }else
    {
        return gcd(y,x%y);
    }
}
//求最小公倍数
int lcm(int x,int y){
    int gcd1=0;
    gcd1=gcd(x,y);
    return x*y/gcd1;
}
int main(int argc, char const *argv[])
{
    int flag=0;
    int key=0;
    int gcd1=0;
    int sum=1;
    int lcm1=0;
    //输入
    scanf("%d",&key);
    int arr[key];
    for (int i = 0; i < key; i++)
    {
        scanf(" %d",&arr[i]);
    }
    getchar();
    //求最大公约数
    /*gcd1=arr[0];
    for (int i = 1; i <=key; i++)
    {
        gcd1=gcd(gcd1,arr[i]);
    }*/
    //求最小公倍数
    lcm1=arr[0];
    for (int i = 0; i < key; i++)
    {
        lcm1=lcm(lcm1,arr[i]);
    }
    printf("%d",lcm1);
    return 0;
}
