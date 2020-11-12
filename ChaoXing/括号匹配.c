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
    //循环读入
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

        int k=0;
        while(k<i){
            if (kuohao[k]=='('||kuohao[k]=='['||kuohao[k]=='{'){
                temps[top]=kuohao[k];
                top++;
            }else{
                if(kuohao[k]==(temps[top-1]+1)||kuohao[k]==(temps[top-1]+2)){
                    temps[top]=0;
                    top--;
                }
            }
            k++;
        }
        if(top==0){
            printf("YES");
        }else{
            printf("NO");
        }
    return 0;
}
