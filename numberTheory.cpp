#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

ReallyLongInt numberTheory::extendedEuclid(ReallyLongInt& a, ReallyLongInt& b, ReallyLongInt* x, ReallyLongInt* y){
    ReallyLongInt zero, one(1), result, otherX, otherY;
    
    if(b.equal(zero)){
        x = one;
        y = zero;
        return a;
    }
    
    result = extendedEuclid(b, a % b, otherX, otherY);
    x = otherY;
    y = otherX - (otherY * floor(a / b));

    return result;
} 