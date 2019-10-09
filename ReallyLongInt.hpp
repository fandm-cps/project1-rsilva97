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
        string toString() const;
        string toStringBinary() const;
        //Checkpoint 2
        void removeLeadingZeros(void);
        ReallyLongInt& operator=(const ReallyLongInt& other);
        ReallyLongInt operator-() const;
        ReallyLongInt absAdd(const ReallyLongInt& other) const;
        ReallyLongInt add(const ReallyLongInt& other) const;
        ReallyLongInt absSub(const ReallyLongInt& other) const;
        ReallyLongInt sub(const ReallyLongInt& other) const;
        ReallyLongInt mult(const ReallyLongInt& other) const;
        void div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
        friend ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y);
        friend ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y);
        friend ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y);
        friend ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y);
        friend ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y);
        //Checkpoint 3
        ReallyLongInt exp(const ReallyLongInt e );
        bool isPrime();

    private:
        vector<bool> *digits; //the binary digits
        unsigned int size; //the number of digits
        bool isNeg; //the sign of the number
        
        bool absGreater(const ReallyLongInt& other) const;
        //Checkpoint 2
        void swap(ReallyLongInt other);
        void flipSign();
        ReallyLongInt absMult(const ReallyLongInt& other) const;
        void absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
        //Checkpoint 3
        

};

#endif
