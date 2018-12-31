#include<string>
#include<vector>
#include<list>
#ifndef big_num
#define big_num
class bnum{
    friend void test();
    friend bnum stob(std::string s);
    friend bnum itob(long long a);
    friend short signcmp(bnum a,bnum b);
    friend std::ostream& operator<<(std::ostream& os , bnum a);
    private:
        std::vector<short> beforeDot,afterDot;
        bool withDot;
        bool signer;
    public:
        static int prec;
        bnum();
        bnum(std::string s);
        bnum(double d);

        bool operator==(bnum a);
        bool operator<(bnum a);
        bool operator>(bnum a);

        bnum operator+(bnum a);
        bnum operator-(bnum a);
        bnum operator*(bnum a);
        bnum operator/(bnum a);
        bnum operator%(bnum a);

        void operator+=(bnum a);
        void operator-=(bnum a);
        void operator*=(bnum a);
        void operator/=(bnum a);
        void operator%=(bnum a);

        void operator=(bnum a);
};

bnum::bnum()
{
    withDot=false;
    signer=false;
    this->beforeDot.resize(30);
}

inline int maxnum(unsigned long long x,unsigned long long y)
{
  return x>y?x:y;
}

bool bnum::operator==(bnum a)
{
    if(this->signer!=a.signer)return false;
    if(this->beforeDot!=a.beforeDot)return false;
    else return true;
}

bool bnum::operator<(bnum a)
{
    unsigned long long ts=this->beforeDot.size(),as=a.beforeDot.size();
    this->beforeDot.resize(maxnum(ts,as));
    a.beforeDot.resize(maxnum(ts,as));
    for(int i=maxnum(ts,as)-1;i>=0;i--)
    {
        if(this->beforeDot[i]<a.beforeDot[i])return true;
        else if(this->beforeDot[i]>a.beforeDot[i])return false;
    }
    return false;
}

bool bnum::operator>(bnum a)
{
    unsigned long long ts=this->beforeDot.size(),as=a.beforeDot.size();
    this->beforeDot.resize(maxnum(ts,as));
    a.beforeDot.resize(maxnum(ts,as));
    for(int i=maxnum(ts,as)-1;i>=0;i--)
    {
        if(this->beforeDot[i]>a.beforeDot[i])return true;
        else if(this->beforeDot[i]<a.beforeDot[i])return false;
    }
    return false;
}


short signcmp(bnum a,bnum b)
{
    unsigned long long as=a.beforeDot.size(),bs=b.beforeDot.size();
    a.beforeDot.resize(maxnum(as,bs));
    b.beforeDot.resize(maxnum(as,bs));
    for(int i=maxnum(as,bs)-1;i>=0;i--)
    {
        if(a.beforeDot[i]>b.beforeDot[i])return 1;
        else if(a.beforeDot[i]<b.beforeDot[i])return -1;
    }
    return 0;
}
#endif