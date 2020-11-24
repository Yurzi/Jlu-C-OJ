#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 5
typedef struct strpro
{
    int length;
    char var[];
}Strpro;

int main(int argc, char const *argv[])
{
    Strpro *arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i]=(Strpro*)malloc(sizeof(Strpro));
    }
    
    for (int i = 0; i < N; i++)
    {
        scanf("%s",&(arr[i]->var));
        arr[i]->length=strlen(arr[i]->var);
        getchar();
    }
    Strpro* p=NULL;

    p=arr[0];
    for (int i = 1; i < N; i++)
    {
        if (p->length<arr[i]->length)
        {
            p=arr[i];
        }
        
    }

    printf("%d",p->length);
    printf(" %s",p->var);
    

    return 0;
}

