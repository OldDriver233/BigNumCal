#include<iostream>
#include"basenum.h"
#include"converter.h"

#ifndef big_num3
#define big_num3
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
    bnum rt,copier;
    short adder=0;
    unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
	copier=*this;
	if(copier.signer==1 && a.signer==1)rt.signer=1;
	else if(copier.signer==1 && a.signer==0)
	{
		copier.signer=0;
		return a-copier;
	}
	else if(copier.signer==0 && a.signer==1)
	{
		a.signer=0;
		return copier-a;
	}
    rt.beforeDot.resize(maxnum(ts,as)+3);
    this->beforeDot.resize(maxnum(ts,as)+3);
    a.beforeDot.resize(maxnum(ts,as)+3);
	for(unsigned long i=0;i<maxnum(ts,as);i++)
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
    bnum rt,copier;
    short lender=0;
    unsigned long long ts=this->beforeDot.size(), as=a.beforeDot.size();
	copier=*this;
	if(a.signer==0 && copier.signer==0)
	{
		if(signcmp(copier,a)==-1)rt.signer=1;
	}
	else if(a.signer==1 && copier.signer==1)
	{
		a.signer=0;
		copier.signer=0;
		return a-copier;
	}
	else if(a.signer==0 && copier.signer==1)
	{
		copier.signer=0;
		rt=a+copier;
		rt.signer=1;
		return rt;
	}
	else
	{
		a.signer=0;
		return a+copier;
	}
    rt.beforeDot.resize(maxnum(ts,as)+3);
    this->beforeDot.resize(maxnum(ts,as)+3);
    a.beforeDot.resize(maxnum(ts,as)+3);
	for(unsigned long i=0;i<maxnum(ts,as);i++)
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
	if(a.signer^this->signer)rt.signer=1;
	rt.beforeDot.resize(ts+as+3);
    this->beforeDot.resize(maxnum(ts,as)+3);
    a.beforeDot.resize(maxnum(ts,as)+3);
	for(unsigned long i=0;i<ts;i++)
	{
		for(unsigned long j=0;j<as;j++)
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
	if(a.signer^this->signer)rt.signer=1;
    rt.beforeDot.resize(maxnum(ts,as)+3);
	rest.beforeDot.resize(ts+3);
	for(unsigned long i=ts-1;i>=0;i--)
	{
		for(unsigned long j=ts;j>0;j--)
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
    unsigned long long ts=this->beforeDot.size();
	rest.beforeDot.resize(ts+3);
	for(unsigned long i=ts-1;i>=0;i--)
	{
		for(unsigned long j=ts;j>0;j--)
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
#endif