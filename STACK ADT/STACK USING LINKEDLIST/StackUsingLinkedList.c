// #include<stdio.h>
// #include<stdlib.h>
#include"LinkedList.h"

struct Stack{
    struct Node **StackPtr;
};

void CreateStack(struct Stack *stack);
void Push(struct Stack *stack, int value);
int Pop(struct Stack *stack);
int IsEmpty(struct Stack *stack);
int IsFull(struct Stack *stack);
int StackTop(struct Stack *stack);
int Peek(struct Stack *stack, int pos);
void DisplayStack(struct Stack *stack);
void FreeStack(struct Stack *stack);

int main()
{
    struct Stack st;
    CreateStack(&st);
    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    DisplayStack(&st);
    Pop(&st);
    Pop(&st);
    Push(&st, 50);
    DisplayStack(&st);
    printf("stack top is: %d\n",StackTop(&st));
    printf("data at pos %d is: %d\n",3,Peek(&st, 3));
    FreeStack(&st);
    if(*(st.StackPtr) == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("NOT NULL\n");
    }
    return 0;
}


void CreateStack(struct Stack *stack)
{
    stack->StackPtr = calloc(1, sizeof(struct Node));
}

void Push(struct Stack *stack, int value)
{
    struct Node *p = NULL;
    p = malloc(sizeof(struct Node));
    if(p == NULL)
    {
        printf("Stack Overflow!\n");
        return;
    }

    InsertNode(stack->StackPtr, value);
}

int Pop(struct Stack *stack)
{
    
    int value = DeleteNode(stack->StackPtr);
    if(value == 0)
    {
        printf("Stack Underflow!\n");
    }
    return value;
}

int IsEmpty(struct Stack *stack)
{
    if(stack->StackPtr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(struct Stack *stack)
{
    struct Node *newNode = NULL;
    int value = 0;
    newNode = malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Stack OverFlow!");
        value = 1;
    }
    free(newNode);
    return value;
}

int StackTop(struct Stack *stack)
{
    if(stack->StackPtr == NULL)
    {
        return 0;
    }

    struct Node *p = *(stack->StackPtr);
    return (*(stack->StackPtr))->data;
}

int Peek(struct Stack *stack, int pos)
{
    struct Node *p = *(stack->StackPtr);

    for (int i = 0; p != NULL && i < pos - 1; i++)
    {
        p = p->next;
    }

    if(p != NULL && pos > 0)
        return p->data;
    else
        return -1;
}


void DisplayStack(struct Stack *stack)
{
    Display(*(stack->StackPtr));
}

void FreeStack(struct Stack *stack)
{
    freeList(stack->StackPtr);
}