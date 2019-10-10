CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g 
COVERAGE = --coverage 

all: catchdebug catchdebug1 keygen

ReallyLongInt.o: ReallyLongInt.cpp ReallyLongInt.hpp
	$(CC) -c ReallyLongInt.cpp

numberTheory.o: numberTheory.cpp numberTheory.hpp
	$(CC) -c numberTheory.cpp

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
	$(CC) $(CFLAGS) -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.o

catchdebug1: numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o
	$(CC) $(CFLAGS) -o numberTheory_TEST numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o

keygen: keygen.cpp numberTheory.o ReallyLongInt.o
	$(CC) -o keygen keygen.cpp numberTheory.cpp ReallyLongInt.o

encrypt: encrypt.cpp numberTheory.o ReallyLongInt.o
	$(CC) -o encrypt encrypt.cpp numberTheory.cpp

decrypt: decrypt.cpp numberTheory.o ReallyLongInt.o
	$(CC) -o decrypt decrypt.cpp numberTheory.cpp

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(COVERAGE) ReallyLongInt_TEST.cpp ReallyLongInt.cpp

coverage1: numberTheory_TEST.cpp numberTheory.cpp
	$(CC) $(CFLAGE) $(COVERAGE) numberTheory_TEST.cpp numberTheory.cpp

clean:
	rm *.o; rm ReallyLongInt_TEST; rm numberTheory_TEST
