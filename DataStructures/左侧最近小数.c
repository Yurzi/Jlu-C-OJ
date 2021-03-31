#include<stdio.h>

#define SIZE 100001    

int main(int argc, char const *argv[])
{
    //栈
    int stack[SIZE]={0};
    int top=-1;
    int n=0;    //整数的个数
    
    scanf("%d",&n);
    getchar();

    //输入数据
    int i=0;
    int temp=0;
    while (i<n)
    {
        scanf("%d",&temp);
        //维护栈的单调性
        if(top==-1){
            printf("-1");//若栈空
            ++top;
            stack[top]=temp;
        }else{
            //若该元素大于栈顶元素,则输出栈顶元素,并入栈该元素
            if(temp>stack[top]){
                printf("%d",stack[top]);
                ++top;
                stack[top]=temp;
            }else{
                //否则则出栈栈首元素到要求
                while (top!=-1&&temp<=stack[top]){
                    --top;
                }
                //后打印栈首元素
                if(top==-1){
                    printf("-1");
                    ++top;
                    stack[top]=temp;
                }else{
                    printf("%d",stack[top]);
                    ++top;
                    stack[top]=temp;
                }
            }
        }
        if(i<n-1)printf(" ");
        ++i;
    }
    return 0;
}