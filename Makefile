#make file for the project polish10 and polish32. 
COMMON = polish.o bounds.o
CC = gcc
CFLAGS =  -Wall -g -std=c99 -c

all: polish10 polish32

polish10: $(COMMON) base10.o
			$(CC) $(COMMON)  base10.o -o polish10

polish32: $(COMMON)  base32.o
			$(CC) $(COMMON)  base32.o -o polish32

polish.o: polish.c bounds.h base.h
			$(CC) $(CFLAGS) -o polish.o polish.c
			
bounds.o: bounds.c bounds.h 
			$(CC) $(CFLAGS) -o bounds.o bounds.c

base10.o: base10.c base.h
			$(CC) $(CFLAGS) -o base10.o base10.c
	
base32.o: base32.c base.h
			$(CC) $(CFLAGS) -o base32.o base32.c

clean: 
		rm -f *.o
		rm -f polish10 polish32 output.txt
