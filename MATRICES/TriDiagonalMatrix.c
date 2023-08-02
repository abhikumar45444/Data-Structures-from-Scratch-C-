#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int y)
{
    if(i - j == 1)
    {
        m->A[i - 1] = y;
    }
    if (i - j == 0)
    {
        m->A[n - 1 + i - 1] = y;
    }
    if (i - j == -1)
    {
        m->A[2 * n - 1 + i - 1] = y;
    }
}

int main()
{
    int n = 5;
    struct Matrix m;
    m.n = n;
    m.A = (int*)malloc((n + n - 1 + n - 1) * sizeof(int));
    return 0;
}