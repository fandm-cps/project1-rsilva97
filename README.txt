Files included in project:

ReallyLongInt.hpp
ReallyLongInt.cpp
ReallyLongInt_TEST.cpp
numberTheory.hpp
numberTheory.cpp
numberTheory_TEST.cpp
keygen.cpp
encrypt.cpp
decrypt.cpp
Makefile
README.txt
catch.hpp

To compile type "make" in the terminal. 

To run unit testing for ReallyLongInt and numberTheory type "./ReallyLongInt_TEST" and "./numberTheory_TEST", respectively, in the terminal. 

To run keygen: In the terminal type "./keygen <number1> <number2> <filename1.txt> <filename2.txt>", where <number1> and <number2> are prime numbers; and <filename1.txt> and <filename2.txt> are the names of the .txt files that will contain the public keys and the private keys, respectively.

To run encrypt: In the terminal type "./encrypt <filename1.txt> <filename2.txt> <filename3.txt>" where <filename1.txt>, <filename2.txt>, and <filename3.txt> are the file with the public keys, a file with a message to be encrypted, and a file with the encrypted message, respectively.

To run encrypt: In the terminal type "./decrypt <filename1.txt> <filename2.txt> <filename3.txt>" where <filename1.txt>, <filename2.txt>, and <filename3.txt> are the file with the private keys, a file with a message to be decrypted, and a file with the decrypted message, respectively.

NOTES:

(1) In encrypt.cpp, instead of converting the values back into characters and putting the characters into the encrypted message, I chose to output the values into the file because some values obtained will not be within the ascii range.

(2) Decryption works fine with small numbers like 11 and 13 into keygen, but it takes a very long time to decrypt the message when larger numbers, such as 257 and 263, are given to keygen.
