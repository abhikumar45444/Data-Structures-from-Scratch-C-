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
char StackTop(struct Stack stack);
char* ConvertInfixToPostfix(const char *infix);
int Precedence(char symbol);
int IsOperand(char symbol);
void FreeStack(struct Stack *stack);

int main()
{
    // struct Stack st;
    // CreateStack(&st);

//    const char *infix = "a+(b*c)-d/e";
   const char *infix = "a+b*c/d-f+a^e^f";
   char *postfix = ConvertInfixToPostfix(infix);
   printf("postfix expression is : %s\n", postfix);
   free(postfix);
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
    if(stack.size == 0)
    {
        printf("Stack Not created!\n");
        return 0;
    }

    if(stack.top == -1)
    {
        return '\0';
    }
    else
    {
        return stack.S[stack.top];
    }
}


int Precedence(char symbol)
{
    if(symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else if(symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if(symbol == '^')
    {
        return 3;
    }

    return 0;
}


int IsOperand(char symbol)
{
    if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
    {
        return 0;
    }

    return 1;
}


char* ConvertInfixToPostfix(const char *infix)
{
    
    struct Stack stack;
    int length = strlen(infix);
    CreateStack(&stack, length);

    char *postfix = calloc(length+1, sizeof(char));

    int i = 0, j = 0;
    while(infix[i] != '\0')
    {
        char symb = infix[i];
        if(IsOperand(symb))
        {
            // printf("%c", symb);
            postfix[j++] = infix[i++];
        }
        else
        {
            if(IsEmpty(stack))
            {
                Push(&stack, symb);
                i++;
            }
            else
            {
                    char stacktop = StackTop(stack);
                    if(Precedence(symb) > Precedence(stacktop))
                    {
                        Push(&stack, symb);
                        i++;
                    }
                    else
                    {
                        // printf("%c", Pop(&stack));
                        postfix[j++] = Pop(&stack);
                    }
             }
        }
    }

    while(!IsEmpty(stack))
    {
        // printf("%c", Pop(&stack));
        postfix[j++] = Pop(&stack);
    }

    FreeStack(&stack);
    if(stack.S == NULL)
    {
        printf("Null\n");
    }
    else
    {
        printf("Not Null\n");
    }

    return postfix;
}

void FreeStack(struct Stack *stack)
{
    free(stack->S);
    stack->S = NULL;
}