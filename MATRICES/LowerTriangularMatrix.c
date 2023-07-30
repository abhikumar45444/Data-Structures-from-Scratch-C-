#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

/*

| a11    0    0    0    0 |
| a21  a22    0    0    0 |
| a31  a32  a33    0    0 |
| a41  a42  a43  a44    0 |
| a51  a52  a53  a54  a55 |

*/




void Set(struct Matrix *m, int i, int j, int value)
{
    if(i >= j)
      m->A[((i * (i - 1)) / 2) + j - 1] = value;
}

int Get(struct Matrix m, int i, int j, int y)
{
  if(i >= j)
  {
    return m.A[(i * (i - 1) / 2) + j - 1];
  }
  return 0;
}

void Display(struct Matrix m)
{
  int i, j;
  printf("Matrix is:\n");
  for (i = 1; i <= m.n; i++)
  {
    for (j = 1; j <= m.n; j++)
    {
       if(i >= j)
       {
        printf("%-2d ", m.A[(i * (i - 1) / 2) + j - 1]);
       }
       else
       {
        printf("%-2d ",0);
       }
    }
    printf("\n");
  }
}

int main()
{
  int n = 3, i , j, y;
  struct Matrix m;
  m.A = (int*)malloc((n * (n+1) / 2) * sizeof(int));
  m.n = n;
  
  for (i = 1; i <= m.n; i++)
  {
     for (j = 1; j <= m.n; j++)
     {
       if(i >= j)
       {
          scanf("%d", &y);
          Set(&m, i, j, y);
       }
     }
  }
  
  Display(m);
  return 0;
}





