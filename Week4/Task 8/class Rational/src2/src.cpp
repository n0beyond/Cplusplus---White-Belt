#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

class Rational
{
    public:
    Rational(){}
    Rational(int numerator, int denominator)
    {
        if(denominator != 0 && numerator != 0)
        {
            int nod;
            nod = gcd(numerator, denominator);
            if(numerator / abs(numerator) == denominator / abs(denominator))
            {
                numer = abs(numerator) / nod ;
                denom = abs(denominator) / nod;
            }
            else if(numerator < 0)
            {
                numer = numerator / nod;
                denom = denominator / nod;
            }
            else
            {
                numer = -1*(numerator / nod);
                denom = abs(denominator) / nod;
            }
        }
        else
        {
            numer = 0;
            denom = 1;
        }
    }
    
    int Numerator () const
    {
        return numer;
    }
    int Denominator() const
    {
        return denom;
    }
    private:
    int numer = 0;
    int denom = 1;
};

bool operator==(const Rational& lhs, const Rational& rhs)
{
    if(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
    {
        return true;
    }
    return false;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
        Rational value(lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator(), rhs.Denominator()*lhs.Denominator());
        return value;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
        Rational value(lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator(), rhs.Denominator()*lhs.Denominator());
        return value;
}
    
int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}