#include<iostream>
#include<algorithm>

int arr[10]={2,6,2,5,9,8,4,3,5,9};
struct Node
{
    int key;
    Node *next;
};


Node* InsertSort(Node *head){
    Node *t=head;
    Node *res=NULL;
    while (t!=nullptr)
    {
        if(res==nullptr){
            head=t->next;
            res=t;
            t->next=nullptr;
            t=head;
        }else{
            head=t->next;
            t->next=nullptr;
            Node *p0=nullptr;
            Node *p=res;
            while (p!=nullptr)
            {
                if(t->key<p->key){
                    break;
                }
                p0=p;
                p=p->next;
            }
            if(p0!=nullptr){
                p0->next=t;
                t->next=p;
            }else{
                res=t;
                t->next=p;
            }
            
        }
        t=head;
    }
    return res;
}

Node * BuketSort(Node *head){

    Node *buket1=nullptr;
    Node *buket1_rear=nullptr;
    Node *buket2=nullptr;
    Node *buket2_rear=nullptr;

    while (head!=nullptr)
    {
        Node *t=head;
        t->next=nullptr;
        if(t->key<0){
            if(buket1!=nullptr){
                buket1_rear->next=t;
                buket1_rear=buket1_rear->next;
            }else{
                buket1=t;
                buket1_rear=buket1;
            }
        }else{
            if(buket2!=nullptr){
                buket2_rear->next=t;
                buket2_rear=buket2_rear->next;
            }else{
                buket2=t;
                buket2_rear=buket2;
            }
        }
        head=head->next;
    }

    if(buket1_rear!=nullptr){
        buket1_rear->next=buket2;
    }else{
        buket1=buket2;
    }
    return buket1;    
}

int * odd_evenSort(int arr[],int size){
    bool flag=true;
    int count=0;
    while (flag)
    {
        flag=false;
        if(count&2){
            //为奇数次扫描
            for (int i = 1; i < size-1;i+=2)
            {
                if (arr[i]>arr[i+1])
                {
                    int t=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=t;
                    flag=true;
                }
            }
        }else{
            //偶数次扫描
            for (int i = 0; i < size-1; i+=2)
            {
                if (arr[i]>arr[i+1])
                {
                    int t=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=t;
                    flag=true;
                }               
            }
        }
        ++count;
    }
    return arr;
}




int main(int argc, char const *argv[])
{
    
    return 0;
}
