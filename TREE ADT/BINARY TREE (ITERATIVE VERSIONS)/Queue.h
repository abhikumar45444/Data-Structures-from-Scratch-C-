#ifndef Queue_H_
#define Queue_H_

#include"StackUsingLinkedList.h"

#define INTMIN -2147483647 - 1

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void CreateQueue(struct Queue *q);
struct Node* CreateNode(struct TreeNode *node);
void Enqueue(struct Queue *q, struct TreeNode *node);
struct TreeNode* Dequeue(struct Queue *q);
int IsQueueEmpty(struct Queue q);
void FreeQueue(struct Queue *q);

#endif /*Queue_H_*/