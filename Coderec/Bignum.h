#include"Bignum_Def.h"

#ifndef _Bignum_Header
#define _Bignum_Header
bignum::bignum(bignum &b):
beforeDot(b.beforeDot),afterDot(b.afterDot),sign(b.sign)
{

}

bignum::bignum(const bignum &b):
beforeDot(b.beforeDot),afterDot(b.afterDot),sign(b.sign)
{

}

bignum::bignum(bignum &&b):
beforeDot(b.beforeDot),afterDot(b.afterDot),sign(b.sign)
{
    std::vector<short>().swap(b.beforeDot);
    std::vector<short>().swap(b.afterDot);
    b.sign=false;
}

short bignum::getpow10(int index) const
{
    if(index>=0)return this->beforeDot[index];
    else return this->afterDot[-index-1];
}

void bignum::setpow10(int index,short num)
{
    if(index>=0)this->beforeDot[index]=num;
    else this->afterDot[-index-1]=num;
    return;
}

std::shared_ptr<bignum> bignum::signoreadd(const bignum &b)
{
    std::shared_ptr<bignum> p=std::make_shared<bignum>();
    p->beforeDot.resize(std::max(this->beforeDot.size(),b.beforeDot.size())+1);
    p->afterDot.resize(std::max(this->afterDot.size(),b.afterDot.size())+1);
    for(int i=this->beforeDot.size()-1;i>=b.beforeDot.size()-1;i--)
    {
        p->beforeDot[i]=this->beforeDot[i];
    }
    for(int i=b.beforeDot.size()-1;i>=this->beforeDot.size()-1;i--)
    {
        p->beforeDot[i]=b.beforeDot[i];
    }
    for(int i=this->afterDot.size()-1;i>=b.afterDot.size()-1;i--)
    {
        p->afterDot[i]=this->afterDot[i];
    }
    for(int i=b.afterDot.size()-1;i>=this->afterDot.size()-1;i--)
    {
        p->afterDot[i]=b.afterDot[i];
    }
    for(int i=std::min(this->beforeDot.size(),b.beforeDot.size())-1;i>=0-(std::min(this->afterDot.size(),b.afterDot.size()));i--)
    {
        p->setpow10(i,this->getpow10(i)+b.getpow10(i));
    }
    for(int i=0-(std::min(this->afterDot.size(),b.afterDot.size()));i<=std::min(this->beforeDot.size(),b.beforeDot.size())-1;i++)
    {
        
    }
    p->beforeDot.shrink_to_fit();
    p->afterDot.shrink_to_fit();
    return p;
}
#endif