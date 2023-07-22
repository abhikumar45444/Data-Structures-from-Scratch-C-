#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[11];          // a pointer of type int which will be used for pointer array on heap.
    int size;        // size variable for creating a dynamic array of size inputed by user.
    int length;  
};


void MissingSingleElement(struct Array arr, int max)
{
   int maxSum = (max * (max + 1)) / 2;
   int arrSum = 0;
   for (int i = 0; i < arr.length; i++)
   {
     arrSum += arr.A[i];
   }
   
   printf("missing element is %d\n", maxSum - arrSum);
}


int main()
{
    struct Array arr = {{1,2,3,4,5,6,8,9,10,11,12},11,11};
    MissingSingleElement(arr,12);
    return 0;
}