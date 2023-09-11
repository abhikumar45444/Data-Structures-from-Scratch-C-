#include<stdio.h>
#include<stdlib.h>

#define INTMIN -2147483647 - 1

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *Head;
};

struct Queue
{
    struct Stack stack1;
    struct Stack stack2;
};

typedef struct Node Node;
typedef struct Stack Stack;
typedef struct Queue Queue;


void CreateQueue(Queue *q);
Node* CreateNode(int value);
void Enqueue(Queue *q, int value);
int Dequeue(Queue *q);
void Display(Queue *q);
void FreeQueue(Queue *q);
void CheckQueueFree(Queue *queue);

int main()
{
    printf("%f\n", str);
    Queue queue;
    CreateQueue(&queue);
    Enqueue(&queue, 10);
    Enqueue(&queue, 20);
    Enqueue(&queue, 30);
    Enqueue(&queue, 40);
    // Display(&queue);
    // printf("dequeue: %d\n", Dequeue(&queue));
    // Enqueue(&queue, 30);
    // Enqueue(&queue, 40);
    // printf("dequeue: %d\n", Dequeue(&queue));
    Display(&queue);
    // printf("dequeue: %d\n", Dequeue(&queue));
    FreeQueue(&queue);
    CheckQueueFree(&queue);
    return 0;
}


void CreateQueue(Queue *q)
{
    q->stack1.Head = NULL;
    q->stack2.Head = NULL;
}


Node* CreateNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("malloc error cant create new node!\n");
    }
    else
    {
        newNode->data = value;
        newNode->next = NULL;
    }

    return newNode;
}



void Enqueue(Queue *q, int value)
{
    Node *p = CreateNode(value);
    if(p == NULL)
    {
        printf("overflow!\n");
        exit(EXIT_FAILURE);
    }

    if(q->stack1.Head == NULL)
    {
        q->stack1.Head = p;
    }
    else
    {
        p->next = q->stack1.Head;
        q->stack1.Head = p;
    }
}


int Dequeue(Queue *q)
{
    int x = INTMIN;

    if(q->stack1.Head == NULL && q->stack2.Head == NULL)
    {
        printf("Queue Empty cant perform Dequeue\n");
        return x;
    }
    
    Node *p = NULL, *newNode = NULL;
    if(q->stack2.Head == NULL)
    {
        while(q->stack1.Head != NULL)
        {
            p = q->stack1.Head;
            newNode = CreateNode(p->data);
            if(q->stack2.Head == NULL)
            {
                q->stack2.Head = newNode;
            }
            else
            {
                newNode->next = q->stack2.Head;
                q->stack2.Head = newNode;
            }
            q->stack1.Head = p->next;
            free(p);
            p = NULL;
        }

        p = q->stack2.Head;
        x = p->data;
        q->stack2.Head = p->next;
        free(p);
    }
    else
    {
        p = q->stack2.Head;
        x = p->data;
        q->stack2.Head = p->next;
        free(p);
    }

    return x;
}


void Display(Queue *q)
{
    if(q->stack1.Head == NULL && q->stack2.Head == NULL)
    {
        printf("Queue Empty Nothing to Display\n");
    }
    else
    {
        Node *p = NULL, *newNode = NULL;
        if(q->stack2.Head == NULL)
        {
            p = q->stack1.Head;
            while(p != NULL)
            {
                newNode = CreateNode(p->data);
                if(q->stack2.Head == NULL)
                {
                    q->stack2.Head = newNode;
                }
                else
                {
                    newNode->next = q->stack2.Head;
                    q->stack2.Head = newNode;
                }
                p = p->next;
            }

            while(q->stack2.Head != NULL)
            {
                p = q->stack2.Head;
                printf("%d ", p->data);
                q->stack2.Head = p->next;
                free(p);
            }
            printf("\n");
        }
        else
        {
            p = q->stack2.Head;
            while(p != NULL)
            {
                printf("%d ", p->data);
                p = p->next;
            }

            if(q->stack1.Head != NULL)
            {
                p = q->stack1.Head;
                while(p != NULL)
                {
                    printf("%d ", p->data);
                    p = p->next;
                }   
            }
            printf("\n");
        }
    }
}


void FreeQueue(Queue *q)
{
    Node *p = NULL;
    while(q->stack1.Head != NULL)
    {
        p = q->stack1.Head;
        q->stack1.Head = p->next;
        free(p);
    }

    p = NULL;

    while(q->stack2.Head != NULL)
    {
        p = q->stack2.Head;
        q->stack2.Head = p->next;
        free(p);
    }
}


void CheckQueueFree(Queue *queue)
{
    if(queue->stack1.Head == NULL)
    {
        printf("stack1 null\n");
    }
    else
    {
        printf("stack1 not null\n");
    }

    if(queue->stack2.Head == NULL)
    {
        printf("stack2 null\n");
    }
    else
    {
        printf("stack2 not null\n");
    }
}
