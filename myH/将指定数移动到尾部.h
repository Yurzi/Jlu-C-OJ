#include <stdio.h>

int main(int argc, char const *argv[]){
    int A[17] = {3, 3, 0, 7, 2, 4, 2, 0, 0, 2, 0, 3, 1, 0, 7, 6, 1};
    int i = 0;
    int j = 0;          //标记两端
    int item = 3;       //item
    int flag_first = 0; //找到第一个的标记
    int flag_isext = 0; //默认不存在
    int flag_cont = 0;  //是否为连续
    int m = 0;          //记录连续的个数
    while (1){
        //初始化
        flag_isext = 0;
        flag_first = 0;
        flag_cont = 0;
        m = 0;
        //寻找item
        for (int k = 0; k < 17; k++){
            if (A[k] == item){
                flag_isext = 1; //若找到一个则存在
                //若是第一个
                if (!flag_first){
                    i = k;          //将位置记下
                    flag_first = 1; //标记找到第一个
                    m = 1;
                    flag_cont = 1; //标记开始记录连续
                    j = 16;        //默认另一端位最后
                }
                else{
                    //若不是第一个
                    j = k;
                    if (flag_cont){
                        ++m;
                        if (j == 16){
                            flag_isext = 0;
                            break;
                        }
                    }
                    else{
                        if (j == 16){
                            flag_isext = 0;
                            break;
                        }
                        break;
                    }
                }
            }
            else{
                flag_cont = 0; //若不是0则关闭监听
            }
        }
        //若全部找完
        if (flag_isext == 0){
            //将表中空闲的所有元素置空
            for (int k = i; k <= j; k++){
                A[k] = -1; //认为-1为空
            }
            break;
        }
        //删除
        if (flag_first){
            for (int k = i; k < j; k++){
                A[k] = A[k + m];
                A[k + m] = item;
            }
        }
    }
    return 0;
}