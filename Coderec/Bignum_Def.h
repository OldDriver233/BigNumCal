#include<iostream>
#include<vector>
#include<algorithm>

#ifndef _Bignum_Header_Define
#define _Bignum_header_Define

class bignum
{
    friend std::ostream& operator<<(std::ostream &os,bignum b);
    private:
        std::vector<short> beforeDot,afterDot;
        bool sign;
        short getpow10(int index);
    public:
        bignum()=default;
        bignum(bignum &);
        bignum(const bignum &);
        bignum(bignum &&);
        
        bignum operator+(bignum b);
        bignum operator-(bignum b);
        bignum operator*(bignum b);
        bignum operator/(bignum b);

        bignum operator+=(bignum b);
        bignum operator-=(bignum b);
        bignum operator*=(bignum b);
        bignum operator/=(bignum b);
};

#endif