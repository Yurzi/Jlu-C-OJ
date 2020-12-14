#include<stdio.h>
#define N 2
//复数类型
typedef struct complex 
{
    double real;
    double imagine;
}complex;

void complexInput(complex*);
void complexDisplay(complex*);
complex complexCal(complex a,complex b,int n);

int main(int argc, char const *argv[])
{
    int n=2;
    complex arr[N]; //存放输入
    complex res[3]; //暂存结果
    //输入
    for (int i = 0; i <n; i++)
    {
        complexInput(&arr[i]);
    }
    //计算并输出
    for (int i = 0; i < 3; i++)
    {
        res[i]=complexCal(arr[0],arr[1],i);
        complexDisplay(&res[i]);
        if (i<2)
        {
            printf("    ");
        }
    }   
    return 0;
}
//输入函数
void complexInput(complex* a){
    scanf("%lf %lf",&(a->real),&(a->imagine));
    getchar();
    return;
}
//输出函数
void complexDisplay(complex* a){
    if (a->imagine==0)
    {
        printf("%.2lf",a->real);
        return;
    }else
    {
        if (a->imagine<0)
        {
            printf("%.2lf-%.2lfi",a->real,-(a->imagine));
            return;
        }else
        {
            printf("%.2lf+%.2lfi",a->real,a->imagine);
            return;
        }  
    }
    
}
//计算函数，用数字控制
complex complexCal(complex a,complex b,int n){
    complex res;
    if (n==0)
    {
        res.real=a.real+b.real;
        res.imagine=a.imagine+b.imagine;
        return res;
    }
    if (n==1)
    {
        res.real=a.real-b.real;
        res.imagine=a.imagine-b.imagine;
        return res;
    }
    if (n==2)
    {
        res.real=(a.real)*(b.real)-(a.imagine)*(b.imagine);
        res.imagine=(a.real)*(b.imagine)+(b.real)*(a.imagine);
        return res;
    }
}