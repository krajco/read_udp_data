CC=g++
CFLAGS= -std=c++11 -pedantic

all: myripsniffer

myripsniffer:
	$(CC) $(CFLAGS) ripsniffer.cpp -lpcap -o myripsniffer

clean:
	rm myripsniffer

tar:
	tar -cf xkrajc17.tar *.cpp *.h Makefile
