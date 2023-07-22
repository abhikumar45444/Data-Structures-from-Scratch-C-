#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[11];          // a pointer of type int which will be used for pointer array on heap.
    int size;        // size variable for creating a dynamic array of size inputed by user.
    int length;  
};

// this function is useful when the array doesn't follow first n natural sequence 
void MissingSingleElement(struct Array arr)
{
   //here we will find the common difference  
   int difference = arr.A[0] - 0;  // arr.A[0] is lowest value
   for (int i = 0; i < arr.length; i++)
   {
       // if common difference is greater than diffrence means the missing element is found
       if (arr.A[i] - i != difference)
       {
         printf("missing element is %d\n", difference + i);
         break;
       }   
   }
}


int main()
{
    struct Array arr = {{6,7,8,9,10,11,13,14,15,16,17},11,11};
    MissingSingleElement(arr,6,17);
    return 0;
}