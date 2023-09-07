#include<stdio.h>
#include<stdlib.h>

#define INTMIN -2147483647 - 1

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void CreateQueue(struct Queue *q);
struct Node *CreateNode(int data);
void Enqueue(struct Queue *q, int value);
int Dequeue(struct Queue *q);
void Display(struct Queue *q);
void FreeQueue(struct Queue *q);

int main()
{
    struct Queue queue;
    CreateQueue(&queue);
    // Enqueue(&queue, 10);
    Enqueue(&queue, 20);
    Enqueue(&queue, 30);
    Display(&queue);
    // Dequeue(&queue);
    // Display(&queue);
    FreeQueue(&queue);
    if(queue.front == NULL && queue.rear == NULL)
    {
        printf("null\n");
    }
    else
    {
        printf("not null\n");
    }
    return 0;
}

void CreateQueue(struct Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}


void Enqueue(struct Queue *q, int value)
{
    struct Node *temp = CreateNode(value);

    if(q->front == NULL && q->rear == NULL)
    {
        q->front = temp;
        q->rear = temp;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
}



int Dequeue(struct Queue *q)
{
    int x = INTMIN;

    if(q->front == NULL)
    {
        printf("Queue is Empty can't Dequeue!\n");
    }
    else
    {
        struct Node *p = q->front;
        x = q->front->data;
        q->front = q->front->next;
        if(q->front == NULL)
            q->rear = NULL;
        free(p);
    }

    return x;
}


struct Node *CreateNode(int data)
{
    struct Node *p = NULL;
    p = malloc(1 * sizeof(struct Node));
    if(p == NULL)
    {
        printf("Create Node Error!\n");
        exit(EXIT_FAILURE);
    }
    p->data = data;
    p->next = NULL;
    return p;
}


void Display(struct Queue *q)
{
    if(q->front == NULL)
    {
        printf("Queue is Empty! Nothing to Display!\n");
    }
    else
    {
        struct Node *p = q->front;
        while(p != q->rear->next)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}


void FreeQueue(struct Queue *q)
{
    if(q->front == NULL)
    {
        q->rear = NULL;
        return;
    }
    else
    {
        struct Node *p = NULL;
        while(q->front != q->rear)
        {
            p = q->front;
            q->front = q->front->next;
            free(p);
        }

        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
}