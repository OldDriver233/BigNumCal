#include<string>
#include<vector>
class bnum{
    private:
        std::vector<short> beforeDot,afterDot;
        bool withDot;
    public:
    bnum();
    bnum(std::string s);
    bool operator==(bnum& a)
    {
        if(afterDot.size()!=a.afterDot.size())return false;
        else if(beforeDot.size()!=a.beforeDot.size())return false;
    }
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
