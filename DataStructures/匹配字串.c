#include<stdio.h>
#include<string.h>
int search(char pat[],char text[]);
char p[501]={0};

char* a="easy";
char* b="qiandao";
int main(int argc, char const *argv[])
{
    
    int n=0,m=0;
    int flag=1;
    scanf("%d %d",&n,&m);
    m=m+1;
    getchar();
    for (n; n>0;--n)
    {
        gets(p);
        if(search(a,p)||search(b,p)){
        }else{
            --m;
        }
        if(m==0){
            printf("%s",p);
            return 0;
        }
    }
    printf("Wo AK le");
    
    return 0;
}

int search(char pat[],char text[]){
    int M=strlen(pat);
    int N=strlen(text);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (pat[j] != text[i+j])
                break;
        }
        // pat 全都匹配了
        if (j == M) return i;
    }
    // txt 中不存在 pat 子串
    return 0;
}