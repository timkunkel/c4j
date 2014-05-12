#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
namespace rn{
class RationalNumber
{
    int m_numerator, m_denominator;
public:
    RationalNumber(int numerator = 0,int denominator = 1):
        m_numerator(numerator), m_denominator(denominator)
    {
    }
    int num() const {return m_numerator;}
    int denom() const {return m_denominator;}
    bool isValid() const;
    RationalNumber inverse() const;
    RationalNumber operator+(RationalNumber rhs) const;
    RationalNumber operator-(RationalNumber rhs) const;
    RationalNumber operator-() const;
    RationalNumber operator*(RationalNumber rhs) const;
    RationalNumber operator/(RationalNumber rhs) const;
    bool operator==(RationalNumber rhs) const;
    RationalNumber operator-();
    bool operator<(RationalNumber rhs) const;


};
}
#endif // RATIONALNUMBER_H
