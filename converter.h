#include<string>
#include"basenum.h"
using namespace std;

bnum stob(std::string s)
{
    bnum rt;
    rt.beforeDot.resize(s.length()+3);
    for(int i=s.length()-1;i>=0;i--)
    {
        rt.beforeDot[i]=s[i]-'0';
    }
    return rt;
}

bnum itob(long long a)
{
    bnum rt;
    int cnt=0;
    while(a!=0)
    {
        rt.beforeDot[cnt]=a%10;
        a/=10;
        cnt++;
    }
    return rt;
}


bnum::bnum(std::string s)
{
    *this=stob(s);
}