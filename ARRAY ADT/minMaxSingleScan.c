#include<stdio.h>

struct Array
{
    /* data */
   int A[10];
   int length;
   int size;
};

void MinMax(struct Array arr)
{
  int min = arr.A[0], max = arr.A[0];
  for (int i = 1; i < arr.length; i++)
  {
    if(arr.A[i] < min)
    {
        min = arr.A[i];
    }
    else if (arr.A[i] > max)
    {
        max = arr.A[i];
    }
  }
  printf("min: %d, max: %d\n", min,max);

}

int main()
{
    struct Array arr = {{2,5,4,6,8,4,9,10,3,12}, 10, 10};
    MinMax(arr);
    return 0;
}