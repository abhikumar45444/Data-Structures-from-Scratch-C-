#include<stdio.h>

struct Array
{
    /* data */
    int A[10];
    int size;
    int length;
};

void PairSumUnsortedM1(struct Array arr, int pairSum)
{
  for (int i = 0; i < arr.length - 1; i++)
  {
     for (int j = i+1; j < arr.length; j++)
     {
        if((arr.A[i] + arr.A[j]) == pairSum)
        {
           printf("%d + %d = %d\n", arr.A[i], arr.A[j], pairSum);
        }
     }
  } 
}

int main()
{
    int k = 10;
    struct Array arr = {{6,3,10,8,17,4,2,9,11,15},10,10};
    PairSumUnsortedM1(arr, k);
    return 0;
}