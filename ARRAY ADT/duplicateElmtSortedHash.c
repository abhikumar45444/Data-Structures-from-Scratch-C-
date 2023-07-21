#include<stdio.h>

struct Array
{
    int A[10];
    int length;
    int size;
};


void DuplicateElementHashTable(struct Array arr, int max)
{
   int hastable[16 + 1] = {0};

   for (int i = 0; i < arr.length - 1; i++)
   {
        hastable[arr.A[i]]++; 
   }

   for (int i = 0; i < max + 1; i++)
   {
      if(hastable[i] > 1)
      {
        printf("%d appears %d time\n", i, hastable[i]);
      }
   }
   
}

int main()
{
     struct Array arr = {{5,7,9,9,10,11,13,13,13,16}, 10, 10};
     DuplicateElementHashTable(arr, 16);
    return 0;
}