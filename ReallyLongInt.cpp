#include "ReallyLongInt.hpp"

ReallyLongInt::ReallyLongInt(){
    digits = new vector<bool>(1,false);
    size = 1;
    isNeg = false;
}

ReallyLongInt::ReallyLongInt(long long num){
    
    if(num < 0){
        isNeg = true;
        num = num*(-1);
    }
    else{
        isNeg = false;
    }

    size = log2(num)+1;
    digits = new vector<bool>(size, isNeg); 

    long long i = num;
    long long index = 0;

    while(i > 0){

        if(i%2 == 1){
            (*digits)[index] = true;
        }
        else{
            (*digits)[index] =false;
        }

        i = i/2;   
        ++index;  
    }

    reverse(digits->begin(), digits->end());


    /*for(int z = 0; z < size; z++)
    {
        cout << (*digits)[z] << " ";
    }
    cout << endl;*/

}

ReallyLongInt::ReallyLongInt(const string& numStr){
    long long num = stoll(numStr, nullptr, 10);
    
    if(num < 0){
        isNeg = true;
        num = num*(-1);
    }
    else{
        isNeg = false;
    }

    size = log2(num)+1;
    digits = new vector<bool>(size, isNeg);

    long long i = num;
    long long index = 0;

    while(i > 0){
        
        if(i%2 == 1){
            (*digits)[index] = true;
        }
        else{
            (*digits)[index] =false;
        }

        i = i/2;   
        ++index;  
    }

    reverse(digits->begin(), digits->end());

    /*for(int z = 0; z < size; z++)
    {
        cout << (*digits)[z] << " ";
    }
    cout << endl;*/
}       

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other){
    isNeg = other.isNeg;
    size = other.size;
    digits = new vector<bool>(size, isNeg);

    for(long long i = 0; i < size; ++i){
        (*digits)[i] = (*other.digits)[i];
    } 
}

ReallyLongInt::~ReallyLongInt(){
    //cout << "Invoking destructor, clearing up" << endl;

    delete digits;
}

//Returns a string representation of the number stored in base 10
string ReallyLongInt::toString() const{

    long long sum = 0;
    long long loc = size-1;

    for(long long i=0; i < size; ++i){
        //cout << (*digits)[i] << "next" << " " << size <<endl;
        if((*digits)[i] == true){
            sum += pow(2, loc);
        
        }
        loc--;

    }
    //cout << " num: " << sum << endl;

    //cout<<"toString: "<<to_string(sum) << endl;
    string result = to_string(sum);

    if(isNeg){
        result = "-" + result;
    }

    //cout << "String: " << result << endl;
    
    return result;
}

//Returns a string representation of the number stored in base 2
string ReallyLongInt::toStringBinary() const{
    
    string binaryString = "";

    for(long long i=0; i < size; ++i){

        if((*digits)[i] == true){
            binaryString += "1";
        }
        else{
            binaryString += "0";
        }
    }

    //cout << "Binary: " << binaryString << endl;

    if(isNeg){
        binaryString = "-" + binaryString;
    }

    return binaryString;
}

bool ReallyLongInt::equal(const ReallyLongInt& other) const{
    if(isNeg != other.isNeg){
        return false;
    }
    
    for(long long i = 0; i < size; ++i){
        if(digits[i] != other.digits[i]){
            return false;
        }
    }

    return true;
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const{
    if(!isNeg && !other.isNeg){
        return this->absGreater(other);
    }

    if(isNeg && other.isNeg){
        return !this->absGreater(other);
    }

    if(isNeg && !other.isNeg){
        return false;
    }
    return true;
    
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const{
    if(size > other.size){
        return true;
    }
    
    if(size == other.size){
        reverse(digits->begin(), digits->end());
        reverse(other.digits->begin(), other.digits->end());

        for(long long i = 0; i < size; ++i){
            if(digits[i] != other.digits[i]){
                if((*digits)[i]){
                    return true;
                }
                return false;
            }
        }
    }

    return false;
}