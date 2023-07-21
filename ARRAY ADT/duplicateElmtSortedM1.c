#include<stdio.h>

struct Array
{
    int A[10];
    int length;
    int size;
};

void DuplicateElement(struct Array arr)
{
   int last_duplicate = 0;
   for (int i = 0; i < arr.length - 1; i++)
   {
       if(arr.A[i] == arr.A[i+1] && arr.A[i] != last_duplicate)
       {
        printf("dulpicate element is %d\n", arr.A[i]);
        last_duplicate = arr.A[i];
       }
   }
}


void DuplicateElementAppeared(struct Array arr)
{
   int last_duplicate = 0, j = 0;
   for (int i = 0; i < arr.length - 1; i++)
   {
       if(arr.A[i] == arr.A[i+1])
       {
           j = i + 1; 
           while(arr.A[j] == arr.A[i]) j++;
           printf("%d appearing %d times\n", arr.A[i], j - i);
           i = j - 1;
       }
   }
   
}

int main()
{
    struct Array arr = {{5,7,9,9,10,11,13,13,13,16}, 10, 10};
    DuplicateElementAppeared(arr);
    return 0;
}