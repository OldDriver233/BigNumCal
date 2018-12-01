#include<string>
#include<vector>
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
};

bnum atoi(std::string str)
{
    bnum a;
    return a;
}

bnum::bnum()
{
    withDot=false;
}
