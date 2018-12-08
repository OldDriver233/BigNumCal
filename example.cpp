#include<iostream>
#include"extendnum.h"

void test()
{
    bnum a,b;
    std::cout<<a.beforeDot.capacity()<<std::endl;
    a.beforeDot[0]=5;
    b.beforeDot[0]=7;
    b*=a;
    for(int i=0;i<b.beforeDot.size();i++)
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
