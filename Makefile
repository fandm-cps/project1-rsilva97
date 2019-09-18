CC = g++
flags = -g -O0

all: ReallyLongInt

gdb_demo: ReallyLongInt.cpp
	$(CC) $(flags) -o ReallyLongInt.exe ReallyLongInt.cpp

clean: rm ReallyLongInt.exe;
