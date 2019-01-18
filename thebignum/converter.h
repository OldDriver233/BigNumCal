#include<string>
#include"basenum.h"
using namespace std;

#ifndef bignum2
#define bignum2
bnum stob(std::string s)
{
    bnum rt;
    rt.beforeDot.resize(s.length()+3);
    for(unsigned long i=s.length()-1;i>=0;i--)
    {
        rt.beforeDot[i]=s[i]-'0';
    }
    return rt;
}

bnum itob(long long a)
{
    bnum rt;
    unsigned long cnt=0;
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
#endif