# Makefile for OPS exercise 5
all: printversion getsignal sendsignal


getsignal: getsignal.o
	gcc -Wall -o getsignal getsignal.o

sendsignal: sendsignal.o
	gcc -Wall -o sendsignal sendsignal.o

getsignal.o: getsignal.c
	gcc -c -Wall getsignal.c

sendsignal.o: sendsignal.c
	gcc -c -Wall sendsignal.c

cleanall: clean
	rm -f getsignal sendsignal

printversion:
	gcc --version | grep gcc
