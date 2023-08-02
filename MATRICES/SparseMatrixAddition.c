#include<stdio.h>
#include<stdlib.h>

struct Cordinate
{
    int rowNumber;
    int columnNumber;
    int element;
};

struct SparseMatrix
{
    int m;
    int n;
    int nonZeroElementCount;
    struct Cordinate *list;
};

void Create(struct SparseMatrix *M);
struct SparseMatrix* Addition(struct SparseMatrix *S1, struct SparseMatrix *S2);
void print(struct SparseMatrix M, char ch);

int main()
{
    struct SparseMatrix A, B, *C;
    char ch = 'A';
    Create(&A);
    Create(&B);
    C = Addition(&A, &B);
   if(C == NULL)
   {
       printf("Dimensions are no same! addtion cannot be performed.\n");
       print(A, ch++);
       print(B, ch++);
       free(A.list);
       free(B.list);
       free(C->list);
       exit(1);
   }
   
    print(A, ch++);
    print(B, ch++);
    print(*C, ch++);
    free(A.list);
    free(B.list);
    free(C->list);
    return 0;
}

void Create(struct SparseMatrix *M)
{
    printf("ENter the Dimensions of the Matrix (ROWS and COLUMNS): ");
    scanf("%d %d", &M->m, &M->n);
    printf("Enter the total number of non-zero elements in matrix: ");
    scanf("%d", &M->nonZeroElementCount);

    M->list = (struct Cordinate *)malloc(M->nonZeroElementCount * sizeof(struct Cordinate));
    
    if(M->list == NULL)
    {
        printf("Program Aborted!\nmalloc couldn't allocate memmory\n");
        exit(1);
    }

    printf("Enter the RowNumber ColumnNumber and Element Values for all non-zero elements:\n");
    for (int i = 0; i < M->nonZeroElementCount; i++)
    {
        scanf("%d %d %d", &M->list[i].rowNumber, &M->list[i].columnNumber, &M->list[i].element); // as you can see we are using list[i].rowNumber here instead of dot it should be ->
                                                                                                 // but we are using dot because [] subscript operator has dereference built into it. ex: a[i] is same as *(a + i).   
    }
}


struct SparseMatrix* Addition(struct SparseMatrix *S1, struct SparseMatrix *S2)
{
    if(S1->m != S2->m || S1->n != S2->n)   //matrix addition can only be done if dimensions are same
        return NULL;

    struct SparseMatrix *C; //we will use pointer to a struct Sparsematrix which points to matrix created on heap so we can access it from anywhere
    C = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix)); // created a SparseMatrix on heap to store result of matrix addition and assigned it to the pointer 
    C->m = S1->m;
    C->n = S1->n;
    
    //we dont know in advance how many non-zero elemts resulting matrix will contain but we know atmost it will contain 
    // total number of non zero elements in both matrix (non-zero elements in A + non-zero elements in B)
    //so size of cordinate list will total number of non-zero elemts in both matrix. 
    C->list = (struct Cordinate *)malloc((S1->nonZeroElementCount + S2->nonZeroElementCount) * sizeof(struct Cordinate));

    if(C->list == NULL)
    {
        printf("Aborted! malloc address not assigned\n");
        exit(1);
    }

    int i = 0, j = 0, k = 0;  // i, j variable to keep track of both tables and k variable to keep track of C matrix table

    while((i < S1->nonZeroElementCount) && (j < S2->nonZeroElementCount))
    {
        if(S1->list[i].rowNumber == S2->list[j].rowNumber)
        {
            if(S1->list[i].columnNumber == S2->list[j].columnNumber)
            {
                C->list[k] = S1->list[i++];
                C->list[k++].element += S2->list[j++].element;
            }
            else if(S1->list[i].columnNumber < S2->list[j].columnNumber)
            {
                C->list[k++] = S1->list[i++];
            }
            else
            {
                C->list[k++] = S2->list[j++];
            }    
        }
        else if(S1->list[i].rowNumber < S2->list[j].rowNumber)
        {
            C->list[k++] = S1->list[i++];
        }
        else
        {
            C->list[k++] = S2->list[j++];
        }       
    }
    
    // we should also consider the remaining elements so we will run loops for them
    for ( ; i < S1->nonZeroElementCount; i++)
    {
        C->list[k++] = S1->list[i];
    }
    
    for ( ; j < S2->nonZeroElementCount; j++)
    {
        C->list[k++] = S2->list[j];
    }

    C->nonZeroElementCount = k;
    return C;
}

void print(struct SparseMatrix M, char ch)
{
    printf("-------------------------------------------------------------------\n");
    printf("Matrix %c is:\n", ch);
    int k = 0;  // k variable is used to track cordinate list array
    for (int i = 1; i <= M.n; i++)   // i and j starts from 1 because we our matrices index starts from 1
    {
        for (int j = 1; j <= M.n; j++)
        {
            if(M.list[k].rowNumber == i && M.list[k].columnNumber == j)
            {
                printf("%-2d ",M.list[k++].element);
            }
            else
            {
                printf("%-2d ", 0);
            }
        }
        printf("\n");
    }
    printf("\n--------------------------------------------------------------------\n");
}