#ifndef STACKUSINGLINKEDLIST_H_
#define STACKUSINGLINKEDLIST_H_

#include<stdio.h>
#include<stdlib.h>

// struct TreeNode{
//     int data;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

struct Node        //Structure for Node of LinkedList. it also called self refrential structure
{
    struct TreeNode *nodeptr;
    struct Node *next; //struct pointer of type struct Node that will point to next node of the list
};


struct Stack{
    struct Node **StackPtr;
};


//functions
void Display(struct Node *head);
void InsertNode(struct Node **head, struct TreeNode *value);
struct TreeNode* DeleteNode(struct Node **head);
void freeList(struct Node **head); //using  double ** because we want to free our main function head so it contains NULL after free mallocs

void CreateStack(struct Stack *stack);
void Push(struct Stack *stack, struct TreeNode *value);
struct TreeNode* Pop(struct Stack *stack);
int IsEmpty(struct Stack *stack);
int IsFull(struct Stack *stack);
struct TreeNode* StackTop(struct Stack *stack);
struct TreeNode* Peek(struct Stack *stack, int pos);
void DisplayStack(struct Stack *stack);
void FreeStack(struct Stack *stack);

#endif