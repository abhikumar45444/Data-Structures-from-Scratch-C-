#include<stdio.h>

struct Array{
    int A[10];
    int length;
    int size;
};

void DuplicateUnsorted(struct Array arr, int max)
{
   int hashTable[max+1];

   for (int i = 0; i <= max; i++)
   {
      hashTable[i] = 0;
   }
   
   for (int i = 0; i < arr.length; i++)
   {
      hashTable[arr.A[i]]++;
      //arr.A[i] = -1;
   }
   
   for (int i = 0; i <= max; i++)
   {
      //printf("%d ",hashTable[i]);

      if(hashTable[i] > 1)
      {
        printf("%d is appearing %d times\n", i , hashTable[i]);
      }
   }
}


int main()
{
    struct Array arr = {{8,3,6,4,6,5,6,8,2,7},10,10};
    DuplicateUnsorted(arr, 8);
    return 0;
}