#include<stdio.h>
#include<stdlib.h>

#define PELEMENTARRAYSIZE 3
#define INTMIN -2147483647 - 1

struct PQueue
{
    int pQueueSize;
    int frontP1;
    int rearP1;
    int frontP2;
    int rearP2;
    int frontP3;
    int rearP3;
    int *P1;
    int *P2;
    int *P3;
};

struct PriorityElement
{
    int priority;
    char element;
};

typedef struct PQueue PQueue;
typedef struct PriorityElement PriorityElement;


void CreatePQueue(PQueue *pQueue);
void InsertElement(PQueue *pQueue, PriorityElement priorityElement);
int DeleteElement(PQueue *pQueue);
int IsEmpty(int front, int rear);
int IsFull(int pQueueSize, int front, int rear);
void Display(PQueue *pQueue);
void FreePQueue(PQueue *pQueue);

int main()
{
    PQueue pqueue;
    PriorityElement pelement[PELEMENTARRAYSIZE] = {{2, 'A'}, {2, 'B'}, {1, 'C'}};

    CreatePQueue(&pqueue);
    InsertElement(&pqueue, pelement[0]);
    InsertElement(&pqueue, pelement[1]);
    InsertElement(&pqueue, pelement[2]);
    InsertElement(&pqueue, pelement[1]);
    InsertElement(&pqueue, pelement[0]);
    Display(&pqueue);
    printf("deleted element is: %c\n", DeleteElement(&pqueue));
    Display(&pqueue);
    printf("deleted element is: %c\n", DeleteElement(&pqueue));
    Display(&pqueue);
    InsertElement(&pqueue, pelement[2]);
    Display(&pqueue);

    FreePQueue(&pqueue);

    return 0;
}


void CreatePQueue(PQueue *pQueue)
{
    pQueue->pQueueSize = 5;
    pQueue->P1 = calloc(pQueue->pQueueSize, sizeof(int));
    pQueue->P2 = calloc(pQueue->pQueueSize, sizeof(int));
    pQueue->P3 = calloc(pQueue->pQueueSize, sizeof(int));

    if(pQueue->P1 == NULL || pQueue->P1 == NULL || pQueue->P1 == NULL)
    {
        printf("calloc error!\n");
        exit(EXIT_FAILURE);
    }

    pQueue->frontP1 = -1;
    pQueue->rearP1 = -1;
    pQueue->frontP2 = -1;
    pQueue->rearP2 = -1;
    pQueue->frontP3 = -1;
    pQueue->rearP3 = -1;
}


void InsertElement(PQueue *pQueue, PriorityElement priorityElement)
{
    if(priorityElement.priority == 1)
    {
        if(IsFull(pQueue->pQueueSize, pQueue->frontP1, pQueue->rearP1))
        {
            printf("Priority Queue 1 is full cant perform Insertion\n");
        }
        else if(pQueue->frontP1 == -1 && pQueue->rearP1 == -1)
        {
            pQueue->frontP1 = pQueue->rearP1 = 0;
            pQueue->P1[pQueue->rearP1] = priorityElement.element;
        }
        else
        {
            pQueue->rearP1 = (pQueue->rearP1 + 1) % pQueue->pQueueSize;
            pQueue->P1[pQueue->rearP1] = priorityElement.element;
        }
    }
    else if(priorityElement.priority == 2)
    {
        if(IsFull(pQueue->pQueueSize, pQueue->frontP2, pQueue->rearP2))
        {
            printf("Priority Queue 1 is full cant perform Insertion\n");
        }
        else if(pQueue->frontP2 == -1 && pQueue->rearP2 == -1)
        {
            pQueue->frontP2 = pQueue->rearP2 = 0;
            pQueue->P2[pQueue->rearP2] = priorityElement.element;
        }
        else
        {
            pQueue->rearP2 = (pQueue->rearP2 + 1) % pQueue->pQueueSize;
            pQueue->P2[pQueue->rearP2] = priorityElement.element;
        }
    }
    else if(priorityElement.priority == 3)
    {
        if(IsFull(pQueue->pQueueSize, pQueue->frontP3, pQueue->rearP3))
        {
            printf("Priority Queue 1 is full cant perform Insertion\n");
        }
        else if(pQueue->frontP3 == -1 && pQueue->rearP3 == -1)
        {
            pQueue->frontP3 = pQueue->rearP3 = 0;
            pQueue->P3[pQueue->rearP3] = priorityElement.element;
        }
        else
        {
            pQueue->rearP3 = (pQueue->rearP3 + 1) % pQueue->pQueueSize;
            pQueue->P3[pQueue->rearP3] = priorityElement.element;
        }
    }
}


int DeleteElement(PQueue *pQueue)
{
    if(!IsEmpty(pQueue->frontP1, pQueue->rearP1))
    {
        int x = INTMIN;
        if(pQueue->frontP1 == pQueue->rearP1)
        {
            x = pQueue->P1[pQueue->frontP1];
            pQueue->frontP1 = pQueue->rearP1 = -1;

        }
        else
        {
            x = pQueue->P1[pQueue->frontP1];
            pQueue->frontP1 = (pQueue->frontP1 + 1) % pQueue->pQueueSize;
        }
        return x;
    }
    else if(!IsEmpty(pQueue->frontP2, pQueue->rearP2))
    {
         int x = INTMIN;
        if(pQueue->frontP2 == pQueue->rearP2)
        {
            x = pQueue->P2[pQueue->frontP2];
            pQueue->frontP2 = pQueue->rearP2 = -1;

        }
        else
        {
            x = pQueue->P2[pQueue->frontP2];
            pQueue->frontP2 = (pQueue->frontP2 + 1) % pQueue->pQueueSize;
        }
        return x;
    }
    else if(!IsEmpty(pQueue->frontP3, pQueue->rearP3))
    {
        int x = INTMIN;
        if(pQueue->frontP3 == pQueue->rearP3)
        {
            x = pQueue->P3[pQueue->frontP3];
            pQueue->frontP3 = pQueue->rearP3 = -1;

        }
        else
        {
            x = pQueue->P3[pQueue->frontP3];
            pQueue->frontP3 = (pQueue->frontP3 + 1) % pQueue->pQueueSize;
        }
        return x;
    }
}


int IsEmpty(int front, int rear)
{
    if((front == -1 && rear == -1))
    {
        return 1;
    }

    return 0;
}


int IsFull(int pQueueSize, int front, int rear)
{
    if((rear + 1) % pQueueSize == front)
    {
        return 1;
    }

    return 0;
}


void Display(PQueue *pQueue)
{
    if(IsEmpty(pQueue->frontP1, pQueue->rearP1))
    {
        printf("P1:\n");
    }
    else
    {
        int i = pQueue->frontP1;
        printf("P1: ");
        while(i != pQueue->rearP1)
        {
            printf("%c ", pQueue->P1[i]);
            i = (i + 1) % pQueue->pQueueSize;
        }
        printf("%c\n", pQueue->P1[i]);
    }
    
    if(IsEmpty(pQueue->frontP2, pQueue->rearP2))
    {
        printf("P2:\n");
    }
    else
    {
        int i = pQueue->frontP2;
        printf("P2: ");
        while(i != pQueue->rearP2)
        {
            printf("%c ", pQueue->P2[i]);
            i = (i + 1) % pQueue->pQueueSize;
        }
        printf("%c\n", pQueue->P2[i]);
    }

    if(IsEmpty(pQueue->frontP3, pQueue->rearP3))
    {
        printf("p3:\n");
    }
    else
    {
        int i = pQueue->frontP3;
        printf("P3: ");
        while(i != pQueue->rearP3)
        {
            printf("%c ", pQueue->P3[i]);
            i = (i + 1) % pQueue->pQueueSize;
        }
        printf("%c\n", pQueue->P3[i]);
    }
    
}


void FreePQueue(PQueue *pQueue)
{
    free(pQueue->P1);
    free(pQueue->P2);
    free(pQueue->P3);
    pQueue->P1 = NULL;
    pQueue->P2 = NULL;
    pQueue->P3 = NULL;
}