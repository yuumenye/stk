$(CC) := g++

all: stk

stk: main.o stack.o
	$(CC) $^ -o $@

main.o: main.cpp
	$(CC) -c main.cpp

stack.o: stack.cpp
	$(CC) -c stack.cpp

clean:
	rm -rf *.o stk
