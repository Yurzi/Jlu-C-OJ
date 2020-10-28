#include <stdio.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    int y, m, d;
    int flag = false;
    scanf("%d %d %d", &y, &m, &d);
    if ((y % 4 <= 0 && y % 100 != 0) || y % 400 <= 0)
    {
        flag = true;
    }
    if (y > 0 && m > 0 && d > 0)
    {
        switch (m)
        {
        case 1:
            if (d <=31)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        case 2:
            if (flag)
            {
                if (d <= 29)
                {
                    printf("OK");
                }
                else
                {
                    printf("NO");
                }
            }
            else
            {
                if (d <= 28)
                {
                    printf("OK");
                }
                else
                {
                    printf("NO");
                }
            }
            break;
        case 3:
            if (d <= 31)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        case 4:
            if (d <= 30)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        case 5:
            if (d <= 31)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        case 6:
            if (d <= 30)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        case 7:
            if (d <= 31)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        case 8:
            if (d <= 31)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        case 9:
            if (d <= 30)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        case 10:
            if (d <= 31)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        case 11:
            if (d <= 30)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        case 12:
            if (d <= 31)
            {
                printf("OK");
            }
            else
            {
                printf("NO");
            }
            break;
        default:
            printf("NO");
        }
    }else
    {
        printf("NO");
    }
    
    return 0;
}
