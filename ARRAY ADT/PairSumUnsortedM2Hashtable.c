#include<stdio.h>

struct Array
{
    /* data */
    int A[10];
    int size;
    int length;
};

void PairSumUnsortedM2Hashtable(struct Array arr, int max, int k)
{
    int hashTable[max+1];
    for (int i = 0; i <= max+1; i++)
    {
        hashTable[i] = 0;
    }

    for (int i = 0; i < arr.length; i++)
    {
         if((hashTable[k - arr.A[i]] != 0) && (k - arr.A[i] > 1))
         {
            printf("%d + %d = %d\n", arr.A[i], k - arr.A[i], k);
         }
         hashTable[arr.A[i]]++;
    }   
}

int main()
{
    int k = 10;
    struct Array arr = {{6,3,10,8,17,4,2,9,11,15},10,10};
    PairSumUnsortedM2Hashtable(arr, 17, k);
    return 0;
}