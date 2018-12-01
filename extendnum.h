#include"basenum.h"

bnum bnum::operator+(bnum &a)
{
    bnum rt;
    short adder=0;
    unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
	for(int i=0;i<maxnum(ts,as);i++)
	{
		rt.beforeDot[i]=this->beforeDot[i]+a.beforeDot[i]+adder;
        adder=rt.beforeDot[i]/10;
        rt.beforeDot[i]=rt.beforeDot[i]%10;
    }
    if(adder!=0)
    {
        rt.beforeDot[maxnum(ts,as)]=rt.beforeDot[maxnum(ts,as)]%10;
    }
    return rt;
}
