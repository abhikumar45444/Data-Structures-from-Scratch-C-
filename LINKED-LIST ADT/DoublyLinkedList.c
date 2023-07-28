#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *previous;
    int data;
    struct Node *next;
};

void DoublyLinkedList(struct Node **head);
void Display(struct Node *head);
int CountNode(struct Node *head);
void FreeList(struct Node **head);
void Insert(struct Node **head, int pos, int x);
void Delete(struct Node **head, int pos);
void ReverseList(struct Node **head);


int main()
{                             //check in linkedlist method -> number of elements
    struct Node *head = NULL;
    DoublyLinkedList(&head);
    //Display(head);

     Insert(&head, 0, 60);
     Insert(&head, 1, 70);
     Insert(&head, 7, 80);
     Insert(&head, 7, 90);
     Display(head);

    //Delete(&head, 9);
    //Delete(&head, 1);
    //Delete(&head, 7);
     ReverseList(&head);
     Display(head);
    FreeList(&head);
    if(head == NULL)
    {
        printf("head is null\n");
    }
    else
    {
        printf("head not Null\n");
    }
    return 0;
}

void DoublyLinkedList(struct Node **head)
{
    int numberOfElements = 5;

    struct Node *p = NULL;
    struct Node *t = NULL;
    
    if(numberOfElements == 0)
    {
        return;
    }

    t = malloc(sizeof(struct Node));
    t->next = NULL;
    t->previous = NULL;
    t->data = 10;

    *head = t;
    p = *head;

    for (int i = 0; i < numberOfElements - 1; i++)
    {
        t = malloc(sizeof(struct Node));
        t->data = i * 10 + 20;
        t->next = NULL;
        t->previous = p;
        p->next = t;
        p = t;
    }
}

int CountNode(struct Node *head)
{
    int count = 0;
    if (head == NULL)
    {
        return count;
    }

    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

void Insert(struct Node **head, int pos, int x)
{
    struct Node *temp = NULL, *p = NULL;

    if(pos < 0 || pos > CountNode(*head))
    {
        printf("INvalid Pos!\n");
        return;
    }

    if(pos == 0)
    {
        temp = malloc(sizeof(struct Node));
        temp->data = x;
        temp->next = *head;
        temp->previous = NULL;
        if((*head))
        {
            (*head)->previous = temp;
        }
        *head = temp;
    }
    else
    {
        temp = malloc(sizeof(struct Node));
        temp->data = x;

        p = *head;

        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        temp->next = p->next;
        temp->previous = p;
        if(p->next)
        {
            p->next->previous = temp;
        }
        p->next = temp;
    }
}


void Delete(struct Node **head, int pos)
{
    struct Node *p = NULL;
    int x = 0;
    if(pos < 1 || pos > CountNode(*head))
    {
        printf("Invalid position!\n");
        return;
    }
    
    if(*head == NULL)
    {
        printf("empty!\n");
        return;
    }

    if(pos == 1)
    {
        p = *head;
        *head = p->next;
        if(*head)
        {
            (*head)->previous = NULL;
        }
        x = p->data;
        free(p);
        printf("deleted node value is %d\n", x);
    }
    else
    {
        p = *head;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        x = p->data;
        p->previous->next = p->next;
        if(p->next)
        {
            p->next->previous = p->previous;
        }
        free(p);
        printf("deleted node value is %d\n", x);
    }
}


void ReverseList(struct Node **head)
{
    struct Node *p = *head, *temp = NULL;

    if(*head == NULL)
    {
        return;
    }

    while(p != NULL)
    {
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        p = p->previous;
        if(p != NULL && p->next == NULL)
        {
            *head = p;
        }
    }
}


void Display(struct Node *head)
{
    if(head == NULL)
    {
        printf("Empty!!\n");
        return;
    }

    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void FreeList(struct Node **head)
{
    struct Node *temp = NULL;
    if(*head == NULL)
    {
        return;
    }

    temp = *head;
    while(temp != NULL)
    {
        temp = temp->next;
        free(*head);
        *head = temp;
    }
    
}




// int main()
// {
//     struct Node *head = NULL, *headTraversePtr = NULL, *tail = NULL, *tailTraversePtr = NULL;
//     struct Node node1 = {NULL, 10, NULL};
//     struct Node node2 = {NULL, 20, NULL};
//     struct Node node3 = {NULL, 30, NULL};

//     head = &node1;
//     tail = &node3;
//     headTraversePtr = head;
//     tailTraversePtr = tail;
//     node1.next = &node2;
//     node2.previous = &node1;
//     node2.next = &node3;
//     node3.previous = &node2;
    
//     while(headTraversePtr != NULL)
//     {
//         printf("%d ", headTraversePtr->data);
//         headTraversePtr = headTraversePtr->next;
//     }
//     printf("\n");

//     while(tailTraversePtr != NULL)
//     {
//         printf("%d ", tailTraversePtr->data);
//         tailTraversePtr = tailTraversePtr->previous;
//     }

//     printf("\n");
//     return 0;
// }