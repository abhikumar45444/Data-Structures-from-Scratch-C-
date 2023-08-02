#include<stdio.h>
#include<stdlib.h>
struct Matrix
{
    int *A;
    int n;
};


/*
  
 A  1    2    3    4    5
1 | 5    5    5    5    5 |    M[i,j] = m[j,i]   
2 | 5    4    4    4    4 |    so we can store elemnts either as upper trinagle or lower triangle
3 | 5    4    3    3    3 |    as we know elemnt at i,j = element at j,i
4 | 5    4    3    4    4 |
5 | 5    4    3    4    6 |           

*/

int Set(struct Matrix *m, int i, int j, int y)
{
    if(i <= j)
      m->A[(j * (j - 1) / 2) + i - 1] = y;
}

int Get(struct Matrix m, int i, int j)
{
    if(i <= j)
      return m.A[(j * (j - 1) / 2) + i - 1];
    else
      return 0;  
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for ( j = 1; j <= m.n; j++)
        {
            if(i <= j)
            {
                printf("%-2d ", m.A[(j * (j - 1) / 2) + i - 1]);
            }
            if(j < i)
            {
                printf("%-2d ", m.A[(i * (i - 1) / 2) + j - 1]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n = 3, i, j, y;
    struct Matrix m;
    m.A = (int *)malloc((n * (n + 1) / 2) * sizeof(int));
    m.n = n;
    printf("enter elements:\n");
    for ( i = 1; i <= m.n; i++)
    {
        for ( j = 1; j <= m.n; j++)
        {

                scanf("%d", &y);
                Set(&m, i, j, y);

        }
    }

    Display(m);
    return 0;
}