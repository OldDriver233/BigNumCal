#include<string>
#include<vector>
#include<list>
class bnum{
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
    bnum operator+=(bnum& a);
    bnum operator-=(bnum& a);
    bnum operator*=(bnum& a);
    bnum operator/=(bnum& a);
    bnum operator+(long long& a);
    bnum operator-(long long& a);
    bnum operator*(long long& a);
    bnum operator/(long long& a);
};

bnum::bnum()
{
    withDot=false;
}

inline int maxnum(unsigned long long x,unsigned long long y)
{
  return x>y?x:y;
}
