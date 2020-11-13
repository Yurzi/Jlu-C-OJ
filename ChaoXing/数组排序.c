#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n=10;
    int a[10],b[10],c[10];
    int swap=0,comp=0;
    //输入
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];c[i]=a[i];
        getchar();
    }

    //主元排序
    int j,r;
    for(int i=0;i<n-1;i++){
        j=i;
        for(int k=i+1;k<n;k++){
            comp++;
            if(a[k]<a[j]){
                j=k;
            }     
        }
        r=a[i];
        a[i]=a[j];
        a[j]=r;
        swap++;
    }
    printf("%d %d ",comp,swap);
    

    //冒泡排序
    comp=0;swap=0;
    int flag=1;//标识是否进行交换
    int t=0;
    int i=0;
    while(flag){
        flag=0;//默认不存在交换 并扫描一次
        //扫描
        for(i=0;i<n-1;i++){
            comp++;
            if(b[i]>b[i+1])//如果前项大于后项怎后移
            {   
                //交换
                t=b[i+1];
                b[i+1]=b[i];
                b[i]=t;
                //标记存在交换
                flag=1;
                swap++;
            }
        }
    }
    printf("%d %d ",comp,swap);

    //插入排序
    comp=0;swap=0;
    int point;int temp;
    for(int i=1;i<n;i++)//排第i个元素
    {
        point=i-1;//先指向该元素前一位
        
        while(c[point]>c[i]&&point>=0)//判断所指的元素是否大于该元素,若大于则证明point还应左移寻找小于先元素的数
        {
            point=point-1;
            comp++;
            
        }
        comp++;//用于记录while循环未进入的比较次数
        
        temp=c[i];//记录该元素
        //向后窜(移动point后和i之间的元素使其向后移动)
        for(int k=i;k>point+1;k--){
            c[k]=c[k-1];
            swap++;
        }
        //将该元素插入留出的空位
        c[point+1]=temp;
        if(point+1!=i)swap++;//用于记录不是该元素本身时插入的次数
    }

    printf("%d %d",comp,swap);

    return 0;
}
