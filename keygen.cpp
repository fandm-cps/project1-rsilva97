#include <iostream>
#include <fstream>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

using namespace std;

int main(int argc, char* argv[]){

    ReallyLongInt zero, p(argv[1]), q(argv[2]), n, t, e, d, one(1), x, y, gcd;
    numberTheory num;

    if(!p.isPrime() || !q.isPrime()){
        cout << "ERROR: At least one of the numbers provided is not prime!" << endl;
        return 1;
    }

    n = p * q;
    t = (p - one) * (q - one);

    for(ReallyLongInt search(2); ; search = search + one){
        gcd = num.extendedEuclid(search, t, x, y);

        if(gcd.equal(one)){
            e = search;
            break;
        }
    }

    d = x;

    //add rules to make d pos

    if(zero.greater(x)){
        t = t + x;
    }

    ofstream myFile;
    ofstream otherFile;

    myFile.open(argv[3]);
    myFile << e.toString() << " " << n.toString() << "\n";
    myFile.close();

    otherFile.open(argv[4]);
    otherFile << d.toString() << " " << n.toString() << "\n";
    otherFile.close();

    return 0;
}