#include"Queue.h"

void CreateQueue(struct Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}


void Enqueue(struct Queue *q, struct TreeNode *node)
{
    struct Node *temp = CreateNode(node);

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



struct TreeNode* Dequeue(struct Queue *q)
{
    struct TreeNode *node = NULL;

    if(q->front == NULL)
    {
        printf("Queue is Empty can't Dequeue!\n");
    }
    else
    {
        struct Node *p = q->front;
        node = q->front->nodeptr;
        q->front = q->front->next;
        if(q->front == NULL)
            q->rear = NULL;    
        free(p);
    }

    return node;
}


struct Node* CreateNode(struct TreeNode *node)
{
    struct Node *p = NULL;
    p = malloc(sizeof(struct Node));
    if(p == NULL)
    {
        printf("Create Node Error!\n");
        exit(EXIT_FAILURE);
    }
    p->nodeptr = node;
    p->next = NULL;
    return p;
}

int IsQueueEmpty(struct Queue q)
{
    return q.rear == NULL && q.front == NULL;
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