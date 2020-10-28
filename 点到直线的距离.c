#include<math.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
    float x,y,z,A,B,C,D;
    float temp1,temp2;
    float d;
    //输入
    scanf("%f %f %f",&x,&y,&z);
    scanf("%f %f %f %f",&A,&B,&C,&D);

    //计算
    temp1=fabs(A*x+B*y+C*z+1 );
    temp2=sqrt(A*A+B*B+C*C);

    d= temp1/temp2;

    //输出
    printf("%.3f",d);
    return 0;
}
