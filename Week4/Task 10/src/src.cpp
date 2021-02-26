#include <iostream>
#include <sstream>
#include <cmath>
#include <numeric>
#include <set>
#include <vector>
#include <map>

using namespace std;

class Rational
{
    public:
    Rational(){}
    Rational(int numerator, int denominator)
    {
        if(denominator == 0)
        {
            throw invalid_argument("invalid_argument");
        }
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

bool operator<(const Rational& lhs, const Rational rhs)
{
    if(lhs.Numerator()*rhs.Denominator() < rhs.Numerator()*lhs.Denominator())
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
    if(lhs.Denominator()*rhs.Numerator() == 0)
    {
        throw domain_error("domain_error");
    }
        Rational value(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
        return value;
}

ostream& operator<<(ostream& stream, const Rational& number)
{
    stream << number.Numerator() << "/" << number.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& number)
{
    int n1, n2;
    char slash;
    stream >> n1;
    stream >> slash;
    stream >> n2;
    if(slash != '/')
    {
        return stream;
    }
    if(stream)
    {
        Rational a(n1, n2);
        number = a;
    }
    return stream;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}