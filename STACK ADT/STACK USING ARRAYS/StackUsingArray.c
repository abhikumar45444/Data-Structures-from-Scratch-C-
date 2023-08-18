/*  ************************************ STACK ADT (ABSTRACT DATA TYPE) **********************************************
 *  ADT means :–
 *  1) Representation of Data.
 *  2) Set of Operations on the Data.
 
 *  DEFINITION :-
     A Stack is an ordered list in which insertion and deletion are done at one end, called top. 
     The last element inserted is the first one to be deleted. 
     Hence, it is called the Last in First out (LIFO) or First in Last out (FILO) list.

 *  C does not provides Stack as a basic data structure. 
 *  The structure defintion of Stack (Data Representation) and and the operations on the data are not defined by the compiler.
 *  We have to implement or provide the operations on Stack data structure. 
 *  So, data structure Stack and the set of operations together we can call it as Abstract Data Type (ADT).
 * ____________________________________________________________________________________________________________________*/


    
    
/*


    |   5   |  <-- Stack Top
    |   3   |
    |   2   |                               <-----  Stack Representation
    |___4___|
           -1  <-- Initial Stack Top
            4  <-- Stack size



   Structure Representation -->      struct Stack{                  _____________
                                        int size;                   |___size____|  
                                        int top;                    |____top____|      ___________________
                                        int *A;                     |_____A_____|----->|___|____|____|___|  Array of some size 
                                    }

*/


#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};



void CreateStack(struct Stack *stack);
void Push(struct Stack *stack, int value);
int Pop(struct Stack *stack); 
int Peek(struct Stack stack, int position); 
int IsEmpty(struct Stack stack); 
int IsFull(struct Stack stack);
int StackTop(struct Stack stack);
void FreeStack(struct Stack *stack);

int main()
{
    struct Stack st;
    CreateStack(&st);
    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);
    Push(&st, 50);
    Push(&st, 60);
    printf("%d\n", Peek(st, 1));
    printf("%d\n", Peek(st, 2));
    printf("%d\n", Peek(st, 3));
    printf("%d\n", Peek(st, 4));
    printf("%d\n", Peek(st, 5));
    printf("%d\n", IsFull(st));
    printf("%d\n", Pop(&st));
    printf("%d\n", Pop(&st));
    printf("%d\n", Pop(&st));
    printf("%d\n", Peek(st, 2));
    printf("%d\n", StackTop(st));
    printf("%d\n", Pop(&st));
    printf("%d\n", Pop(&st));
    printf("%d\n", IsEmpty(st));
    printf("%d\n", IsFull(st));
    FreeStack(&st);
    if(st.S == NULL)
    {
        printf("null\n");
    }
    else
    {
        printf("not null\n");
    }
    return 0;
}


void CreateStack(struct Stack *stack)
{
    printf("Enter the size of Stack: ");
    scanf("%d", &stack->size);
    stack->top = -1;
    stack->S = calloc(stack->size, sizeof(int));
}


void Push(struct Stack *stack, int value)
{
    if(stack->top == stack->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack->S[++stack->top] = value;
    }
}

int Pop(struct Stack *stack)
{
    int value = -1;
    if(stack->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        value = stack->S[stack->top--];
    }
    return value;
}


int Peek(struct Stack stack, int position)
{
    int value = -1;
    int index = stack.top - position + 1;
    if(index < 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        value = stack.S[index];
    }
    return value;
}


int IsEmpty(struct Stack stack)
{
    if(stack.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int IsFull(struct Stack stack)
{
    if(stack.top == stack.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int StackTop(struct Stack stack)
{
    if(stack.top == -1)
    {
        return -1;
    }
    else
    {
        return stack.S[stack.top];
    }
}



void FreeStack(struct Stack *stack)
{
    free(stack->S);
    stack->S = NULL;
}