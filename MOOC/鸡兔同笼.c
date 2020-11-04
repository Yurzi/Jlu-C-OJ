#include<stdio.h>
int main()
{
    int x,y,heads,feet;
    heads=25;
    feet=72;
    y=(feet-(heads*2))/2;
    x=heads-y;
    printf("%d %d",x,y);
    return 0;
}
