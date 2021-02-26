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

Rational operator*(const Rational& lhs, const Rational& rhs)
{
        Rational value(lhs.Numerator()*rhs.Numerator(), rhs.Denominator()*lhs.Denominator());
        return value;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
        Rational value(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
        return value;
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}