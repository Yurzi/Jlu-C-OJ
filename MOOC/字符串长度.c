#include<stdio.h>
#define N 1024
int main(int argc, char const *argv[])
{
    char arr[N];
    char* p=NULL;
    int res=0;
    gets(arr);
    p=arr;

    while (*p!='\0')
    {
        p=p+1;
        res++;
    }
    
    printf("%d",res);

    return 0;
}
