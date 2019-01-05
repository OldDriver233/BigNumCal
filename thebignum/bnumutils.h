#include"basenum.h"
#include"converter.h"
#include"extendnum.h"
#include<algorithm>

bnum gcd(bnum a, bnum b)
{
    if(signcmp(a,b)==-1)swap(a,b);
    if(b==itob(0))return a;
    else return gcd(b,a%b);
}