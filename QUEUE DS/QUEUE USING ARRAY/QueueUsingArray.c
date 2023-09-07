#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};


void CreateQueue(struct Queue *q);
void Enqueue(struct Queue *q, int value);
int Dequeue(struct Queue *q);
void Display(struct Queue q);
void FreeQueue(struct Queue *q);

int main()
{
    struct Queue queue;
    CreateQueue(&queue);
    Enqueue(&queue, 12);
    Enqueue(&queue, 6);
    Enqueue(&queue, 9);
    Enqueue(&queue, 14);
    Enqueue(&queue, 8);
    Display(queue);
    printf("deleted element is: %d\n", Dequeue(&queue));
    Display(queue);
    FreeQueue(&queue);
    return 0;
}


void CreateQueue(struct Queue *q)
{
    printf("Enter the Size of Queue: ");
    scanf("%d", &q->size);

    q->Q = calloc(q->size, sizeof(int));
    if(q->Q == NULL)
    {
        printf("Calloc Failed\n");
        exit(EXIT_FAILURE);
    }

    q->front = q->rear = -1;
}


void Enqueue(struct Queue *q, int value)
{
    if(q->rear == q->size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = value;
    }
}


int Dequeue(struct Queue *q)
{
    int value = -1;
    if(q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front++;
        value = q->Q[q->front];
    }

    return value;
}



void Display(struct Queue q)
{
    if(q.front == q.rear)
    {
        printf("queue is empty nothing to display\n");
    }
    else
    {
        while(q.front != q.rear)
        {
            q.front++;
            printf("%d ", q.Q[q.front]);
        }
    }
    printf("\n");
}


void FreeQueue(struct Queue *q)
{
    free(q->Q);
    q->Q = NULL;
}