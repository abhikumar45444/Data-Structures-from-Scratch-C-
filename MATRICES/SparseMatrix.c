#include<stdio.h>
#include<stdlib.h>

struct CoordinatesList
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
    struct CoordinatesList *list;
};

void Create(struct SparseMatrix *M);
void Print(struct SparseMatrix *M);

int main()
{
    struct SparseMatrix M;

    Create(&M);
    Print(&M);

    return 0;
}


void Create(struct SparseMatrix *M)
{
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &M->m, &M->n);
    printf("Enter number of non-zero elements: ");
    scanf("%d", &M->nonZeroElementCount);

    M->list = (struct CoordinatesList *)malloc(M->nonZeroElementCount * sizeof(struct CoordinatesList));

    printf("Enter RowNumber ColumnNumber and Element:\n");
    for (int i = 0; i < M->nonZeroElementCount; i++)
    {
        scanf("%d %d %d", &M->list[i].rowNumber, &M->list[i].columnNumber, &M->list[i].element);
    }

    // for (int i = 0; i < M->m; i++)
    // {
    //     for (int j = 0; j < M->n; j++)
    //     {
    //         if ((M->list[i]->rowNumber == i) && (M->list[i]->columnNmuber == j))
    //         {
    //             printf("%-2d ", M->list[i]->element)
    //         }
    //         else
    //         {
    //             printf("%-2d ", 0);
    //         }
    //     }
    //     printf("\n");
    // }
}

void Print(struct SparseMatrix *M)
{
    int k = 0;
    for (int i = 1; i <= M->m; i++)
    {
        for (int j = 1; j <= M->n; j++)
        {
            //printf("%d %d %d %d ", M->list[k].rowNumber, i, M->list[k].columnNumber, j);
            if ((M->list[k].rowNumber == i) && (M->list[k].columnNumber == j))
            {
                printf("%-2d ", M->list[k++].element);
                //k++;
            }
            else
            {
                printf("%-2d ", 0);
            }
        }
        printf("\n");
    }
}