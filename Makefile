CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g 
COVERAGE = --coverage 

all: catchdebug 


ReallyLongInt.o: ReallyLongInt.cpp
	$(CC) -c ReallyLongInt.cpp

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
	$(CC) $(CFLAGS) $(CATCHINC) -o ReallyLongIntTEST ReallyLongInt_TEST.cpp ReallyLongInt.o

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) ReallyLongInt_TEST.cpp ReallyLongInt.cpp

clean:
	rm *.o; rm main; VectorDebug
