#include<stdio.h>
#include <string.h>
#define N 255
int main(int argc, char const *argv[])
{
    char arr[N]={0};
    gets(arr);
    for(int i=strlen(arr)-1;i>=0;i--){
        printf("%c",arr[i]);
    }
    return 0;
}
