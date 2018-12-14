#include<string>
#include<vector>
#include<list>
#ifndef big_num
#define big_num
class bnum{
    friend void test();
    friend bnum stob(std::string s);
    friend bnum itob(long long a);
    private:
        std::vector<short> beforeDot,afterDot;
        bool withDot;
    public:
        static int prec;
        bnum();
        bnum(std::string s);
        bnum(double d);

        bool operator==(bnum& a);
        bool operator<(bnum& a);
        bool operator>(bnum& a);

        bnum operator+(bnum& a);
        bnum operator-(bnum& a);
        bnum operator*(bnum& a);
        bnum operator/(bnum& a);

        void operator+=(bnum& a);
        void operator-=(bnum& a);
        void operator*=(bnum& a);
        void operator/=(bnum& a);

        void operator=(bnum a);
};

bnum::bnum()
{
    withDot=false;
    this->beforeDot.resize(30);
}

inline int maxnum(unsigned long long x,unsigned long long y)
{
  return x>y?x:y;
}

bool bnum::operator==(bnum &a)
{
    if(this->beforeDot!=a.beforeDot)return false;
    else return true;
}

bool bnum::operator<(bnum &a)
{
    unsigned long long ts=this->beforeDot.size,as=a.beforeDot.size;
    this->beforeDot.resize(maxnum(ts,as));
    a.beforeDot.resize(maxnum(ts,as));
    for(int i=maxnum(this->beforeDot.size,a.beforeDot.size)-1;i>=0;i--)
    {
        if(this->beforeDot[i]<a.beforeDot[i])return true;
        else if(this->beforeDot[i]>a.beforeDot[i])return false;
    }
    return false;
}

bool bnum::operator>(bnum &a)
{
    unsigned long long ts=this->beforeDot.size,as=a.beforeDot.size;
    this->beforeDot.resize(maxnum(ts,as));
    a.beforeDot.resize(maxnum(ts,as));
    for(int i=maxnum(this->beforeDot.size,a.beforeDot.size)-1;i>=0;i--)
    {
        if(this->beforeDot[i]>a.beforeDot[i])return true;
        else if(this->beforeDot[i]<a.beforeDot[i])return false;
    }
    return false;
}

#endif