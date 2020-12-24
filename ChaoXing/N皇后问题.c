#include <stdio.h>
#include <math.h>

int n = 0;          //存储棋盘大小
int res[16] = {-1}; //存储对应行的皇后列数
int count = 0;      //记录总方法数

//在第n行找皇后的位置
void tosolve(int line)
{
    //一列列搜索
    for (int i = 1; i <=n; i++)
    {
        if (line != 1 && i == res[line - 1])
            continue;
        int flag = 1;
        for (int j = 1; j <line; j++)
        {
            if (i == res[j] || (abs(line - j)) == (abs(i - res[j])))
            {
                flag = 0; //同一列、同一对角线拒绝
                break;
            }
        }
        if (flag)
        {
            res[line] = i; //记录下这行所对应的皇后的列数
            if (line == n)
            {
                count++;
                /*for (int j = 0; j < n; j++)
                {
                    printf("%d ",res[j]);
                }*/
                //printf("\n");
                return;
            }
            //若没放满则放下一行
            tosolve(line + 1);
            res[line] = -1;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    //输入棋盘大小
    scanf("%d", &n);
    //从第1行开始
    tosolve(1);
    //输出
    printf("%d", count);

    return 0;
}
