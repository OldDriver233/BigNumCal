#include"../bignum"

class frac
{
    private:
        bnum upper,lower;
    public:
        frac();
        frac(std::string s);
        frac(double d);

        bool operator==(frac a);
        bool operator<(frac a);
        bool operator>(frac a);

        frac operator+(frac a);
        frac operator-(frac a);
        frac operator*(frac a);
        frac operator/(frac a);
        frac operator%(frac a);

        void operator+=(frac a);
        void operator-=(frac a);
        void operator*=(frac a);
        void operator/=(frac a);
        void operator%=(frac a);

        void operator=(frac a);
};

frac::frac()
{

}

