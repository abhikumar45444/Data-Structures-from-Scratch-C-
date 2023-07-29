#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // for MIN and MAX function (it contains defintion for minimum and maximum values for datatypes)
#include"LinkedList.h"

/*

struct Term              //use this struct if you want to access head/first pointer of linked list from everywhere
{                        //and dont want to use double pointers and all
    int data;
    struct Term *next;
}*first = NULL;          //declaring head/first of linked list as global pointer

*/
                                           
void LinkedList(struct Term **head)   //here i can also take (struct Term **head) so that we can use pass by reference for main head
{                                           //if i dont want to return Term pointer and directly reflect changes on main head 
     int numOfTerms = 0;
    //int numOfTerms = 2;
    struct Term *current = NULL;
    printf("Enter Number of Terms in Polynomial: ");
    scanf("%d", &numOfTerms);
    *head = malloc(sizeof(struct Term));
    printf("Enter the %d Term Coefficient :\n", 1);
    scanf("%d", &(*head)->coefficient);  
    printf("Enter the %d Term Exponent:\n", 1);
    scanf("%d", &(*head)->exponent);  
    
    // (*head)->coefficient = 1;
    // (*head)->exponent = 2;
    (*head)->next = NULL;

    current = *head;

    for (int i = 1; i < numOfTerms; i++)
    {
        current->next = malloc(sizeof(struct Term));
        current = current->next;
        printf("Enter the %d Term Coefficient :\n", i + 1);
        scanf("%d", &current->coefficient);  
        printf("Enter the %d Term Exponent:\n", i + 1);
        scanf("%d", &current->exponent);

        // current->coefficient = i+1;
        // current->exponent = i + (*head)->exponent;
        current->next = NULL;
    }
}


int CountTerms(struct Term *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}


void InsertAtLast(struct Term **head, int coeff, int expo)
{
    struct Term *p = *head;
    struct Term *newTerm = NULL;
    newTerm = malloc(sizeof(struct Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = expo;
    newTerm->next = NULL;

    if(*head == NULL)
    {
        *head = newTerm;
    }
    else
    {
        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = newTerm;
    }
}


int  DeleteAtPos(struct Term **head)
{
    struct Term *p = *head, *q = NULL;
    int pos = 7, Deletedvalue = 0;
    
    if(pos < 1 || pos > CountTerms(p))
    {
        printf("Invalid Position\n");
        return -1;
    }

    if(pos == 1)
    {
        *head = p->next;
        Deletedvalue = p->exponent;
        free(p);
        return Deletedvalue;
    }
    else
    {
        for (int i = 0; i < pos - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            Deletedvalue = p->exponent;
            free(p);
        }     
        return Deletedvalue;    
    }
    //printf("Problem occured P==Null\n");
    
}


void Display(struct Term *head)
{
    //struct Term *Current = head;
    if(head == NULL)
    {
        return;
    }

    int count = CountTerms(head);

    while (head != NULL)
    {
        //printf("| data: %d | Next: %X | --->", head->data, head->next);
        //printf("data: %d | Next: %X | adress of current: %X --->", head->data, head->next, head);
        if(count > 1)
        {
            if(head->exponent == 0)
            {
                printf("%d + ", head->coefficient);
            }
            else
            {
                printf("%dx^%d + ", head->coefficient, head->exponent);
            }
            head = head->next;
            count--;
        }
        else
        {
            if(head->exponent == 0)
            {
                printf("%d ", head->coefficient);
            }
            else
            {
                printf("%dx^%d ", head->coefficient, head->exponent);
            }
            head = head->next;
            count--;
        }
    }
    printf("\n");
}


void freeList(struct Term** head) // we are using pass by reference here because we also want to set our head as null
{                                 //so our list shows empty if we dont do that head will contain some value and it will break our code (eg: seg fault)
   struct Term* tmp = NULL;
   if(*head == NULL)
   {
       return;
   }

   while (*head != NULL) // it will first break the link to of first Term and then second and the third and so on.....
    {
       tmp = *head;
       *head = (*head)->next;
       free(tmp);
    }
    tmp = NULL;
}