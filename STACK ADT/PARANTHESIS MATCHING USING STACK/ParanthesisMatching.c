/*  ************************************ STACK ADT (ABSTRACT DATA TYPE) **********************************************
 *  ADT means :–
 *  1) Representation of Data.
 *  2) Set of Operations on the Data.
 
 *  DEFINITION :-
     A Stack is an ordered list in which insertion and deletion are done at one end, called top. 
     The last element inserted is the first one to be deleted. 
     Hence, it is called the Last in First out (LIFO) or First in Last out (FILO) list.

 *  C/C++ does not provides Stack as a basic data structure. 
 *  The structure defintion of Stack (Data Representation) and and the operations on the data are not defined by the compiler.
 *  We have to implement or provide the operations on Stack data structure. 
 *  So, data structure Stack and the set of operations together we can call it as Abstract Data Type (ADT).
 * ____________________________________________________________________________________________________________________*/


    
    
/*


    |   5   |  <-- Stack Top
    |   3   |
    |   2   |                               <-----  Stack Representation
    |___4___|
           -1  <-- Initial Stack Top
            4  <-- Stack size



   Structure Representation -->      struct Stack{                  _____________
                                        int size;                   |___size____|  
                                        int top;                    |____top____|      ___________________
                                        int *A;                     |_____A_____|----->|___|____|____|___|  Array of some size 
                                    }

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int size;
    int top;
    char *S;
};



void CreateStack(struct Stack *stack, int expLength);
void Push(struct Stack *stack, char value);
char Pop(struct Stack *stack); 
int Peek(struct Stack stack, int position); 
int IsEmpty(struct Stack stack); 
int IsFull(struct Stack stack);
int IsMatching(const char *exp);
char StackTop(struct Stack stack);
void FreeStack(struct Stack *stack);

int main()
{
    // struct Stack st;
    // CreateStack(&st);

   const char *exp = "{(a+b)*c}+(d+e}";
    int isMatch = IsMatching(exp);
    if(isMatch == -1)
    {
        printf("Matching\n");
    } 
    else //if(isMatch == 0)
    {
        printf("Not Matching index: %d\n", isMatch);
    }
    return 0;
}


void CreateStack(struct Stack *stack, int expLength)
{
    //printf("Enter the size of Stack: ");
    //scanf("%d", &stack->size);
    stack->size = expLength;
    stack->top = -1;
    stack->S = calloc(stack->size, sizeof(char));
}


void Push(struct Stack *stack, char value)
{
    if(stack->top == stack->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack->S[++stack->top] = value;
    }
}

char Pop(struct Stack *stack)
{
    char value = '\0';
    if(stack->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        value = stack->S[stack->top--];
    }
    return value;
}


int Peek(struct Stack stack, int position)
{
    int value = -1;
    int index = stack.top - position + 1;
    if(index < 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        value = stack.S[index];
    }
    return value;
}


int IsEmpty(struct Stack stack)
{
    if(stack.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int IsFull(struct Stack stack)
{
    if(stack.top == stack.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


char StackTop(struct Stack stack)
{
    if(stack.top == -1)
    {
        return '\0';
    }
    else
    {
        return stack.S[stack.top];
    }
}

int IsMatching(const char *exp)
{
    if(exp[0] == '\0')
    {
        printf("Empty Expression\n");
        return -1;
    }

    int length = strlen(exp);

    struct Stack st;
    CreateStack(&st, length);

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            Push(&st, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if(IsEmpty(st))
            {
                FreeStack(&st);
                if(st.S == NULL)
                {
                    printf("Null\n");
                }
                else
                {
                    printf("Not Null\n");
                }
                return i;
            }
            else if(StackTop(st) == '(' && exp[i] == ')')
            {
                Pop(&st);
            }
            else if(StackTop(st) == '{' && exp[i] == '}')
            {
                Pop(&st);
            }
            else if(StackTop(st) == '[' && exp[i] == ']')
            {
                Pop(&st);
            }
            else
            {
                 FreeStack(&st);
                if(st.S == NULL)
                {
                    printf("Null\n");
                }
                else
                {
                    printf("Not Null\n");
                }
                return i;
            }
        }
    }

    if(IsEmpty(st))
    {
        FreeStack(&st);
        if(st.S == NULL)
        {
            printf("Null\n");
        }
        else
        {
            printf("Not Null\n");
        }
        return -1;
    }
    else
    {
        FreeStack(&st);
        if(st.S == NULL)
        {
            printf("Null\n");
        }
        else
        {
            printf("Not Null\n");
        }
        return length-1;
    }
}


void FreeStack(struct Stack *stack)
{
    free(stack->S);
    stack->S = NULL;
}