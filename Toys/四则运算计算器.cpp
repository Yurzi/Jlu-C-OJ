#include<iostream>
#include<stack>
#define N 128

using namespace std;

int main(int argc, char const *argv[])
{
    char t=0;
    char tmp=0;
    stack<char> singals;
    stack<char> temp;
    while (scanf("%c",&tmp)==1)
    {   
        //将中缀表示法转换为后缀表示法
        //预处理加减乘除的优先级
		if (tmp=='(')tmp=1;
		if (tmp==')')tmp=2;
        if (tmp=='+')tmp=11;
		if (tmp=='-')tmp=12;
		if (tmp=='*')tmp=21;
		if (tmp=='/')tmp=22;


        //进行转换操作
        //若为数字直接输出，否则判断与符号栈顶的优先级
        if (tmp>='0'&&tmp<='9')
        {
            printf("%c",tmp);
        }else
        {
            //若栈空则入栈
            if (singals.empty())
            {
                //不合法输入
                if (tmp==2)
                {
                    printf("输入不合法");
                    exit(-1);
                }
                singals.push(tmp);
            }else
            {
				//若为左括号则人栈
                if (tmp==1)
                {
                    singals.push(tmp);
					continue;
                }
                //若现符号优先级高于或等于栈顶符号优先级则入栈
                if ((tmp+1)>=singals.top())
                {
                    singals.push(tmp);
					continue;
                }
                //若该元素优先级低于栈顶元素,或者遇到右括号，则出栈至左括号处或至空
                if ((tmp+1)<singals.top()||tmp==2)
                {
                    while (singals.top()!=1&&!(singals.empty()))
                    {
                        if(singals.top()==11){printf("+");singals.pop();}
                        if(singals.top()==12){printf("-");singals.pop();}
                        if(singals.top()==21){printf("*");singals.pop();}
                        if(singals.top()==22){printf("/");singals.pop();}
                    }
					//将这个符号置入栈
					if (tmp!=2)
					{
						singals.push(tmp);
					}
					
                }
            }
        }
    }

    //结束后清空符号栈
    while (!(singals.empty()))
    {
        if(singals.top()==1){printf("+");singals.pop();}
        if(singals.top()==2){printf("-");singals.pop();}
        if(singals.top()==11){printf("*");singals.pop();}
        if(singals.top()==12){printf("/");singals.pop();}
    }
    
    


    return 0;
}
