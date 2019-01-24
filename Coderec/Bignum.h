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

#endif