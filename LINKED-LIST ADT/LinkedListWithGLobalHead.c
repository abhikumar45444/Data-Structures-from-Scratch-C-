#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node
{
    int data;
    struct Node *Next;
}*head = NULL, *head1 = NULL, *last = NULL;    // here we are using Global head and last to keep track of linked list 

void insertNode(int value);
void insertNodeAtposition(struct Node *p, int pos, int value);
void InsertAtLast(struct Node *p, int value);
int count(struct Node *p);
void SortedInsert(struct Node *p, int value);
void IsSorted();
void display(struct Node *p);
void freeList();
void ReverseLListUsingReversingElemeentMtd(struct Node *p);
void ReverseLListUsingReversingLinksMtd(struct Node *p);
void ReverseLListUsingRecursion(struct Node *q, struct Node *p);
void Merge(struct Node *p, struct Node *q);

int main()
{
    // insertNodeAtposition(head, 0, 1);
    insertNode(10);
    insertNode(20);
    insertNode(30);
    insertNode(30);
    insertNode(40);
    // insertNodeAtposition(head, 4, 25);
    // insertNodeAtposition(head, 0, 35);
    // insertNode(60);
    // SortedInsert(head,5);
    // SortedInsert(head,5);
    // SortedInsert(head,2);
    // InsertAtLast(head, 60);
    // InsertAtLast(head, 60);
    
     SortedInsert(head,1);
    SortedInsert(head,3);
    SortedInsert(head,5);
    InsertAtLast(head, 7);
    InsertAtLast(head, 9);

    // SortedInsert(head1,2);
    // SortedInsert(head1,4);
    // SortedInsert(head1,6);
    // SortedInsert(head1,8);
    // SortedInsert(head1,10);

    
    IsSorted();

    display(head);

    //ReverseLListUsingReversingElemeentMtd(head);
    //ReverseLListUsingReversingLinksMtd(head);
    ReverseLListUsingRecursion(NULL, head);
    
    //Merge(head, head1);


    display(head);
    freeList();
    if(head != NULL)
    {
        printf("head not Null\n");
    }
    else
    {
        printf("head is Null\n");
    }
    return 0;
}

void insertNode(int value)
{
    struct Node *t = NULL;
    t = malloc(sizeof(struct Node));
    t->data = value;
    t->Next = NULL;

    if(head == NULL)
    {
        head = t;
        last = head;
    }
    else
    {
        last->Next = t;
        last = t;
    }
}

void insertNodeAtposition(struct Node *p, int pos, int value)
{
    int lengthofLinkedlist = 0;
    lengthofLinkedlist = count(p);  
    if(pos < 0 || pos > lengthofLinkedlist)  
        return;

    struct Node *t = NULL;
    t = malloc(sizeof(struct Node));
    t->data = value;
    t->Next = NULL;

    if(pos == 0 && lengthofLinkedlist == 0) // meeans inserting in empty list
    {
        insertNode(value);
    }
    else if(pos == 0 && lengthofLinkedlist > 0)
    {
        t->Next = head;
        head = t;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->Next;
        }
        t->Next = p->Next;
        p->Next = t;
    }
}

int count(struct Node *p)
{
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->Next;
    }
    return count;
}


void SortedInsert(struct Node *p, int value)
{
    struct Node *t = NULL, *q = NULL;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;
    t->Next = NULL;
    while(p && p->data < value)
    {
        q = p;
        p = p->Next;
    }
    
    if(q == NULL)
    {
        t->Next = p;
        head = t;
    }
    else
    {
        t->Next = q->Next;
        q->Next = t;
    }
}


void InsertAtLast(struct Node *p, int value)
{
    struct Node *temp = NULL;
    temp = malloc(sizeof(struct Node));
    temp->data = value;
    temp->Next = NULL;

    while(p->Next != NULL)  //we are using p->next as condtion because we want to stop on the node 
    {                       //so we dont need to use *q pointer as tail pointer to keep track
        p = p->Next;
    }
    p->Next = temp;

}

void IsSorted()
{
    struct Node *p = head;
    int x = INT_MIN;
    while(p != NULL)
    {
        if(x > p->data)
        {
            printf("Not Sorted!!\n");
            return;
        }
        x = p->data;
        p = p->Next;
    }
    printf("Sorted!!\n");
}

void ReverseLListUsingReversingElemeentMtd(struct Node *p)
{
    struct Node *q = p;
    
    int *A = NULL;
    A = malloc(sizeof(int) * count(p));
    int i = 0;
    while(q != NULL)
    {
        A[i++] = q->data;
        q = q->Next;
    }

    q = p;
    i--;


    while(q != NULL)
    {
        q->data = A[i--];
        q = q->Next;
    }

    free(A);
}


void ReverseLListUsingReversingLinksMtd(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->Next;
        q->Next = r;
    }
    head = q;
}


void ReverseLListUsingRecursion(struct Node *q, struct Node *p)
{
    if(p)
    {
        ReverseLListUsingRecursion(p, p->Next);
        p->Next = q;
    }
    else
    {
        head = q;
    }
}


void Merge(struct Node *p, struct Node *q)
{
    struct Node *temp, *third;

    if(p->data < q->data)
    {
        temp = third = p;
        p = p->Next;
        temp->Next = NULL;
    }
    else
    {
        temp = head1 = q;
        q = q->Next;
        temp->Next = NULL;
    }

    while(p != NULL && q != NULL)
    {
        if(p->data < q->data)
        {
            temp->Next = p;
            p = p->Next;
            temp = temp->Next;
            temp->Next = NULL;
        }
        else
        {
            temp->Next = q;
            q = q->Next;
            temp = temp->Next;
            temp->Next = NULL;
        }
    }

    if(p != NULL)
    {
        temp->Next = p;
    }
    else
    {
        temp->Next = q;
    }
}


void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->Next;
    }

    printf("\n");
}

void freeList()
{
    struct Node *temp = NULL;
    while(head != NULL)
    {
        temp = head;
        head = head->Next;
        free(temp);
    }
}