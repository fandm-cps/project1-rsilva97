CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g 
COVERAGE = --coverage 

all: catchdebug catchdebug1


ReallyLongInt.o: ReallyLongInt.cpp
	$(CC) -c ReallyLongInt.cpp

numberTheory.o: numberTheory.cpp
	$(CC) -c numberTheory.cpp

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
	$(CC) $(CFLAGS) -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.o

catchdebug1: numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o
	$(CC) $(CFLAGS) -o numberTheory_TEST numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(COVERAGE) ReallyLongInt_TEST.cpp ReallyLongInt.cpp

coverage1: numberTheory_TEST.cpp numberTheory.cpp
	$(CC) $(CFLAGE) $(COVERAGE) numberTheory_TEST.cpp numberTheory.cpp

clean:
	rm *.o; rm ReallyLongInt_TEST; rm numberTheory_TEST
