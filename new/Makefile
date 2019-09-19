CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g 
COVERAGE = --coverage 

all: catchdebug 


ReallyLongInt.o: rli.cpp
	$(CC) -c rli.cpp

catchdebug: rli_TEST.cpp rli.o
	$(CC) $(CFLAGS) $(CATCHINC) -o rliTEST rli_TEST.cpp rli.o

debug: rli.cpp
	$(CC) $(DEBUG) $(CFLAGS)  -o rliDebug rli.cpp

coverage: rli_TEST.cpp rli.cpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) rli_TEST.cpp rli.cpp

clean:
	rm *.o; rliDebug
