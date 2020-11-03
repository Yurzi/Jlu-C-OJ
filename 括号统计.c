#include <stdio.h>
int main(int argc, char const *argv[])
{
    //定义变量
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
    char t;
    //循环读入
    while (1)
    {
        t = getchar();
        //判断并计数
        if (t == '@')
        {
            break;
        }else if (t==' ')
        {
            continue;
        }else
        {
            switch (t)
            {
            case '{':a1++;break;
            case '}':a2++;break;
            case '[':b1++;break;
            case ']':b2++;break;
            case '(':c1++;break;
            case ')':c2++;break;
            default: continue;
            }
        }
    }

    //判断是否相等并输出结果
    if (a1!=a2)
    {
        printf("{}");
    }
    if (b1!=b2)
    {
        printf("[]");
    }
    if (c1!=c2)
    {
        printf("()");
    }
    if (a1==a2&&b1==b2&&c1==c2)
    {
        printf("NULL");
    }
    
    //printf("%d %d %d %d %d %d",a1,a2,b1,b2,c1,c2);
    return 0;
}
