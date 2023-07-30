#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

/*

| a11  a12  a13  a14  a15 |
| 0    a22  a23  a24  a25 |
| 0    0    a33  a34  a35 |
| 0    0    0    a44  a55 |
| 0    0    0    0    a55 |

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
            else
            {
                printf("%-2d ", 0);
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
            if (i <= j)
            {
                scanf("%d", &y);
                Set(&m, i, j, y);
            }
        }
    }

    Display(m);
    return 0;
}