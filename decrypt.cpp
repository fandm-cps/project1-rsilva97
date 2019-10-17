#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

using namespace std;

int main(int argc, char* argv[]){

    bool endProgram = false;

    ReallyLongInt d, n;

    ifstream keyFile;
    keyFile.open(argv[1], ios_base::in);

    if(keyFile.is_open()){
        string fileContents;
        vector<string> results;

        getline(keyFile, fileContents);

        boost::split(results, fileContents, [](char c){return c == ' ';});
        
        ReallyLongInt tmpD(stoll(results[0], nullptr, 10));
        ReallyLongInt tmpN(stoll(results[1], nullptr, 10));

        d = tmpD;
        n = tmpN;

        keyFile.close();
    }
    else{
        cout << "open() failed: check if file is in right folder" << endl;
        endProgram = true;
    }

    if(!endProgram){
        ifstream inFile;
        ofstream outFile;
        inFile.open(argv[2], ios_base::in);
        outFile.open(argv[3], ios_base::out);

        if(inFile.is_open() && outFile.is_open()){
            //char ch;
            long long a, ascii;
                //inFile >> ascii;
            while(inFile >> a){
                /*//ascii = int(ch);
                //cout << ascii << endl;
                ReallyLongInt y(ascii);
                ReallyLongInt x(y.exp(d) % n);
                outFile << char(stoll(x.toString(), nullptr, 10));
                inFile >> ascii;*/

                ReallyLongInt y(a);
                ReallyLongInt x(y.exp(d) % n);
                outFile << char(stoll(x.toString(), nullptr, 10));

            }

            inFile.close();
            outFile.close();
        }
        else{
            cout << "open() failed: check if file is in right folder" << endl;
        }
    }

    return 0;
}