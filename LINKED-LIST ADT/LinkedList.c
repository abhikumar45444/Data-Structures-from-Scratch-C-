#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // for MIN and MAX function (it contains defintion for minimum and maximum values for datatypes)

/*

struct Node              //use this struct if you want to access head/first pointer of linked list from everywhere
{                        //and dont want to use double pointers and all
    int data;
    struct Node *next;
}*first = NULL;          //declaring head/first of linked list as global pointer

*/

struct Node        //Structure for Node of LinkedList. it also called self refrential structure
{
    int data;
    struct Node *next; //struct pointer of type struct Node that will point to next node of the list
};

//functions
struct Node* LinkedList(struct Node *head);
void Display(struct Node *head);
void RecursiveDisplay(struct Node *head);
void freeList(struct Node **head); //using  double ** because we want to free our main function head so it contains NULL after free mallocs
int CountNodes(struct Node *head);
int RecursiveCountNodes(struct Node *head);
int Sum(struct Node *head);
int RecursiveSum(struct Node *head);
int MaxElement(struct Node *head);
int RecursiveMaxElement(struct Node *head);
struct Node* LinearSearch(struct Node *head, int key);  //Binary Search will not work b/c we cant directly go to middle of L.L. 
struct Node* RecursiveLinearSearch(struct Node *head, int key);
struct Node* ImprovedLinearSearch(struct Node **head, int key);
void InsertNode(struct Node **head);
void InsertNodeInSortedList(struct Node **head, int value);
int DeleteAtPos(struct Node **head);
void IsSorted(struct Node *head);
void RemoveDuplicatesInSorted(struct Node *head);
void ReverseLListUsingReverseElementsMtd(struct Node *head);
void ReverseLListUsingSlidingPointersMtd(struct Node **head);
void ReverseUsingRecursion(struct Node *p, struct Node **head);
void RecursiveReverseBreakInto2(struct Node **head);
void Concat(struct Node *head, struct Node *head1);
void Merge(struct Node **head, struct Node **head1);
void Isloop(struct Node *head);
void MiddleNodeM1(struct Node *head); //first scan the list to count nodes and the reach floor(NodeCount) for the mid Node
void MiddleNodeM2(struct Node *head); // in this method we will use tailing pointers approach means one pointer (q) will move 2 steps 
                                      // and other (p) 1 step so by the time, q will be at the end then p will be pointing on mid node.

int main()
{
    struct Node *head = NULL, *head1 = NULL;  //pointer of type struct  
     head = LinkedList(head);
     head1 = LinkedList(head1);
    /* 
    printf("count: %d\n", CountNodes(head));
    printf("Rcount: %d\n", RecursiveCountNodes(head));
    printf("sum: %d\n", Sum(head));
    printf("Rsum: %d\n", RecursiveSum(head));
    printf("Max: %d\n", MaxElement(head));
    printf("RecMax: %d\n", RecursiveMaxElement(head));
    //printf("found at address of node: %X\n", LinearSearch(head, 40));
    //printf("found at address of node: %X\n", RecursiveLinearSearch(head, 40));
    //ImprovedLinearSearch(&head, 40);
    //printf("found at address of node: %X\n", ImprovedLinearSearch(&head, 40));
    Display(head);
    RecursiveDisplay(head);
    //printf("found at address of node: %X\n", ImprovedLinearSearch(&head, 40));
    //Display(head);
    //printf("found at address of node: %X\n", ImprovedLinearSearch(&head, 20));
    //Display(head);
    //printf("found at address of node: %X\n", ImprovedLinearSearch(&head, 20));
    //Display(head);
    
    //InsertNode(&head);
    */

    InsertNodeInSortedList(&head, 2);
    //InsertNodeInSortedList(&head, 30);
    InsertNodeInSortedList(&head, 40);
    // InsertNode(&head);
    // InsertNode(&head);
     InsertNodeInSortedList(&head, 100);
    InsertNodeInSortedList(&head, 75);
     InsertNodeInSortedList(&head, 60);
    // InsertNodeInSortedList(&head, 60);
    // InsertNodeInSortedList(&head, 60);
    
    InsertNodeInSortedList(&head1, 1);
    //InsertNodeInSortedList(&head1, 20);
    InsertNodeInSortedList(&head1, 50);
    //InsertNode(&head);
    
    //RemoveDuplicatesInSorted(head);
    // InsertNode(&head);
    //DeleteAtPos(&head);
    //IsSorted(head);
    
    Display(head);
    Display(head1);

    //ReverseLListUsingReverseElementsMtd(head);
    //ReverseLListUsingSlidingPointersMtd(&head);
    //ReverseUsingRecursion(NULL, &head);   //passing first argument as NULL because p will be initially null

    //InsertNode(&head);
    //InsertNode(&head);
    //Concat(head, head1);

    Merge(&head, &head1);

    InsertNodeInSortedList(&head, 90);
    InsertNodeInSortedList(&head, 90);

    // struct Node *temp1 = head, *temp = head;
    // temp = temp->next->next->next;
    
    // while(temp1->next != NULL)
    // {
    //     temp1 = temp1->next;
    // }
    // temp1->next = temp;

    // Isloop(head);
    //Display(head);
    //RecursiveReverseBreakInto2(&head);

    MiddleNodeM1(head);
    MiddleNodeM2(head);
    Display(head);
    freeList(&head);
    if(head != NULL)
        printf("head not null\n");
    else
        printf("head is Null\n");
    return 0;
}

                                           
struct Node* LinkedList(struct Node *head)   //here i can also take (struct Node **head) so that we can use pass by reference for main head
{                                           //if i dont want to return Node pointer and directly reflect changes on main head 
    int numElements = 0;
    struct Node *current = NULL;
    printf("Enter Number of elements in List: ");
    scanf("%d", &numElements);
    head = malloc(sizeof(struct Node));
    printf("Enter the %d element:\n", 1);
    scanf("%d", &head->data);
    head->data = 10;
    head->next = NULL;

    current = head;

    for (int i = 1; i < numElements; i++)
    {
        current->next = malloc(sizeof(struct Node));
        current = current->next;
        printf("Enter the %d element:\n", i + 1);
        scanf("%d", &current->data);
        current->data = i * 10 + head->data;
        current->next = NULL;
    }
    return head;
}


int CountNodes(struct Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

int RecursiveCountNodes(struct Node *head)
{
    if(head == NULL)
        return 0;
    else
        return RecursiveCountNodes(head->next) + 1;
}


int Sum(struct Node *head)
{
    int sum = 0;
    while(head != NULL)
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}


int RecursiveSum(struct Node *head)
{
    if(head == NULL)
        return 0;
    else
    {
        return head->data + RecursiveSum(head->next);
    }
}


int MaxElement(struct Node *head)
{
    int max = INT_MIN;
    while(head != NULL)
    {
        if(head->data > max)  
        {
             max = head->data;
        }
        head = head->next;
    }
    return max;
}


int RecursiveMaxElement(struct Node *head)
{
    int max = 0;
    if(head == NULL)
    {
        return INT_MIN;
    }

    max = RecursiveMaxElement(head->next);
    if(max > head->data)
    {
        return max;
    }
    else
    {
        return head->data;
    }
}


struct Node* LinearSearch(struct Node *head, int key)
{
    while(head != NULL)
    {
        if(head->data == key)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

struct Node* RecursiveLinearSearch(struct Node *head, int key)
{
    if(head == NULL)
        return NULL;
    
    if(head->data == key)
        return head;

    return RecursiveLinearSearch(head->next, key);
}


struct Node* ImprovedLinearSearch(struct Node **head, int key)
{
    struct Node *tailPointer = NULL, *p = *head;
    if (key == p->data)
    {
        return *head;
    }
    
    while(p != NULL)
    {
        if(key == p->data)
        {
            tailPointer->next = p->next;
            p->next = *head;
            *head = p;
            return *head;
        }
        tailPointer = p;
        p = p->next;
    }
    return NULL;
}



void InsertNode(struct Node **head)
{
    struct Node *newNode = NULL;
    struct Node *p = *head;
    short int pos = 0, lenOfLinkedlist = 0;
    lenOfLinkedlist = CountNodes(*head);
    //printf("enter the positon at which the node to be inserted: ");
    //scanf("%d", &pos);
    pos = 0;

    if(pos < 0 || pos > lenOfLinkedlist){  //if position is not valid exit the function
        printf("Position: %d is not valid\n", pos);
        return;
    }
    //printf("%d\n", lenOfLinkedlist);
    
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    //printf("Enter the data: ");
    //scanf("%d", &newNode->data);
    newNode->data = 10;
    newNode->next = NULL;

    if(pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
}


void InsertNodeInSortedList(struct Node **head, int value)
{
    struct Node *q = NULL, *p = *head, *t = NULL;

    t = malloc(sizeof(struct Node));
    t->data = value;
    //q = *head;
    while(p && p->data < value)
    {
        q = p;
        p = p->next;
    }

    if(q == NULL)
    {
        t->next = *head;
        *head = t;
    }
    else
    {
        t->next = q->next;
        q->next = t;
    }
}


int  DeleteAtPos(struct Node **head)
{
    struct Node *p = *head, *q = NULL;
    int pos = 7, Deletedvalue = 0;
    
    if(pos < 1 || pos > CountNodes(p))
    {
        printf("Invalid Position\n");
        return -1;
    }

    if(pos == 1)
    {
        *head = p->next;
        Deletedvalue = p->data;
        free(p);
        return Deletedvalue;
    }
    else
    {
        for (int i = 0; i < pos - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            Deletedvalue = p->data;
            free(p);
            return Deletedvalue;    
        }     
    }
    printf("Problem occured P==Null\n");
}


void IsSorted(struct Node *head)
{
    //struct Node *q = head->next;

    int x = INT_MIN;

    while(head != NULL)
    {
        if(x > head->data)
        {
            printf("Not Sorted!!\n");
            return;
        }
        //q = q->next;
        x = head->data;
        head = head->next;
    }

    printf("Sorted!!\n");
}


void RemoveDuplicatesInSorted(struct Node *head)
{
    struct Node *p = head, *q = head->next;
    
    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}


void ReverseLListUsingReverseElementsMtd(struct Node *head)
{
    struct Node *p = head;                              // to traverse list
    int linkedListLength = CountNodes(head);           // count nodes to get length of LL
    int *A = NULL;                                    // dynamic array of size equal to list length
    A = malloc(linkedListLength * sizeof(int)); 
    int i = 0;                                      // pointer for array tracker 
 
    while(p != NULL)                              // to copy data from linked list to array
    {
        A[i++] = p->data;
        p = p->next;
    }

    p = head; // point p back to head
    i--;  // to make i point to last element

    while(p != NULL) // copy elements in reverse into linkedlist
    {
        p->data = A[i--];
        p = p->next;
    }

    free(A);
}


void ReverseLListUsingSlidingPointersMtd(struct Node **head)
{
    struct Node *p = *head, *q = NULL, *r = NULL;
    
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    *head = q;
}


void ReverseUsingRecursion(struct Node *q, struct Node **head)
{
    struct Node *p = *head;
    if(p)
    {
        *head = (*head)->next;
        ReverseUsingRecursion(p, head);
        p->next = q;
    }
    else
    {
        *head = q;
    }

}

//this method will use breaking list into 2 pieces first and rest then recursively reverse rest list and fix head at rest  
void RecursiveReverseBreakInto2(struct Node **head)
{
    struct Node *first, *rest;

    if(*head == NULL)
    {
        return;
    }

    first = *head;
    rest = (*head)->next;
    
    if(rest == NULL)
    {
        return;
    }

    RecursiveReverseBreakInto2(&rest);

    first->next->next = first;
    first->next = NULL;
    *head = rest;
}


void Concat(struct Node *head, struct Node *head1)
{
    struct Node *p = head;

    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = head1;
}


void Merge(struct Node **head, struct Node **head1)
{
    struct Node *third = NULL, *last = NULL;  // third will keep track the initial place of head pointer
                                             // last pointer is used for to join the next node that needs to be merged
    
    if((*head)->data < (*head1)->data)     // initially check which list's first node is smaller      
    {                                     // then point pointer third and last to that node
        third = last = *head;
        *head = (*head)->next;
        last->next = NULL;
    }
    else
    {
        third = last = *head1;
        *head1 = (*head1)->next;
        last->next = NULL;
    }


    while(*head != NULL && *head1 != NULL)  // now we are find and merging the node in sorted order ubtil one list is completed
    {
        if((*head)->data < (*head1)->data)   // check whcih node is smaller then point last's next to that node 
        {                                    // then increse the last pointer to current pointer and increase the current pointer
            last->next = *head;              // then make last's next null
            last = last->next;
            *head = (*head)->next;
            last->next = NULL;
        }
        else
        {
            last->next = *head1;
            last = last->next;
            *head1 = (*head1)->next;
            last->next = NULL;
        }
    }

    if(*head)  // now we have to link the list is not traversed fully and then assign third pointer to one of head
    {
        last->next = *head;
        *head = third;
    }
    else
    {
        last->next = *head1;
        *head = third;
    }
}



void Isloop(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is Empty!!\n");
        return;
    }
    else
    {
        struct Node *p, *q;
        p = q = head;

        do
        {
            p = p->next;
            q = q->next;
            q = q != NULL ? q->next : NULL;
        } while (p && q && (p != q));

        if(p == q)
        {
            printf("loop!!\n");
        }
        else
        {
            printf("no loop!!\n");
        }
        
    }
}


void MiddleNodeM1(struct Node *head)
{
    struct Node *p = head;
    int listLength = CountNodes(head);
    for (int i = 0; i < listLength/2; i++)
    {
        p = p->next;
    }
    printf("%d\n", p->data);
}


void MiddleNodeM2(struct Node *head)
{
    struct Node *p, *q;
    p=q=head;

    while(q != NULL)
    {
        q = q->next;
        if(q) q = q->next;
        if(q) p = p->next;
    }
    printf("%d\n", p->data);
}



void Display(struct Node *head)
{
    //struct Node *Current = head;
    while (head != NULL)
    {
        //printf("data: %d | Next: %X | adress of current: %X --->", head->data, head->next, head);
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void RecursiveDisplay(struct Node *head)
{
     if(head != NULL)
     {
         printf("%d ", head->data);
         RecursiveDisplay(head->next);
     }
     printf("\n");
}


void freeList(struct Node** head) // we are using pass by reference here because we also want to set our head as null
{                                 //so our list shows empty if we dont do that head will contain some value and it will break our code (eg: seg fault)
   struct Node* tmp = NULL;
   while (*head != NULL) // it will first break the link to of first node and then second and the third and so on.....
    {
       tmp = *head;
       *head = (*head)->next;
       free(tmp);
    }
    tmp = NULL;
}