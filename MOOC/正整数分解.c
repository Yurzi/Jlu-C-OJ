#include<stdio.h>
#define N 16
#define L 256
int line=0;
int finalres[L][N];
int res[N];
int scanNum=0;

//深度比较
int arrcmp(int *a,int *b){
    if (*a>*b)
    {
        return 1;
    }
    if (*a<*b)
    {
        return -1;
    }
    return arrcmp(a-1,b-1);
}


//排序算法
void BubbleSort(int* arr[],int n){
    int flag=1;//标识是否进行交换
    int* t=NULL;
    while(flag){
        flag=0;//默认不存在交换 并扫描一次
        //扫描
        for(int i=0;i<n-1;i++){
            int a=arr[i][0];
            int b=arr[i+1][0];
            if(arrcmp(&(arr[i][a]),&(arr[i+1][b]))==-1)//如果前项大于后项怎后移
            {   
                //交换
                t=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=t;
                //标记存在交换
                flag=1;
            }
        }
    }
}

//主要题解函数
/*
将一个数完全展开，然后从后面逐渐缩叠
5=1+1+1+1+1
5=1+1+1+2
5=1+1+3
...
*/
void resolve(int k, int num) {
        int rest = 0;
        for (int i = 1; i <= num; i++) {
            // 避免重复
            if (i < res[k - 1]) continue;
            // 去掉6=6这种情况
            if (i == scanNum) continue;
            res[k] = i;
            rest = num - i;
            // 递归终止条件 拆分结束
            if (rest == 0) {
                for (int j = k; j > 1; j--) {
                    finalres[line][j]=res[j];
                }
                finalres[line][1]=res[1];
                finalres[line][0]=k;
                line++;
                continue;
            }
            resolve(k + 1, rest);
        }
}

int main(int argc, char const *argv[])
{
    scanf("%d",&scanNum);
    resolve(1,scanNum);
    if(scanNum==1){
        printf("1=1\n");
    }
    //对fianlres数组进行排序
    int *arr[L]={NULL};
    for (int i = 0; i < line; i++)
    {
        arr[i]=finalres[i];
    }


    BubbleSort(arr,line);


    for (int i = 0; i < line; i++)
    {
        printf("%d=",scanNum);
        for (int j = arr[i][0]; j >1; j--)
        {
            printf("%d+",arr[i][j]);
        }
        printf("%d\n",arr[i][1]);
        
    }

    return 0;
}
