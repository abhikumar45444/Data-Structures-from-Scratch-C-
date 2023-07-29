struct Term        //Structure for Term of LinkedList. it also called self refrential structure
{
    int coefficient;
    int exponent;
    struct Term *next; //struct pointer of type struct Term that will point to next Term of the list
};

//functions
void LinkedList(struct Term **head);
void Display(struct Term *head);
void freeList(struct Term **head); //using  double ** because we want to free our main function head so it contains NULL after free mallocs
int CountTerms(struct Term *head);
void InsertAtLast(struct Term **head,int coeff, int expo);
int DeleteAtPos(struct Term **head);
