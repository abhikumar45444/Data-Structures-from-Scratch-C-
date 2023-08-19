#include<stdio.h>
#include<stdlib.h>

struct Node        //Structure for Node of LinkedList. it also called self refrential structure
{
    int data;
    struct Node *next; //struct pointer of type struct Node that will point to next node of the list
};

//functions
void Display(struct Node *head);
void InsertNode(struct Node **head, int value);
int DeleteNode(struct Node **head);
void freeList(struct Node **head); //using  double ** because we want to free our main function head so it contains NULL after free mallocs