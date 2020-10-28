#include <stdio.h>
int  main(void){
   int i=1,j,m=0;
     for (;i<=5;i+=4)
       for (j=3;j<=19;j+=4)
       m++;
     printf("%d",m);
     return 0;
}