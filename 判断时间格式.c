#include<stdio.h>
int main(int argc, char const *argv[])
{
    int s,m,h;
    scanf("%d %d %d",&h,&m,&s);
    if(h>=0&&h<24){
        if(m>=0&&m<60){
            if (s>=0&&s<60)
            {
                printf("OK");
            }else
            {
                printf("NO");
            }
            
        }else
        {
            printf("NO");
        }
    }else
    {
        printf("NO");
    }
    
    return 0;
}
