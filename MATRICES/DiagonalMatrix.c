#include<stdio.h>

struct DMatrix
{
    int A[10];
    int n;
};

void SetElement(struct DMatrix *dmatrix, int i, int j, int element)
{
    if (i == j)
    {
        dmatrix->A[i - 1] = element;
    }
}

int GetElement(struct DMatrix dmatrix, int i, int j)
{
    if(i == j)
    {
        return dmatrix.A[i - 1];
    }
}

void DisplayMatrix(struct DMatrix dmatrix)
{
    for (int i = 0; i < dmatrix.n; i++)
    {
        for (int j = 0; j < dmatrix.n; j++)
        {
            if (i == j)
            {
                printf("%-2d ", dmatrix.A[j]);
            }
            else
            {
                int k = 0;
                printf("%-2d ", k);
            }
        }
        printf("\n");
    }
}


int main()
{
    struct DMatrix dmatrix = {{0}, 4};
    SetElement(&dmatrix, 1, 1, 4); SetElement(&dmatrix, 2, 2, 13); SetElement(&dmatrix, 3, 3, 11); SetElement(&dmatrix, 4, 4, 1);
    printf("%d\n", GetElement(dmatrix, 2, 2));
    DisplayMatrix(dmatrix);
    return 0;
}