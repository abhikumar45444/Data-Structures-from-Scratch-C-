// #include<stdio.h>
// #include<stdlib.h>
#include"LinkedList.h"

/*

struct Node              //use this struct if you want to access head/first pointer of linked list from everywhere
{                        //and dont want to use double pointers and all
    int data;
    struct Node *next;
}*first = NULL;          //declaring head/first of linked list as global pointer

*/
                                           

void InsertNode(struct Node **head, int value)
{
    struct Node *newNode = NULL;
    struct Node *p = *head;
    
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Malloc Exception!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    newNode->next = *head;
    *head = newNode;
}




int DeleteNode(struct Node **head)
{
    struct Node *p = *head, *q = NULL;
    int deleteValue = 0;
    if(*head != NULL)
    {
        *head = p->next;
        deleteValue = p->data;
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
        //printf("| data: %d | Next: %X | --->", head->data, head->next);
        //printf("data: %d | Next: %X | adress of current: %X --->", head->data, head->next, head);
        printf("%d ", head->data);
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