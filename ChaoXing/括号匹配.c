#include <stdio.h>

int main(int argc, char const *argv[])
{
    //定义变量
    int i=0;
    char t;
    char kuohao[1024]={0};
    char temps[1024]={0};
    int flag=1;
    int top=0;
    //循环读入获得括号字符串
    while (1)
    {
        t = getchar();
        //判断并计数
        if (t == '@')
        {
            break;
        }
        else if (t == ' ')
        {
            
        }
        else
        {   
            switch (t)
            {
            case '{':kuohao[i]=t;i++;break;
            case '}':kuohao[i]=t;i++;break;
            case '[':kuohao[i]=t;i++;break;
            case ']':kuohao[i]=t;i++;break;
            case '(':kuohao[i]=t;i++;break;
            case ')':kuohao[i]=t;i++;break;
            default: continue;
            }
        }
    }

    //模拟栈，确保对数组的最上层top位进行操作，top变量类似指针的作用
        int k=0;
        while(k<i){
            if (kuohao[k]=='('||kuohao[k]=='['||kuohao[k]=='{'){
                //若为左括号则入“栈”
                temps[top]=kuohao[k];
                top++;
            }else{
                if(kuohao[k]==(temps[top-1]+1)||kuohao[k]==(temps[top-1]+2)){
                    //若右括号匹配到左括号则出栈左括号
                    temps[top]=0;
                    top--;//将指针右移
                }
            }
            k++;
        }
        //指针归零则证明栈空
        if(top==0){
            printf("YES");
        }else{
            printf("NO");
        }
    return 0;
}
