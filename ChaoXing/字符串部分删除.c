#include<stdio.h>
#include<string.h>
#define N 512
int main(int argc, char const *argv[])
{
    char str[N]={0};
    int v=0,w=0;
    char* p=NULL;
    scanf("%d %d",&v,&w);
    getchar();
    gets(str);
	char* head=&str[v-1];
	char* tail=NULL;
	if (w!=0)
	{
		tail=&str[v+w-1];
		*head='\0';
	}
	if (w==0)
	{
		printf("%s",str);
	}
	else
	{
	printf("%s%s",str,tail);
	}  
    return 0;
}
