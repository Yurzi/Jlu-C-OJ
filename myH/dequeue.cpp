template<typename T>
class Dequeue
{
    T data_; //数据域
    Dequeue &next_;  //指针域
    static Dequeue &top;    //头指针
    static Dequeue &rear;   //尾指针
    static bool flag_init=true;  //初始化标记 

    public:
        Dequeue(){
            //首个节点
            if(this->flag_init){
                this->top=this;
                this->rear=this;
                flag_init=false;
            }
            this->next_=nullptr;
        }
        //重载
        Dequeue(T data){
            //首个节点
            if(this->flag_init){
                this->top=this;
                this->rear=this;
                flag_init=false;
            }
            this->data_=data;
            this->next_=nullptr;
        }

        bool empty(){
            if(top==rear)return true;
            return false;
        }

        //push
        void push(T data){
            Dequeue<T> temp= new Dequeue<T>(data);
            //将节点插入哨兵节点后
            temp.next_=top.next_;
            top.next_=temp;
            return;
        }
        //pop
        void pop(T data){
            if(empty()){data=nullptr;return;}
            Dequeue &p=top.next_;   //记录节点
            data=p; //将值传出  
            top.next_=top.next_.next_;  //修改指针
            delete p;   //释放空间
            return;
        }
        //inject
        void inject(T data){
            Dequeue<T> temp= new Dequeue<T>(data);
            rear.next_=temp;    //将节点放到尾部
            rear=temp;      //将尾指针修改为当前
            return;
        }
        //eject
        void eject(T data){
            if(empty()){data=nullptr;return;}
            //找打尾节点前的一个节点
            Dequeue &p=top; //从头开始
            while(p.next_!=rear){
                p=p.next_;
            }
            data=rear;  //将值传递出去
            delete rear;    //  释放空间
            rear=p; //指针调整
            return;
        }
};
