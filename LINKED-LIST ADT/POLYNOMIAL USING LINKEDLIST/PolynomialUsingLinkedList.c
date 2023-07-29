#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"LinkedList.h"

struct Polynomial
{
    struct Term **ptrToPolynomial;
};

void CreatePolynomial(struct Polynomial *polynomial);
int EvaluatePolynomial(struct Polynomial *Polynomial, int value);
void PolynomialAddition(struct Polynomial *Poly1, struct Polynomial *Poly2, struct Polynomial *Poly3);
void DisplayPolynomial(struct Polynomial *polynomial);
void FreePolynomial(struct Polynomial *polynomial);

int main()
{
    struct Polynomial Polynomial1, Polynomial2, Polynomial3;
    CreatePolynomial(&Polynomial1);
    CreatePolynomial(&Polynomial2);
    //CreatePolynomial(&Polynomial3);
    PolynomialAddition(&Polynomial1, &Polynomial2, &Polynomial3);

    DisplayPolynomial(&Polynomial1);
    DisplayPolynomial(&Polynomial2);
    DisplayPolynomial(&Polynomial3);
    // int poly1Result = EvaluatePolynomial(&Polynomial1, 2);
    // int poly2Result = EvaluatePolynomial(&Polynomial2, 2);
    // int poly3Result = EvaluatePolynomial(&Polynomial3, 2);
    
    // printf("poly1 evaluates to: %d\n", poly1Result);
    // printf("poly2 evaluates to: %d\n", poly2Result);
    // printf("poly2 evaluates to: %d\n", poly3Result);
    
    FreePolynomial(&Polynomial1);
    FreePolynomial(&Polynomial2);
    FreePolynomial(&Polynomial3);
    if(*(Polynomial1.ptrToPolynomial) == NULL)
    {
        printf("Null\n");
    }
    else
    {
        printf("Not Null\n");
    }
    if(*(Polynomial2.ptrToPolynomial) == NULL)
    {
        printf("Null\n");
    }
    else
    {
        printf("Not Null\n");
    }
    if(*(Polynomial3.ptrToPolynomial) == NULL)
    {
        printf("Null\n");
    }
    else
    {
        printf("Not Null\n");
    }

    return 0;
}

void CreatePolynomial(struct Polynomial *polynomial)
{
    polynomial->ptrToPolynomial = malloc(sizeof(struct Term *));
    LinkedList(polynomial->ptrToPolynomial);
}

int EvaluatePolynomial(struct Polynomial *Polynomial, int value)
{
    int sum = 0;
    struct Term *p = NULL;
    if(*(Polynomial->ptrToPolynomial) == NULL)
    {
        return sum;
    }

    p = *(Polynomial->ptrToPolynomial);
    while(p != NULL)
    {
        sum = sum + (p->coefficient * pow(value, p->exponent));
        p = p->next;
    }

    return sum;
}

void PolynomialAddition(struct Polynomial *Poly1, struct Polynomial *Poly2, struct Polynomial *Poly3)
{
    Poly3->ptrToPolynomial = calloc(1, sizeof(struct Term*));
    //*(Poly3->ptrToPolynomial) = NULL;

    struct Term *p = *(Poly1->ptrToPolynomial);
    struct Term *q = *(Poly2->ptrToPolynomial);
    struct Term **poly3head = Poly3->ptrToPolynomial;
    while(p && q)
    {
        if(p->exponent < q->exponent)
        {
            InsertAtLast(poly3head, q->coefficient, q->exponent);
            q = q->next;
        }
        else if(p->exponent > q->exponent)
        {
            InsertAtLast(poly3head, p->coefficient, p->exponent);
            p = p->next;
        }
        else
        {
            int coefficentsSum = p->coefficient + q->coefficient;
            InsertAtLast(poly3head, coefficentsSum, p->exponent);
            p = p->next;
            q = q->next;
        }
    }

    while(p != NULL)
    {
        InsertAtLast(poly3head, p->coefficient, p->exponent);
        p = p->next; 
    }
    
    while(q != NULL)
    {
        InsertAtLast(poly3head, q->coefficient, q->exponent);
        q = q->next; 
    }
}


void DisplayPolynomial(struct Polynomial *polynomial)
{
    Display(*(polynomial->ptrToPolynomial));
}

void FreePolynomial(struct Polynomial *polynomial)
{
    freeList(polynomial->ptrToPolynomial);
}