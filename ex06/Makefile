# Makefile for OPS exercise 5
all: printversion getsignal sendsignal


getsignal: getsignal_sendpid.o
	gcc -Wall -o getsignal_sendpid getsignal_sendpid.o

sendsignal: sendsignal_getpid.o
	gcc -Wall -o sendsignal_getpid sendsignal_getpid.o

getsignal.o: getsignal_sendpid.c
	gcc -c -Wall getsignal_sendpid.c

sendsignal.o: sendsignal_getpid.c
	gcc -c -Wall sendsignal_getpid.c

cleanall: clean
	rm -f getsignal_sendpid sendsignal_getpid

printversion:
	gcc --version | grep gcc
