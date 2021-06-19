#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class BigInteger
{
private:
    vector<int> content;
public:
    BigInteger();
    BigInteger(long long origin);
    BigInteger(const BigInteger& b);
    ~BigInteger();
    unsigned long long size() const;
    BigInteger operator+(const BigInteger& b);
    BigInteger& operator=(const BigInteger& b);
    void resize(unsigned long long n); 
    const int& operator[](unsigned long long i)const;
    int& operator[](unsigned long long i);
    string toString();

};
BigInteger::BigInteger(){
    content.reserve(128);
    for (int i = 0; i < 128; ++i){
        content.push_back(0);
    }
    
}

BigInteger::BigInteger(long long origin){
    content.reserve(128);
    while (origin>0)
    {
        content.push_back(origin%10);
        origin=origin/10;
    }
}
BigInteger::BigInteger(const BigInteger& b){
    content.clear();
    for(int i=0;i<b.size();++i){
        content.push_back(b[i]);
    }
}

BigInteger::~BigInteger(){
    content.clear();
}

BigInteger BigInteger::operator+(const BigInteger& b){
    BigInteger t;
    BigInteger res;
    unsigned long long maxsize=max(this->size(),b.size());
    t.resize(maxsize+1);
    res.resize(maxsize+1);
    for (int i = 0; i < maxsize; ++i){
        int num1=i<this->size()?content[i]:0;
        int num2=i<b.size()?b[i]:0;
        res[i]=(num1+num2+t[i])%10;
        t[i+1]=(num1+num2+t[i])/10;
    }
    if(t[maxsize]!=0){
        res[maxsize]=t[maxsize];
    }else{
        res.resize(maxsize);
    }
    return res;
}
BigInteger& BigInteger::operator=(const BigInteger& b){
    if(this==&b){
        return *this;
    }else{
        content.clear();
        content.reserve(b.size());
        for(int i=0;i<b.size();++i){
            content.push_back(b[i]);
        }
    }
    return *this;
}
unsigned long long BigInteger::size()const{
        return content.size();
}
const int& BigInteger::operator[](unsigned long long i)const{
    if(i>content.size())return *content.end();
    return (*(content.begin()+i));
}
int& BigInteger::operator[](unsigned long long i){
    if(i>content.size())return *content.end();
    return (*(content.begin()+i));
}
void BigInteger::resize(unsigned long long n){
    if(n>this->size()){
        for (unsigned long long i = this->size(); i <n; ++i){
            content.push_back(0);
        }
    }else{
        for (unsigned long long i = this->size(); i>n; --i){
            content.pop_back();
        }
    }
}
string BigInteger::toString(){
    bool flag=true;
    string res;
    for (int i = this->size()-1; i >=0; --i){
        if(flag&&content[i]==0){
            continue;
        }else{
            if(flag&&content[i]!=0){
                flag=false;
            }
            res.push_back(content[i]+48);
        }
    }
    if(flag)res.push_back('0');
    return res;
}


int main(int argc, char const *argv[])
{
    BigInteger a=0;
    BigInteger b=0;
    cout<<(a+b).toString();
    return 0;
}
