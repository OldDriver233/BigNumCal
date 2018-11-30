#include<string>
#include<vector>
class bnum{
    private:
        std::vector<int> beforeDot,afterDot;
        bool withDot;
    public:
    bnum();
    bnum(std::string s);
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

bnum::bnum(std::string s)
{

}