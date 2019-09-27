#include "ReallyLongInt.hpp"

ReallyLongInt::ReallyLongInt(){
    digits = new vector<bool>(1,false);
    size = 1;
    isNeg = false;
}

ReallyLongInt::ReallyLongInt(long long num){
    
    if(num == 0){
        isNeg = false;
        digits = new vector<bool>(1,false);
        size = 1;
    }
    else{
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
        //reverse(digits->begin(), digits->end());
        //reverse(other.digits->begin(), other.digits->end());

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
    ReallyLongInt result;

    if(!isNeg && !other.isNeg){
        return this->absAdd(other);
    }
    else if(isNeg && other.isNeg){
        result = this->absAdd(other);
        result.flipSign();
        return result;
    }
    else if(!isNeg && other.isNeg){
        return this->absSub(other);
    }
    
    result = this->absSub(other);
    result.flipSign();
    return result;
}

void ReallyLongInt::flipSign(){
    if(size == 1 && !(*digits)[0]){
        isNeg = false;
    }
    else{
        isNeg = (isNeg)? false : true;
    }
}

ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const{
    vector<bool> total(std::max(size, other.size), isNeg), *top, *bottom;
    long long i, j, k, partial = 0, index;
    ReallyLongInt result;
    result.size = std::max(size, other.size);
    result.isNeg = false;

    if(*digits == *(other.digits)){
        return result;
    }   

    if(size < other.size){
        top = other.digits;
        bottom = digits;
        i = other.size - 1;
        j = size - 1;
        result.isNeg = true;
    }
    else if(size > other.size){
        top = digits;
        bottom = other.digits;
        
        i = size - 1;
        j = other.size - 1;
    }
    else{
        if((this->absGreater(other))){
            top = digits;
            bottom = other.digits;
            i = size - 1;
            j = other.size - 1;
        }
        else{
            top = other.digits;
            bottom = digits;
            i = other.size - 1;
            j = size - 1;
            result.isNeg = true;
        }
    }
    vector<bool> topCopy(i+1, isNeg);
    for(long long z = 0; z < i+1; z++){
        (topCopy)[z] = (*top)[z];
    }

    /*for(long long z = 0; z < i+1; z++){
        cout << (topCopy)[z] << " ";
    }
    cout << endl;*/

    long long pi = i;

    k = std::max(i,j);

    while(k >= 0 && (i >= 0 || j >= 0)){

        if(i >= 0){
            partial += ((topCopy)[i])? 1 : 0;
        }
        if(j >= 0){
            partial -= ((*bottom)[j])? 1 : 0;
        }

        if(i>=0 && j>=0){
            if(!(topCopy)[i] && (*bottom)[j]){
                index = i;
                while(index >= 0){
                    index--;
                    if((topCopy)[index]){
                       (topCopy)[index] = false;
                       break;
                    }
                    else{
                     (topCopy)[index] = true;
                    }
                }
                (total)[k] = true;
            }
        }

        if(partial == 0){
            (total)[k] = false;
        }
        else if(partial == 1){
            (total)[k] = true;
        }
        partial = 0;

        i--;
        j--;
        k--;
    }

    /*cout << "topCopy: ";
    for(long long z = 0; z < pi+1; z++){
        cout << (topCopy)[z] << " ";
    }
    cout << endl;

    cout << "top: ";
    for(long long z = 0; z < pi+1; z++){
        cout << (*top)[z] << " ";
    }
    cout << endl;*/

    *result.digits = total;
    result.removeLeadingZeros();    

    return result;
}

ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const{
    ReallyLongInt result;
    
    if(isNeg && !other.isNeg){
        result = this->absAdd(other);
        result.flipSign();
        return result;
    }
    else if(!isNeg && other.isNeg){
        return this->absAdd(other);
    }
    else if(!isNeg && !other.isNeg){
        return this->absSub(other);
    }
    else{
        
            result = this->absSub(other);
            result.flipSign();
            return result;
       
    }

}

ReallyLongInt ReallyLongInt::operator-() const{
    ReallyLongInt result = *this;
    result.flipSign();
    return result;
}

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.add(y);
}

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.sub(y);
}

ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const{
    //cout<<"Entering absMult."<<endl;
    ReallyLongInt result;
    result.isNeg = false;
    result.size = size + other.size;
    vector<bool> *top, *bottom, total((size + other.size), false);
    long long topSize = 0, botSize = 0, index = 0, sumIndex = 0, k = 0;

    if((size == 1 && !(*digits)[0]) || (other.size == 1 && !(*other.digits)[0])){
        result.size = 1;
        return result;
    } 

    if(size > other.size || size == other.size){
        top = digits;
        bottom = other.digits;
        topSize = size;
        botSize = other.size;
        //cout<<"A"<<endl;
    }
    else{
        top = other.digits;
        bottom = digits;
        topSize = other.size;
        botSize = size;
        //cout<<"B"<<endl;
    }
    index = topSize + botSize - 1;
    sumIndex = index;

    for(long long i = botSize-1; i >= 0; i--){
        //cout<<"First loop iteration at index "<<i<<endl;
        if((*bottom)[i]){   
            for(long long j = topSize-1; j >= 0; j--){
                //cout<<"Second loop iteration at index "<<j<<endl;
                if((*top)[j] && (*bottom)[i]){
                    if((total)[sumIndex]){
                        //cout<<"here"<<endl;
                        do{
                            (total)[sumIndex-k] = false;
                            k++;
                        }while((sumIndex-k >= 0) && (total)[sumIndex-k]);
                        (total)[sumIndex-k] = true;
                        k = 0;
                    }
                    else{
                        (total)[sumIndex] = true;
                    }
                }

                sumIndex--;
            }
        }
        index--;
        sumIndex = index;
    }

    *result.digits = total;
    result.removeLeadingZeros();
    return result;
}

ReallyLongInt ReallyLongInt::mult(const ReallyLongInt& other) const{ 
    if((isNeg && other.isNeg) || (!isNeg && !other.isNeg)){
        return this->absMult(other);
    }
    ReallyLongInt result = this->absMult(other);
    result.flipSign();
    return result;

}

ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.mult(y);
}

void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const{

}

/*void ReallyLongInt::div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const{

}

ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.div(y);
}

ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.mult(y);
}*/