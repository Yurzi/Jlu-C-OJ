//计算多边形周长
#include<stdio.h>
#include<math.h>
//计算2点间距离
double getlength(double x1,double y1,double x2,double y2){
    double x=x1-x2,y=y1-y2;
    double result=0;
    result=sqrt(x *x + y *y);
    return result;
}
int main(int argc, char const *argv[])
{
    int n=0;    //存储顶点数
    double a[10],b[10];
    double sum = 0.0;
    //输入
    scanf("%d",&n);
    getchar();
    
    for(int i = 0; i < n; i++){
        
        scanf("%lf %lf",&a[i],&b[i]);
        getchar();
    }
    if(n<2){
        printf("0.00");
        return 0;
    }

    //计算周长
    //余下从头到尾
    for (int i = 0; i < n-1; i++) {
        sum +=getlength(a[i],b[i],a[i+1],b[i+1]);
    }
    if(n>2){
        sum += getlength(a[0],b[0],a[n-1],b[n-1]);
    }
    
    printf("%.2lf",sum);


    return 0;
}
