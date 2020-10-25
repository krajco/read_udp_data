CC=g++
CFLAGS= -std=c++11 -Wall -pedantic
all: udpreader

udpreader: global.h udpreader.cpp
	$(CC) $(CFLAGS) udpreader.cpp -lpcap -o udpreader

clean:
	rm udpreader

tar:
	tar -cf xkrajc17.tar *.cpp *.h Makefile
