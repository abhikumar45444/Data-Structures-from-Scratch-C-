// #include<stdio.h>
// #include<stdlib.h>
#include"StackUsingLinkedList.h"

/*

struct Node              //use this struct if you want to access head/first pointer of linked list from everywhere
{                        //and dont want to use double pointers and all
    int nodeptr;
    struct Node *next;
}*first = NULL;          //declaring head/first of linked list as global pointer

*/


// struct Stack{
//     struct Node **StackPtr;
// };


void CreateStack(struct Stack *stack)
{
    stack->StackPtr = calloc(1, sizeof(struct Node));
}

void Push(struct Stack *stack, struct TreeNode *value)
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

struct TreeNode* Pop(struct Stack *stack)
{
    struct TreeNode *value = DeleteNode(stack->StackPtr);
    if(value == 0)
    {
         //printf("Stack Underflow!\n");

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

struct TreeNode* StackTop(struct Stack *stack)
{
    if(stack->StackPtr == NULL)
    {
        return 0;
    }

    struct Node *p = *(stack->StackPtr);
    return (*(stack->StackPtr))->nodeptr;
}

struct TreeNode* Peek(struct Stack *stack, int pos)
{
    struct Node *p = *(stack->StackPtr);

    for (int i = 0; p != NULL && i < pos - 1; i++)
    {
        p = p->next;
    }

    if(p != NULL && pos > 0)
        return p->nodeptr;
    else
        return 0;
}


void DisplayStack(struct Stack *stack)
{
    Display(*(stack->StackPtr));
}

void FreeStack(struct Stack *stack)
{
    freeList(stack->StackPtr);
}



                                           

void InsertNode(struct Node **head, struct TreeNode *value)
{
    struct Node *newNode = NULL;
    struct Node *p = *head;
    
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Malloc Exception!\n");
        return;
    }

    newNode->nodeptr = value;
    // newNode->next = NULL;

    newNode->next = *head;
    *head = newNode;
}




struct TreeNode* DeleteNode(struct Node **head)
{
    struct Node *p = *head;
    // int deleteValue = 0;
    struct TreeNode *deleteValue = NULL;
    if(*head != NULL)
    {
        *head = p->next;
        deleteValue = p->nodeptr;
        free(p);
    }
    return deleteValue;
}



void Display(struct Node *head)
{
    //struct Node *Current = head;
    if(head == NULL)
    {
        printf("Stack is Empty!\n");
        return;
    }

    while (head != NULL)
    {
        //printf("| nodeptr: %d | Next: %X | --->", head->nodeptr, head->next);
        //printf("nodeptr: %d | Next: %X | adress of current: %X --->", head->nodeptr, head->next, head);
        printf("%d ", head->nodeptr);
        head = head->next;
    }
    printf("\n");
}


void freeList(struct Node** head) // we are using pass by reference here because we also want to set our head as null
{                                 //so our list shows empty if we dont do that head will contain some value and it will break our code (eg: seg fault)
   struct Node* tmp = NULL;
   if(*head == NULL)
   {
       return;
   }

   while (*head != NULL) // it will first break the link to of first node and then second and the third and so on.....
    {
       tmp = *head;
       *head = (*head)->next;
       free(tmp);
    }
    tmp = NULL;
}