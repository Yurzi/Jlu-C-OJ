#include<stdio.h>
int main(int argc, char const *argv[])
{
    int i=1;
    int total=0;
    while (1)
    {
        total=7*i;
        if (total%2==1&&total%3==2&&total%5==4)
        {
            break;
        }

        i++;    
    }
    printf("%d",total);
    
    return 0;
}
