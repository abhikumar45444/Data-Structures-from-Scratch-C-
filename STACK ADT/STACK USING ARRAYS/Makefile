CC=gcc -Wall
CFLAGS=-I.
DEPS = 
OBJ = StackUsingArray.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

StackUsingArray: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)