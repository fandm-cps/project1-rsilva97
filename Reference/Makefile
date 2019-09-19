CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g  #-D means to define a macro name
COVERAGE = --coverage 

all: main 


Vector.o: Vector.cpp
	$(CC) -c Vector.cpp

main.o: main_ref.cpp
	$(CC) -c main_ref.cpp

main: main.o Vector.o
	$(CC) $(CFLAGS) -o main main_ref.o Vector.o

debug: Vector.cpp
	$(CC) $(DEBUG) $(CFLAGS)  -o VectorDebug Vector.cpp

catchdebug: Vector_Unit.cpp Vector.o
	$(CC) $(CFLAGS) $(CATCHINC) -o VectorUnit Vector_Unit.cpp Vector.o

coverage: Vector_Unit.cpp Vector.cpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) Vector_Unit.cpp Vector.cpp

clean:
	rm *.o; rm main; VectorDebug

#CATCHINC = -I/Users/jbooth1/courses/cs3/fall2017/unit_testing/Catch-master/single_include
