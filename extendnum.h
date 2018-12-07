#include<iostream>
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

void bnum::operator+=(bnum& a)
{
    short adder=0;
    unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
	for(int i=0;i<maxnum(ts,as);i++)
	{
		this->beforeDot[i]=this->beforeDot[i]+a.beforeDot[i]+adder;
        adder=this->beforeDot[i]/10;
        this->beforeDot[i]=this->beforeDot[i]%10;
    }
    if(adder!=0)
    {
        this->beforeDot[maxnum(ts,as)]=this->beforeDot[maxnum(ts,as)]%10;
    }
}

bnum bnum::operator-(bnum &a)
{
    bnum rt;
    short lender=0;
    unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
	for(int i=0;i<maxnum(ts,as);i++)
	{
		rt.beforeDot[i]=this->beforeDot[i]-a.beforeDot[i]-lender;
        lender=(rt.beforeDot[i]<0?1:0);
        rt.beforeDot[i]=rt.beforeDot[i]+10;
    }
    return rt;
}

void bnum::operator-=(bnum& a)
{
    short lender=0;
    unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
	for(int i=0;i<maxnum(ts,as);i++)
	{
		this->beforeDot[i]=this->beforeDot[i]-a.beforeDot[i]-lender;
        lender=(this->beforeDot[i]<0?1:0);
        if(this->beforeDot[i]<0) this->beforeDot[i]=this->beforeDot[i]+10;
    }
}