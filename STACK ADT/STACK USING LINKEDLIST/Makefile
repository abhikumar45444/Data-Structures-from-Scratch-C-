CC=gcc
CFLAGS=-I.
DEPS = LinkedList.h
OBJ = LinkedList.o StackUsingLinkedList.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

StackUsingLinkedList: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)