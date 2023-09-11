#include<stdio.h>
#include<stdlib.h>


// The approach that we are using will utitize (total size - 1) space 
// because the location at which front will be pointing we will not use it
// and the code of circular queue is changed according to it.
struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};



void CreateCircularQueue(struct CircularQueue *q);
void Enqueue(struct CircularQueue *q, int value);
int Dequeue(struct CircularQueue *q);
void Display(struct CircularQueue q);
void FreeQueue(struct CircularQueue *q);

int main()
{
    struct CircularQueue queue;
    CreateCircularQueue(&queue);
    Enqueue(&queue, 10);
    Enqueue(&queue, 20);
    // Enqueue(&queue, 30);
    // Enqueue(&queue, 40);
    // Enqueue(&queue, 50);
    // Enqueue(&queue, 60);
    // Enqueue(&queue, 70);
    Display(queue);
    printf("Deleted element is %d\n",Dequeue(&queue));
    Display(queue);
    FreeQueue(&queue);
    if(queue.Q == NULL)
    {
        printf("null\n");
    }
    else
    {
        printf("not null\n");
    }
    return 0;
}


void CreateCircularQueue(struct CircularQueue *q)
{
    // printf("Enter the size of Queue: ");
    // scanf("%d", &q->size);
    q->size = 7;
    q->front = q->rear = 0;
    q->Q = calloc(q->size, sizeof(int));
    if(q->Q == NULL)
    {
        printf("Error calloc!\n");
        exit(EXIT_FAILURE);
    }
}


void Enqueue(struct CircularQueue *q, int value)
{
    if((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full cant insert %d\n", value);
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = value;
    }
}


int Dequeue(struct CircularQueue *q)
{
    int value = -2147483647 - 1;
    if(q->front == q->rear)
    {
        printf("cant perform Deletion, Queue is Empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        value = q->Q[q->front];
    }
    return value;
}


void Display(struct CircularQueue q)
{
    if(q.front == q.rear)
    {
        printf("Cant display queue is empty\n");
        return;
    }

    int i = q.front;
    while(i != q.rear)
    {
        i = (i + 1) % q.size;
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

void FreeQueue(struct CircularQueue *q)
{
    free(q->Q);
    q->Q = NULL;
}