#ifndef REALLYLONGINT_HPP
#define REALLYLONGINT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class ReallyLongInt{

    public:
        ReallyLongInt(); //represents the value 0
        ReallyLongInt(long long num); //sets base on num
        ReallyLongInt(const string& numStr); //this is string representation and sets the private member variables
        ReallyLongInt(const ReallyLongInt& other); // this is needed to make copies
        
        ~ReallyLongInt();

        bool equal(const ReallyLongInt& other) const;
        bool greater(const ReallyLongInt& other) const;
        unsigned int getSize() const;
        string toString() const;
        string toStringBinary() const;

    private:
        vector<bool> *digits; //the binary digits
        unsigned int size; //the number of digits
        bool isNeg; //the sign of the number
        
        bool absGreater(const ReallyLongInt& other) const;
};

#endif
