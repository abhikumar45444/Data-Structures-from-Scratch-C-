#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *GlobalHead = NULL;

void CircularLinkedList(struct Node **head);
void Insert(struct Node **head, int pos, int x);
int CountNode(struct Node *head);
void Delete(struct Node **head, int pos);
void Display(struct Node *head);
void RecursiveDisplay(struct Node *head);
void FreeList(struct Node **head);
void Sum(struct Node *head);
void MaxElement(struct Node *head);
void LinearSearch(struct Node *head, int key);

int main()
{
    struct Node *head = NULL;
    CircularLinkedList(&head);
    GlobalHead = head;
    Display(head);
    RecursiveDisplay(head);

    //Insert(&head, 3, 70);
    //Insert(&head, 0, 80);
    //Insert(&head, 0, 90);
    //Insert(&head, 7, 90);
   // Insert(&head, 7, 90);
   // GlobalHead = head;
    Display(head);
    printf("%d\n", CountNode(head));
    //GlobalHead = head;
    //Delete(&head, 2);
    //Delete(&head, 1);
    Delete(&head, 1);
    //GlobalHead = head;
    Display(head);
    Sum(head);
    MaxElement(head);
    LinearSearch(head, 40);
    //GlobalHead = head;
    FreeList(&head);
    //Display(head);
    if(head != NULL)
        printf("head not null\n");
    else
        printf("head is Null\n");

    return 0;
}

void CircularLinkedList(struct Node **head)
{
    int totalElements = 5; // number of elements in linkedlist
    struct Node *p = NULL;
    
    if(totalElements == 0)
    {
        return;
    }  

    struct Node *newNode = NULL;
    newNode = malloc(sizeof(struct Node));
    newNode->data = 10;
    newNode->next = NULL;
    p = newNode;
    *head = p;

    for (int i = 0; i < totalElements - 1; i++)
    {
        newNode = malloc(sizeof(struct Node));
        newNode->data = i * 10 + 20;
        newNode->next = NULL;
        p->next = newNode;
        p = p->next;
    }

   p->next = *head;
}

// if you evaluate this Expression -> CountNode(*head) in watch window and doesn't give nse(no side effect) parameter can go into trouble cause it changes behaviour
int CountNode(struct Node *head)
{
    struct Node *p = head;
    int count = 0;
    
    if(p == NULL)
    {
         return count;
    }
    
    do
    {
        count++;
        p = p->next;
    } while (p != head);

    return count;
}


void Insert(struct Node **head, int pos, int x)
{
    struct Node *p = NULL, *temp = NULL;

    if(pos < 0 || pos > CountNode(*head))
    {
        printf("invalid position!\n");
        return;
    }

    if(pos == 0)
    {
        temp = malloc(sizeof(struct Node));
        temp->data = x;
        if(*head == NULL)
        {
            *head = temp;
            (*head)->next = *head;
        }
        else
        {
            p = *head;
            temp->next = *head;

            while(p->next != *head)
            {
                p = p->next;
            }

            p->next = temp;
            *head = temp;
        }
    }
    else
    {
        temp = malloc(sizeof(struct Node));
        temp->data = x;
        p = *head;

        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;
    }
}


void Delete(struct Node **head, int pos)
{
    int x = 0;
    struct Node *p = NULL, *q = NULL;

    if(pos < 1 || pos > CountNode(*head))
    {
        printf("invalid pos\n");
        return;
    }

    if(*head == NULL)
    {
        printf("List is empty! cannot perform deletion!\n");
        return;
    }

    if(pos == 1)
    {
        p = *head;
        while(p->next != *head)
        {
            p = p->next;
        }

        x = (*head)->data;

        if(p == *head)
        {
            free(*head);
            *head = NULL;
        }
        else
        {
            p->next = (*head)->next;
            free(*head);
            *head = p->next;
        }
    }
    else
    {
        p = *head;
        
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        x = q->data;
        p->next = q->next;
        free(q);
    }

    printf("deleted node value is %d\n", x);
}


void Sum(struct Node *head)
{
    int sum = 0;
    struct Node *current = head;
    if(head == NULL)
    {
        printf("smu is -1\n");
        return;
    }

    do
    {
        sum += current->data;
        current = current->next;
    } while (current != head);

    printf("sum is %d\n", sum);
}


void MaxElement(struct Node *head)
{
    int max = INT_MIN;
    struct Node *current = head;

    if(head == NULL)
    {
        printf("max -1\n");
        return;
    }

    do
    {
        if(max < current->data)
        {
            max = current->data;
            current = current->next;
        }
    } while (current != head);

    printf("max is %d\n", max);
}


void LinearSearch(struct Node *head, int key)
{
    struct Node *current = head;
    if(head == NULL)
    {
        printf("-1\n");
        return;
    }

    int index = 0;
    do
    {
        if(current->data == key)
        {
            printf("key is found at index %d\n", index);
            return;
        }
        index++;
        current = current->next;
    } while (current != head);

    printf("key not found!\n");
}


void Display(struct Node *head)
{   
    if(head == NULL) 
    {
        printf("Empty\n");
        return;
    }
        

    struct Node *p = head;
    do   
    {
        printf("%d ", head->data);
        head = head->next;
    } while (p != head);

    printf("\n");
}


void RecursiveDisplay(struct Node *head)
{
    if(head == NULL)
        return;

    static int flag = 0;
    if(head != GlobalHead || flag == 0)
    {
        flag = 1;
        printf("%d ", head->data);
        RecursiveDisplay(head->next);
    }
    else
    {
        printf("\n");
    }
    flag = 0;
}


void FreeList(struct Node **head)
{
    if(*head == NULL)
    {
        return;
    }

        struct Node *p = *head;

        *head = (*head)->next;        
        p->next = NULL;

        struct Node *tmp = NULL;

        do
        {
           tmp = *head;
           *head = (*head)->next;
           free(tmp);
        }while (*head != NULL); // it will first break the link to of first node and then second and the third and so on.....

        tmp = NULL;
}