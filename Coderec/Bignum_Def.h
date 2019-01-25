#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>

#ifndef _Bignum_Header_Define
#define _Bignum_header_Define

class bignum
{
    friend std::ostream& operator<<(std::ostream &os,bignum b);
    private:
        std::vector<short> beforeDot,afterDot;
        bool sign;
        short getpow10(int index)const;
        void setpow10(int index,short num);
        std::shared_ptr<bignum> signoreadd(const bignum &b);
        std::shared_ptr<bignum> signoremin(const bignum &b);
        std::shared_ptr<bignum> signoremul(const bignum &b);
        std::shared_ptr<bignum> signorediv(const bignum &b);
    public:
        bignum()=default;
        bignum(bignum &);
        bignum(const bignum &);
        bignum(bignum &&);
        
        bignum operator+(const bignum &b);
        bignum operator-(const bignum &b);
        bignum operator*(const bignum &b);
        bignum operator/(const bignum &b);

        bignum operator+=(const bignum &b);
        bignum operator-=(const bignum &b);
        bignum operator*=(const bignum &b);
        bignum operator/=(const bignum &b);
};

#endif