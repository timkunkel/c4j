#include "rationalnumber.h"

RationalNumber invalid = {1,0};

int Euclid(int a, int b)
{
    if(b == 0)
        return a;
    else
        return Euclid(b, a%b);
}

bool rnIsValid(RationalNumber n)
{
    if(n.denominator != 0)
        return true;

    return false;
}

RationalNumber normalize(RationalNumber n)
{

    if(!rnIsValid(n)){

        return invalid;
}
    int gcd = Euclid(n.numerator, n.denominator);
    RationalNumber rn = {n.numerator/gcd, n.denominator/gcd};
    return rn;
}

bool rnEqual(RationalNumber n1, RationalNumber n2)
{
    if(!rnIsValid(n1) || !rnIsValid(n2))
        return false;

    n1 = normalize(n1);
    n2 = normalize(n2);
    if(n1.numerator == n2.numerator && n1.denominator == n2.denominator)
        return true;

    return false;
}

bool rnLessThan (RationalNumber n1, RationalNumber n2)
{
    if(!rnIsValid(n1) || !rnIsValid(n2))
        return false;

    if(((n1.numerator < 0)^(n1.denominator < 0)) && !((n2.numerator < 0)^(n2.denominator < 0)))
        return true;

    else if(n1.numerator / n1.denominator < n2.numerator / n2.denominator)
        return true;

    return false;
}


RationalNumber rnAdd(RationalNumber n1, RationalNumber n2)
{

    if(!rnIsValid(n1) || !rnIsValid(n2))
        return invalid;
    int newNum = n1.numerator * n2.denominator + n2.numerator * n1.denominator;
    int newDenum = n1.denominator * n2.denominator;
    RationalNumber rn = {newNum, newDenum};
    return normalize(rn );
}

RationalNumber rnSubtract(RationalNumber n1, RationalNumber n2)
{
    if(!rnIsValid(n1) || !rnIsValid(n2))
        return invalid;

    int newNum = n1.numerator * n2.denominator - n2.numerator * n1.denominator;
    int newDenum = n1.denominator * n2.denominator;
    RationalNumber rn = {newNum, newDenum};
    return normalize(rn);
}

RationalNumber rnMultiply(RationalNumber n1, RationalNumber n2)
{
    if(!rnIsValid(n1) || !rnIsValid(n2))
        return invalid;
    RationalNumber rn = {n1.numerator * n2.numerator, n1.denominator * n2.denominator};
    return normalize(rn);
}

RationalNumber rnDivide(RationalNumber n1, RationalNumber n2)
{
    if(!rnIsValid(n1) || !rnIsValid(n2))
        return invalid;
    RationalNumber rn = {n2.denominator, n2.numerator};
    return rnMultiply(n1, rn);
}
