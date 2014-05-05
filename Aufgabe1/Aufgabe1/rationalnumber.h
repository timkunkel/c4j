#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

// rational number containing a numerator and a denominator
struct RationalNumber
{
    int numerator, denominator;
};

// returns whether the given rational number is valid
bool rnIsValid(RationalNumber n);

// returns whether the both given rational numbers are equal
bool rnEqual(RationalNumber n1, RationalNumber n2);

// checks whether the first rational number is less than the second
bool rnLessThan(RationalNumber n1, RationalNumber n2);

// returns the sum of both given rational numbers
RationalNumber rnAdd(RationalNumber n1, RationalNumber n2);

// returns the difference of between the first and the second rational number
RationalNumber rnSubtract(RationalNumber n1, RationalNumber n2);

// returns the product of both given rational numbers
RationalNumber rnMultiply(RationalNumber n1, RationalNumber n2);

// returns the quotient of both given rational numbers
RationalNumber rnDivide(RationalNumber n1, RationalNumber n2);

#endif // RATIONALNUMBER_H
