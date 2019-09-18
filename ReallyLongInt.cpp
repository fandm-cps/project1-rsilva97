#include "ReallyLongInt.hpp"
#include <iostream>
using namespace std;

ReallyLongInt::ReallyLongInt(){
    *digits = new vector<bool> [16];
    size = 16;
    n = 0;
    isNeg = false;
}

ReallyLongInt::ReallyLongInt(long long num){
    n = num;

    if(n < 0){
        isNeg = true;
    }
    else
    {
        isNeg = false;
    }


    
}

ReallyLongInt::ReallyLongInt(const string& numStr){

}       

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other){

}

ReallyLongInt::~ReallyLongInt(){
    cout << "Invoking destructor, clearing up" << endl;

    delete [] digits;
}

//Returns a string representation of the number stored in base 10
string ReallyLongInt::toString() const{
    //return this.
}

//Returns a string representation of the number stored in base 2
string ReallyLongInt::toStringBinary() const{

}

bool ReallyLongInt::equal(const ReallyLongInt& other) const{
    if(this->n == other->n){
        return true;
    }
    return false;
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const{
    if(this->n > other->n){
        return true;
    }
    return false;
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const{
    
}