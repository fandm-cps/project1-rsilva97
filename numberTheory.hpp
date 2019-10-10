#ifndef NUMBERTHEORY_HPP
#define NUMBERTHEORY_HPP

#include "ReallyLongInt.hpp"

class numberTheory{
    public:
        ReallyLongInt extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b, ReallyLongInt x, ReallyLongInt y);

};

#endif