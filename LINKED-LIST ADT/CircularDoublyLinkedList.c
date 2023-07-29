#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
};

void CreateList(struct Node **head);
int CountNodes(struct Node *head);
void Insert(struct Node **head, int pos, int value);
void Delete(struct Node **head, int pos);
void Display(struct Node *head);
void FreeList(struct Node **head);


int main()
{
    struct Node *head = NULL;
    CreateList(&head);
    Display(head);
    Insert(&head, 3, 70);
    Delete(&head, 2);
    Display(head);
    FreeList(&head);
    if(head == NULL)
    {
        printf("Head is null!\n");
    }
    else
    {
        printf("Head is not null\n");
    }
    return 0;
}

void CreateList(struct Node **head)
{
    int noOfElements = 3;
    struct Node *p = NULL, *newNode = NULL;

    if(noOfElements == 0)
    {
        return;
    }

    newNode = malloc(sizeof(struct Node));
    newNode->data = 10;
    newNode->previous = NULL;
    newNode->next = NULL;
    *head = newNode;
    p = *head;


    for (int i = 0; i < noOfElements - 1; i++)
    {
        newNode = malloc(sizeof(struct Node));
        newNode->data = i * 10 + 20;
        p->next = newNode;
        newNode->previous = p;
        p = p->next;
    }
    
    p->next = *head;
    (*head)->previous = p;
}


int CountNodes(struct Node *head)
{
    int count = 0;
    if(head == NULL)
    {
        return count;
    }

    struct Node *p = head;

    do
    {
        count++;
        p = p->next;
    } while (p != head);

    return count;
}


void Insert(struct Node **head, int pos, int value)
{
    struct Node *p = NULL, *t = NULL;
    int lengthOflist = CountNodes(*head);

    if(pos < 0 || pos > lengthOflist)
    {
        printf("invalid index!\n");
        return;
    }

    if(pos == 0)
    {
        t = malloc(sizeof(struct Node));
        t->data = value;
        t->next = NULL;
        t->previous = NULL;
        if(*head == NULL)
        {
            (*head) = t;
            t->next = *head;
            t->previous = *head;
        }
        else
        {
            t->next = *head;
            t->previous = (*head)->previous;
            (*head)->previous->next = t;
            (*head)->previous = t;
            (*head) = t;
        }
    }
    else if (pos == lengthOflist)
    {
        t = malloc(sizeof(struct Node));
        t->data = value;
        (*head)->previous->next = t;
        t->previous = (*head)->previous;
        (*head)->previous = t;
        t->next = *head;
    }
    else
    {
        p = *head;
        t = malloc(sizeof(struct Node));
        t->data = value;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        t->previous = p;
        p->next->previous = t;
        p->next = t;
    }
}


void Delete(struct Node **head, int pos)
{
    struct Node *p = NULL;
    int lengthOfList = CountNodes(*head);
    if(pos < 1 || pos > lengthOfList)
    {
        printf("invalid index\n");
        return;
    }

    if(pos == 1)
    {
        p = *head;
        if((*head)->next == *head)
        {
            free(*head);
            *head = NULL;
        }
        else
        {
            p->previous->next = p->next;
            p->next->previous = p->previous;
            *head = (*head)->next;
            free(p);
        }
    }
    else if(pos == lengthOfList)
    {
        p = (*head)->previous;
        p->previous->next = p->next;
        p->next->previous = p->previous;
        free(p);
    }
    else
    {
        p = *head;
        struct Node *temp = NULL;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        //temp = p->previous;
        //temp->next = p->next;
        //p->next->previous = temp;
        p->previous->next = p->next;
        p->next->previous = p->previous;
        free(p);  
    }
}


void Display(struct Node *head)
{
    struct Node *p = head;

    if (head == NULL)
    {
        printf("empty\n");
        return;
    }

    do
    {
        //printf("|- %X - %d - %X -| --> ",p->previous, p->data, p->next);
        //printf("%d ", p->data);
        printf("<---|- %d -|--->", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
    printf("|");
    for (int i = 0; i < 15 * CountNodes(head); i++)
        printf("_");
    printf("|\n\n");
}


void FreeList(struct Node **head)
{
    if(*head == NULL)
    {
        printf("empty no need to free!\n");
        return;
    }
    struct Node *p = *head;
    (*head) = (*head)->next;
    p->next = NULL;
    struct Node *temp = NULL;
    do
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    } while (*head != NULL);
}