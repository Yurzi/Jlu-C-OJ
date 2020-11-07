//求参加竞赛的人数
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int sum = 100;                //各年级总人数
    int x1 = 0, y1 = 0, sum1 = 0; //一年级及格人数和不及格人数
    int x2 = 0, y2 = 0, sum2 = 0; //二年级及格及不及格人数

    //一年级循环
    while (1)
    {
        //一年级部分
        x1 = 3 * y1 + 1;
        sum1 = x1 + y1;
        //二年级部分
        x2 = x1 + 5;
        //判断整除
        if (x2 % 6 == 0)
        {
            y2 = x2 / 6;
            sum2 = x2 + y2;

            if (sum1 <= sum && sum2 <= sum)
            {
                printf("%d\n", sum1 + sum2); //输出值
            }
        }
        if (sum1 > sum || sum2 > sum)
        {
            break;
        }

        y1++;
    }
    return 0;
}
