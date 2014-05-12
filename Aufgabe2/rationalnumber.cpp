#include "rationalnumber.h"
namespace rn {

using namespace rn;

bool rn::RationalNumber::isValid()const{
    if(this->denom() == 0)
        return false;
    return true;

}

int Euclid(int a, int b)
{
    if(b == 0)
        return a;
    else
        return Euclid(b, a%b);
}

RationalNumber normalize(RationalNumber rn) {
    int gcd = Euclid(rn.num(),rn.denom());
    return RationalNumber(rn.num()/gcd,rn.denom()/gcd);
}

RationalNumber rn::RationalNumber::operator+(RationalNumber rhs) const{
     int newnum = num()* rhs.denom() + rhs.num() * denom();
     int newdenom = denom() * rhs.denom();
     return normalize(RationalNumber(newnum,newdenom));
 }

RationalNumber rn::RationalNumber::operator-(RationalNumber rhs) const{
     int newnum = num()* rhs.denom() - rhs.num() * denom();
     int newdenom = denom() * rhs.denom();
     return normalize(RationalNumber(newnum,newdenom));
 }

RationalNumber rn::RationalNumber::operator*(RationalNumber rhs) const{
     int newnum = num()*rhs.num();
     int newdenom = denom() * rhs.denom();
     return normalize(RationalNumber(newnum,newdenom));
 }
RationalNumber rn::RationalNumber::operator-() const {
   return RationalNumber(-1*num(), denom());
}

bool rn::RationalNumber::operator==(RationalNumber rhs) const{
   RationalNumber n1 = normalize(RationalNumber(this->num(),this->denom()));
   RationalNumber n2 = normalize(rhs);

    if(n1.num() == n2.num() && n1.denom() == n2.denom())
        return true;
    return false;
 }
RationalNumber rn::RationalNumber::inverse() const{
    return RationalNumber(denom(),num());
}
RationalNumber rn::RationalNumber::operator/(RationalNumber rhs) const{
    return normalize(rhs * RationalNumber(this->denom(),this->num()));
}
bool rn::RationalNumber::operator <(RationalNumber rn) const{
    if((float)this->num()/(float)this->denom() < (float)rn.num()/(float)rn.denom())
        return true;
    return false;

}


}
