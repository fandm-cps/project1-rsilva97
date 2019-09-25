CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g 
COVERAGE = --coverage 

all: catchdebug 


ReallyLongInt.o: ReallyLongInt.cpp
	$(CC) -c ReallyLongInt.cpp

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
	$(CC) $(CFLAGS) -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.o

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(COVERAGE) ReallyLongInt_TEST.cpp ReallyLongInt.cpp

clean:
	rm *.o; rm ReallyLongInt_TEST
