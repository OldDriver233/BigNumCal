#include<iostream>
#include"bignum"

void test()
{
    bnum a,b;
    a.beforeDot[0]=2;
    b.beforeDot[0]=6;
    b/=a;
    for(unsigned long i=0;i<b.beforeDot.size();i++)
    {
        std::cout<<b.beforeDot[i];
    }
    return;
}

int main()
{
    test();
    return 0;
}
