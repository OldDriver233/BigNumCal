#include<iostream>
#include"basenum.h"
#include"converter.h"

void bnum::operator=(bnum a)
{
	this->beforeDot.resize(a.beforeDot.capacity());
	this->beforeDot=a.beforeDot;
	this->afterDot.resize(a.afterDot.capacity());
	this->afterDot=a.afterDot;
	this->withDot=a.withDot;
	this->signer=a.signer;
	return;
}

bnum bnum::operator+(bnum a)
{
    bnum rt;
    short adder=0;
    unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
    rt.beforeDot.resize(maxnum(ts,as)+3);
    this->beforeDot.resize(maxnum(ts,as)+3);
    a.beforeDot.resize(maxnum(ts,as)+3);
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

void bnum::operator+=(bnum a)
{
	*this=(*this+a);
	return;
}

bnum bnum::operator-(bnum a)
{
    bnum rt;
    short lender=0;
    unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
    rt.beforeDot.resize(maxnum(ts,as)+3);
    this->beforeDot.resize(maxnum(ts,as)+3);
    a.beforeDot.resize(maxnum(ts,as)+3);
	for(int i=0;i<maxnum(ts,as);i++)
	{
		rt.beforeDot[i]=this->beforeDot[i]-a.beforeDot[i]-lender;
        lender=(rt.beforeDot[i]<0?1:0);
        if(rt.beforeDot[i]<0)rt.beforeDot[i]=rt.beforeDot[i]+10;
    }
    return rt;
}

void bnum::operator-=(bnum a)
{
	*this=(*this-a);
	return;
}

bnum bnum::operator*(bnum a)
{
	bnum rt;
	short adder=0;
	unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
	rt.beforeDot.resize(ts+as+3);
    this->beforeDot.resize(maxnum(ts,as)+3);
    a.beforeDot.resize(maxnum(ts,as)+3);
	for(int i=0;i<ts;i++)
	{
		for(int j=0;j<as;j++)
		{
			rt.beforeDot[i+j]+=this->beforeDot[i]*a.beforeDot[j]+adder;
			adder=rt.beforeDot[i+j]/10;
			rt.beforeDot[i+j]%=10;
		}
		if(adder!=0)
		{
			rt.beforeDot[i+as]+=adder;
			adder=0;
		}
	}
	return rt;
}

void bnum::operator*=(bnum a)
{
	*this=((*this)*a);
	return;
}

bnum bnum::operator/(bnum a)
{
	bnum rt,rest;
    unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
    rt.beforeDot.resize(maxnum(ts,as)+3);
	rest.beforeDot.resize(ts+3);
	for(int i=ts-1;i>=0;i--)
	{
		for(int j=ts;j>0;j--)
		{
			rest.beforeDot[j]=rest.beforeDot[j-1];
		}
		rest.beforeDot[0]=this->beforeDot[i];
		while(a<rest || a==rest)
		{
			rest-=a;
			rt.beforeDot[i]++;
		}
	}
	return rt;
}

void bnum::operator/=(bnum a)
{
	*this=((*this)/a);
	return; 
}

bnum bnum::operator%(bnum a)
{
	bnum rest;
    unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
	rest.beforeDot.resize(ts+3);
	for(int i=ts-1;i>=0;i--)
	{
		for(int j=ts;j>0;j--)
		{
			rest.beforeDot[j]=rest.beforeDot[j-1];
		}
		rest.beforeDot[0]=this->beforeDot[i];
		while(a<rest || a==rest)
		{
			rest-=a;
		}
	}
	return rest;
}

void bnum::operator%=(bnum a)
{
	*this=((*this)%a);
	return; 
}