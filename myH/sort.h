//均从小到大排序

//主元选择排序
void mainSort(int arr[],int n){
    int j;int r;
    for(int i=0;i<n-1;i++){
        j=i;
        for(int k=i+1;k<n;k++){
            if(arr[k]<arr[j]){
                j=k;
            }
            r=arr[i];
            arr[i]=arr[j];
            arr[j]=r;
        }
    }
}
//冒泡排序
void BubbleSort(int arr[],int n){
    int flag=1;//标识是否进行交换
    int t=0;
    while(flag){
        flag=0;//默认不存在交换 并扫描一次
        //扫描
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1])//如果前项大于后项怎后移
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
//插入排序
void InsertSort(int arr[],int n){
    int point;int temp;
    for(int i=1;i<n;i++)//排第i个元素
    {
        point=i-1;//先指向该元素前一位
        while(arr[point]>arr[i]&&point>=0)//判断所指的元素是否大于该元素,若大于则证明point还应左移寻找小于先元素的数
        {
            point=point-1;
        }
        temp=arr[i];//记录该元素
        //向后窜(移动point后和i之间的元素使其向后移动)
        for(int k=i;k>point+1;k--){
            arr[k]=arr[k-1];
        }
        //将该元素插入留出的空位
        arr[point+1]=temp;
    }
}
//快速排序
void QuickSort(int *arr, int low, int high)
{
    int i = low;
    int j = high;
    int key = arr[low];
    if (low >= high)  //如果low >= high说明排序结束了
    {
        return ;
    }
    while (low < high)  //该while循环结束一次表示比较了一轮
    {
        while (low < high && key <= arr[high])
        {
            --high;  //向前寻找
        }
        if (key > arr[high])
        {
            arr[low] = arr[high];  //直接赋值, 不用交换
            ++low;
        }
        while (low < high && key >= arr[low])
        {
            ++low;  //向后寻找
        }
        if (key < arr[low])
        {
            arr[high] = arr[low];  //直接赋值, 不用交换
            --high;
        }
    }
    arr[low] = key;  //查找完一轮后key值归位, 不用比较一次就互换一次。此时key值将序列分成左右两部分
    QuickSort(arr, i, low-1);  //用同样的方式对分出来的左边的部分进行同上的做法
    QuickSort(arr, low+1, j);  //用同样的方式对分出来的右边的部分进行同上的做法
}