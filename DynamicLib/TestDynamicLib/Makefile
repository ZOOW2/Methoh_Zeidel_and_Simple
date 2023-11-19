CC = g++
CFLAGS = -Wall -Werror

all: run

run: main
	./main

.PHONY: all run

iterative_methods.so: iterative_methods.cpp iterative_methods.h
	$(CC) $(CFLAGS) -shared -fPIC -o iterative_methods.so iterative_methods.cpp

main: main.cpp iterative_methods.so
	$(CC) $(CFLAGS) -o main main.cpp -ldl


clean:
	rm -f iterative_methods.so main
