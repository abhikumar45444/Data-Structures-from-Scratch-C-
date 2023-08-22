#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int  size;
    int  top;
    char *S;
};

struct EvaluationStack
{
    int size;
    int top;
    int *A;
};

void CreateStack(struct Stack *stack, int expLength);
void CreateEvaluationStack(struct EvaluationStack *stack, int expLength);
void Push(struct Stack *stack, char value);
void EvaluateStackPush(struct EvaluationStack *stack, int value);
char Pop(struct Stack *stack); 
int EvaluateStackPop(struct EvaluationStack *stack); 
int Peek(struct Stack stack, int position); 
int IsEmpty(struct Stack stack); 
int EvaluationStackIsEmpty(struct EvaluationStack stack); 
int IsFull(struct Stack stack);
int EvaluationStackIsFull(struct EvaluationStack stack);
char StackTop(struct Stack stack);
int EvaluationStackStackTop(struct EvaluationStack stack);
char* ConvertInfixToPostfix(const char *infix);
void PostfixEvaluation(const char *infix);
int InsideOfStkPrecedence(char symbol);
int OutsideOfStkPrecedence(char symbol);
int Precedence(char symbol);
int IsOperand(char symbol);
void FreeStack(struct Stack *stack);
void EvaluationStackFreeStack(struct EvaluationStack *stack);


int main()
{
//    struct Stack st;
//    CreateStack(&st);

//    const char *infix = "a+(b*c)-d/e";
//    const char *infix = "((a+b)*c)/d-f+a^e^f";
//    const char *infix = "(((a+b)*c)-d)^e^f";
//    char *postfix = ConvertInfixToPostfix(infix);
//    printf("postfix expression is : %s\n", postfix);
//    free(postfix);


//    give infix expression to PostfixEvaluation function and enable the conversion function inside it.
//    const char *infix = "2+3*6/2";
   
//    directly giving postfix
   const char *Postfix = "100 200 + 2 / 5 * 7 +";
//    const char *Postfix = "2 3 1 * + 9 -";

   PostfixEvaluation(Postfix);

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


void CreateEvaluationStack(struct EvaluationStack *stack, int expLength)
{
    stack->size = expLength;
    stack->top = -1;
    stack->A = calloc(stack->size, sizeof(int));
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


void EvaluateStackPush(struct EvaluationStack *stack, int value)
{
    if(stack->top == stack->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack->A[++stack->top] = value;
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


int EvaluateStackPop(struct EvaluationStack *stack)
{
    int value = 0;
    if(stack->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        value = stack->A[stack->top--];
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



int EvaluationStackIsEmpty(struct EvaluationStack stack)
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




int EvaluationStackIsFull(struct EvaluationStack stack)
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



int EvaluationStackStackTop(struct EvaluationStack stack)
{
    if(stack.size == 0)
    {
        printf("Stack Not created!\n");
        return 0;
    }

    if(stack.top == -1)
    {
        return 0;
    }
    else
    {
        return stack.A[stack.top];
    }

}



int InsideOfStkPrecedence(char symbol)
{
    if(symbol == '+' || symbol == '-')
    {
        return 2;
    }
    else if(symbol == '*' || symbol == '/')
    {
        return 4;
    }
    else if(symbol == '^')
    {
        return 5;
    }
    else if(symbol == '(')
    {
        return 0;
    }

    return 0;
}

int OutsideOfStkPrecedence(char symbol)
{
    if(symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else if(symbol == '*' || symbol == '/')
    {
        return 3;
    }
    else if(symbol == '^')
    {
        return 6;
    }
    else if(symbol == '(')
    {
        return 7;
    }
    else if(symbol == ')')
    {
        return 0;
    }

    return 0;
}


int IsOperand(char symbol)
{
    if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '(' || symbol == ')' )
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
                    if(OutsideOfStkPrecedence(symb) > InsideOfStkPrecedence(stacktop))
                    {
                        Push(&stack, symb);
                        i++;
                    }
                    else if(OutsideOfStkPrecedence(symb) == InsideOfStkPrecedence(stacktop))
                    {
                        Pop(&stack);
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



void PostfixEvaluation(const char *infix)
{
    // char *postfix = ConvertInfixToPostfix(infix);
    const char *postfix = infix;

    int lengthOfPostfix = strlen(postfix);

    struct EvaluationStack evalstack;
    CreateEvaluationStack(&evalstack, lengthOfPostfix);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if(postfix[i] == ' ')
        {
            continue;
        }
        else if (IsOperand(postfix[i]))
        {
            // int digit = atoi(postfix[i]);
                int num = 0;
            while(postfix[i] >= '0' && postfix[i] <= '9')
            {
                num = num * 10 + (postfix[i] - '0');
                // int digit = postfix[i] - '0';
                i++;
            }
            i--;
            EvaluateStackPush(&evalstack, num);
        }
        else
        {
            int operandright = EvaluateStackPop(&evalstack);
            int operandleft = EvaluateStackPop(&evalstack);
            switch(postfix[i])
            {
                case '+': EvaluateStackPush(&evalstack, (operandleft + operandright));
                          break;
                case '-': EvaluateStackPush(&evalstack, (operandleft - operandright));
                          break;
                case '*': EvaluateStackPush(&evalstack, (operandleft * operandright));
                          break;
                case '/': EvaluateStackPush(&evalstack, (operandleft / operandright));
                          break;
            }

            // if(postfix[i] == '+')
            // {
               
            //     EvaluateStackPush(&evalstack, (operandleft + operandright));
            // }
            // else if(postfix[i] == '-')
            // {
            //     int operandright = EvaluateStackPop(&evalstack);
            //     int operandleft = EvaluateStackPop(&evalstack);
            //     EvaluateStackPush(&evalstack, (operandleft - operandright));
            // }
            // else if(postfix[i] == '*')
            // {
            //     int operandright = EvaluateStackPop(&evalstack);
            //     int operandleft = EvaluateStackPop(&evalstack);
            //     EvaluateStackPush(&evalstack, (operandleft * operandright));
            // }
            // else if(postfix[i] == '/')
            // {
            //     int operandright = EvaluateStackPop(&evalstack);
            //     int operandleft = EvaluateStackPop(&evalstack);
            //     EvaluateStackPush(&evalstack, (operandleft / operandright));
            // }
        }
    }

    printf("postfix evaluation is: %d\n", EvaluateStackPop(&evalstack));

    EvaluationStackFreeStack(&evalstack);
    //free(postfix);
}


void FreeStack(struct Stack *stack)
{
    free(stack->S);
    stack->S = NULL;
}


void EvaluationStackFreeStack(struct EvaluationStack *stack)
{
    free(stack->A);
    stack->A = NULL;   
}