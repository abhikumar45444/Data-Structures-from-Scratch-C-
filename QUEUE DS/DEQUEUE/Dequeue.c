#include<stdio.h>
#include<stdlib.h>

#define INTMIN -2147483647 - 1

struct DEqueue{
    int size;
    int front;
    int rear;
    int *Q;
};

void CreateDEqueue(struct DEqueue *q);
void InsertFront(struct DEqueue *q , int value);
int DeleteFront(struct DEqueue *q);
void InsertRear(struct DEqueue *q , int value);
int DeleteRear(struct DEqueue *q);
int isEmpty(struct DEqueue *q);
int isFull(struct DEqueue *q);
void Display(struct DEqueue *q);
void FreeDEqueue(struct DEqueue *q);

int main()
{
    struct DEqueue dequeue;
    CreateDEqueue(&dequeue);
    InsertFront(&dequeue, 7);
    // InsertFront(&dequeue, 3);
    // InsertFront(&dequeue, 1);
    // InsertFront(&dequeue, 5);
    //  InsertRear(&dequeue, 40);
    // InsertRear(&dequeue, 50);
    printf("%d\n", DeleteRear(&dequeue));
    printf("%d\n", DeleteFront(&dequeue));
    // DeleteFront(&dequeue);
    Display(&dequeue);
    FreeDEqueue(&dequeue);
    return 0;
}


void CreateDEqueue(struct DEqueue *q)
{
    q->size = 5;
    q->Q = malloc(q->size * sizeof(int));
    if(q->Q == NULL)
    {
        printf("malloc error!\n");
        exit(EXIT_FAILURE);
    }

    q->front = -1;
    q->rear = -1;
}



void InsertFront(struct DEqueue *q, int value)
{
    if(isFull(q))
    {
        printf("DEqueue is full cant perform InsertFront\n");
    }
    else if(q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->Q[q->front] = value;
    }
    else if(q->front == 0)
    {
        q->front = q->size - 1;
        q->Q[q->front] = value;
    }
    else
    {
        q->front--;
        q->Q[q->front] = value;
    }
}


void InsertRear(struct DEqueue *q , int value)
{
    if(isFull(q))
    {
        printf("DEqueue is full cant perform InsertRear\n");
    }
    else if(q->rear == -1 && q->front == -1)
    {
        q->rear = q->front = 0;
        q->Q[q->rear] = value;
    }
    else if(q->rear == q->size - 1)
    {
        q->rear = 0;
        q->Q[q->rear] = value;
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = value;
    }
}


int DeleteFront(struct DEqueue *q)
{
    int x = INTMIN;
    if(isEmpty(q))
    {
        printf("DEqueue is Empty cant perform DeleteFront: ");
    }
    else if(q->front == q->rear)
    {
        x = q->Q[q->front];
        q->rear = q->front = -1;
    }
    else if(q->front == q->size - 1)
    {
        x = q->Q[q->front];
        q->front = 0;
    }
    else
    {
        x = q->Q[q->front];
        q->front++;
    }

    return x;
}


int DeleteRear(struct DEqueue *q)
{
    int x = INTMIN;
    if(isEmpty(q))
    {
        printf("DEqueue is Empty cant perform DeleteFront: ");
    }
    else if(q->rear == q->front)
    {
        x = q->Q[q->rear];
        q->rear = q->front = -1;
    }
    else if(q->rear == 0)
    {
        x = q->Q[q->rear];
        q->rear = q->size - 1;
    }
    else
    {
        x = q->Q[q->rear];
        q->rear--;
    }

    return x;
}


int isEmpty(struct DEqueue *q)
{
    // if(q->front == q->rear || (q->front == -1 && q->rear == -1))
    if((q->front == -1 && q->rear == -1))
    {
        // q->front = q->rear = -1;
        return 1;
    }
    return 0;
}


int isFull(struct DEqueue *q)
{
    if(((q->front == 0) && (q->rear == (q->size - 1))) || (q->front == q->rear + 1))
    {
        return 1;
    }
    return 0;
}


void Display(struct DEqueue *q)
{
    if(isEmpty(q))
    {
        printf("nothing to display, queue is empty\n");
    }
    else
    {
        int i = q->front;
        while(i != q->rear)
        {
            printf("%d ", q->Q[i]);
            i = (i + 1) % q->size;
        }
        printf("%d", q->Q[i]);
        printf("\n");
    }
}


void FreeDEqueue(struct DEqueue *q)
{
    if(q->Q != NULL)
    {
        free(q->Q);
    }

    q->Q = NULL;
}