#include<string.h>
//压栈
void inStack(char temp[],char n){
    int i=strlen(temp);
    for(int j=i-1;j>=0;j--){
        temp[j]=temp[j-1];
    }
    temp[0]=n;
}
//出栈
void outStack(char temp[]){
    int i=strlen(temp);
    for(int j=0;j<i-1;j++){
        temp[j]=temp[j+1];
    }
    temp[i-1]=0;
}
//判断空栈
int isEmptyStack(char temp[]){
    int i=strlen(temp);
    for(int j=0;j<i;j++){
        if(temp[j]!=0){
            return 0;
        }
    }
    return 1;
}