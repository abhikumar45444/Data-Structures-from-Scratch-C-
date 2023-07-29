CC=gcc -Wall
CFLAGS=-I.
DEPS = LinkedList.h
OBJ = LinkedList.o PolynomialUsingLinkedList.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

PolynomialUsingLinkedList: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)