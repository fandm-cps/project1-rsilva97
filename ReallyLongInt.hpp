#ifndef REALLYLONGINT_HPP
#define REALLYLONGINT_HPP

class ReallyLongInt{

    public:
        ReallyLongInt(); //represents the value 0
        ReallyLongInt(long long num); //sets base on num
        ReallyLongInt(const string& numStr); //this is string representation and sets the private member variables
        ReallyLongInt(cont ReallyLongInt& other); // this is needed to make copies
        
        ~ReallyLongInt();

        bool equal(const ReallyLongInt& other) const;
        bool greater(const ReallyLongInt& other) const;

    private:
        vector<bool> *digits = NULL; //the binary digits
        unsigned int size; //the number of digits
        bool isNeg; //the sign of the number
        
        long long n;

        bool absGreater(const ReallyLongInt& other) const;
        string ReallyLongInt::toString() const;
        string ReallyLongInt::toStringBinary() const;
};

#endif
