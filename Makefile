
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

#default target
all: test

#how to build the libre object file
libmystack.o: src/my_stack.c include/mystack.h
	$(CC) $(CFLAGS) -c src/my_stack.c -o libmystack.o

#how to build test
test: libmystack.o tests/test.c
	$(CC) $(CFLAGS) tests/test.c libmystack.o -o test_stack

#clean up build artifacts
clean:
	del Q/ -f *.o test.exe