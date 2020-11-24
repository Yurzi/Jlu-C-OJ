#include<stdio.h>
#define N 1024
int main(int argc, char const *argv[])
{
    char str1[N]={0};
    char str2[N]={0};
    gets(str1);
    //getchar();
    gets(str2);

    puts(str2);
    //printf("\n");
    puts(str1);
    return 0;
}
