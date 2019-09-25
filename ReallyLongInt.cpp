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
}       

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other){
    isNeg = other.isNeg;
    size = other.size;
    digits = new vector<bool>(size, isNeg);

    for(long long i = 0; i < size; ++i){
        (*digits)[i] = (*other.digits)[i];
    } 
}

ReallyLongInt::~ReallyLongInt(){ delete digits; }

string ReallyLongInt::toString() const{

    long long sum = 0;
    long long loc = size-1;

    for(long long i=0; i < size; ++i){
        
        if((*digits)[i] == true){
            sum += pow(2, loc);
        
        }
        loc--;

    }
    
    string result = to_string(sum);

    if(isNeg){
        result = "-" + result;
    }
    
    return result;
}

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
        if((*digits)[i] != (*other.digits)[i]){
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
            if((*digits)[i] != (*other.digits)[i]){
                if((*digits)[i]){
                    return true;
                }
                return false;
            }
        }
    }

    return false;
}

//Checkpoint 2

void ReallyLongInt::removeLeadingZeros(void){
    long long count = 0;
    
    for(long long i = 0; i < size; i++){
        if((*digits)[i] == false){
            count++;
        }
        else if((*digits)[i]){
            break;
        }
    }

    size -= count;
    vector<bool> *tmp = new vector<bool>(size, isNeg);
    long long j = 0;

    for(long long k = count; k < (size+count); k++){
        (*tmp)[j] = (*digits)[k];
        j++;
    }
    
    delete digits;
    digits = tmp;
    

}

void ReallyLongInt::swap(ReallyLongInt other){

    std::swap(digits, other.digits); //also works without * ??
    std::swap(size, other.size);
    std::swap(isNeg, other.isNeg);

}

ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other){
    swap(other);
    return *this;
}

ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const{
    //vector<bool> *total = new vector<bool>((max(size, other.size)+1), isNeg);
    
    vector<bool> total((std::max(size, other.size)+1), isNeg);
    long long i = size - 1;
    long long j = other.size - 1;
    long long k = std::max(size, other.size);
    long long partSum = 0;

    while(k >= 0 && (i >= 0 || j >= 0 || partSum == 1)){
        if(i >= 0){
            if((*digits)[i]){
                partSum += 1;
            }
        }
        if(j >= 0){
            if((*other.digits)[j]){
                partSum += 1;
            }
        }

        if(partSum % 2 == 0){
            (total)[k] = false; // deleted *
        }
        else{
            (total)[k] = true;  // deleted *
        }

        partSum /= 2;
        i--;
        j--;
        k--;
    }

    ReallyLongInt result;
    *result.digits = total; //added *
    result.size = (std::max(size, other.size)+1);
    result.isNeg = false;

    return result;

}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const{
    if(!isNeg && !other.isNeg){
        return this->absAdd(other);
    }
    else if(isNeg && other.isNeg){
        ReallyLongInt result = this->absAdd(other);
        result.isNeg = true;
        return result;
    }
    else if(isNeg && !other.isNeg){
        return other.sub(*this);
    }
    return this->sub(other);
}

void ReallyLongInt::flipSign(){

}

ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const{
    vector<bool> total(std::max(size, other.size), isNeg), *top, *bottom;
    long long i, j, k, partial, index;
    ReallyLongInt result;
    result.size = std::max(size, other.size);
    result.isNeg = false;

    for(int z = 0; z<size;z++){
            cout<<(*digits)[z]<<" ";
        }
        cout<<endl;
    for(int u = 0; u<other.size;u++){
            cout<<(*other.digits)[u]<<" ";
        }
        cout<<endl;

    if(*digits == *(other.digits)){
        cout<<"in here"<<endl;
        return result;
    }

    if(size < other.size){
        top = other.digits;
        bottom = digits;
        i = other.size - 1;
        j = size - 1;
        result.isNeg = true;
        cout<<"A"<<endl;
    }
    else if(size > other.size){
        top = digits;
        bottom = other.digits;
        
        i = size - 1;
        j = other.size - 1;
        cout<<"B"<<endl;
    }
    else{
        if(this->absGreater(other)){
            top = digits;
            bottom = other.digits;
            i = size - 1;
            j = other.size - 1;
            cout<<"C"<<endl;
        }
        else{
            top = other.digits;
            bottom = digits;
            i = other.size - 1;
            j = size - 1;
            result.isNeg = true;
            cout<<"D"<<endl;
        }
    }

    

    k = std::max(i,j);

    while(k >= 0 && (i >= 0 || j >= 0)){

        //cout << "i, j, k: " << i << " " << j << " " << k << endl;

        if(i >= 0){
            partial += ((*top)[i])? 1 : 0;
        }
        if(j >= 0){
            partial -= ((*bottom)[j])? 1 : 0;
        }

        if(i>=0 && j>=0){
            if(!(*top)[i] && (*bottom)[j]){
                index = i;
                while(index >= 0){
                    index--;
                    if((*top)[index]){
                       (*top)[index] = false;
                       break;
                    }
                    else{
                     (*top)[index] = true;
                    }
                }
                (total)[k] = true;
            }
        }

        //cout << "hi" << endl;
        if(partial == 0){
            (total)[k] = false;
        }
        else if(partial == 1){
            (total)[k] = true;
        }
        partial = 0;
        //cout << "hello" <<endl;

        i--;
        j--;
        k--;
    }

    *result.digits = total;
    result.removeLeadingZeros();    

    return result;
}

ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const{
    
}