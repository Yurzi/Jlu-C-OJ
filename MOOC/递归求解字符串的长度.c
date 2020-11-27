#include<stdio.h>
#define N 1024
int strLength(char* str,char* now){
    if (*now=='\0')
    {
        return (now-str);
    }else{
        return strLength(str,now+1);
    }    
}

int main(int argc, char const *argv[])
{
    char str[N]={0};
    int l=0;

    gets(str);

    l=strLength(str,str);

    printf("%d",l);

    return 0;
}
