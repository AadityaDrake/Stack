CFLAGS  = -Wall -std=c11 -g
LIBS = -lm

.PHONY: clean 

all : stack

clean :
	rm -f *.o  *~ stack tst
	rm -rf *.dSYM

stack: ui.o stack.o main.o expressions.o queue.o
	gcc $(CFLAGS) -o stack ui.o stack.o expressions.o queue.o main.o $(LIBS)

test : test.c ui.o stack.o expressions.o queue.o
	gcc $(CFLAGS) -o tst ui.o stack.o expressions.o queue.o test.c

main.o : ui.o stack.o main.c stack.h ui.h
	gcc $(CFLAGS) -c main.c

ui.o : stack.o ui.c ui.h stack.h
	gcc $(CFLAGS) -c ui.c

stack.o : stack.c stack.h
	gcc $(CFLAGS) -c stack.c

queue.o : queue.c queue.h
	gcc $(CFLAGS) -c queue.c

expressions.o : expressions.c expressions.h
	gcc $(CFLAGS) -c expressions.c
