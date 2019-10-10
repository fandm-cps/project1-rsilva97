#include "numberTheory.hpp"

ReallyLongInt numberTheory::extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b, ReallyLongInt &x, ReallyLongInt &y){
    ReallyLongInt zero, one(1), result, otherX, otherY;

    if(b.equal(zero)){
        x = one;
        y = zero;
        return a;
    }

    result = extendedEuclid(b, a % b, otherX, otherY);
    x = otherY;
    y = otherX - (otherY * (a / b));

    return result;
} 