CC=gcc
CFLAGS=-I.
DEPS = StackUsingLinkedList.h Queue.h
OBJ = StackUsingLinkedList.o Queue.o BinaryTreeIterativePreorder.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

BinaryTreeIterativePreorder: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)