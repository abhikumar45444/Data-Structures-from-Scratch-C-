#include<stdio.h>

struct Array
{
    /* data */
    int A[10];
    int length;
    int size;
};

void PairSumSorted(struct Array arr, int k)
{
    int i = 0, j = arr.length - 1;
    while(i < j)
    {
        if (arr.A[i] + arr.A[j] == k)
        {
            printf("%d + %d = %d\n", arr.A[i], arr.A[j], k);
            i++;
            j--;
        }
        else if(arr.A[i] + arr.A[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    } 
}

int main()
{
    struct Array arr = {{1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, 10, 10};
    PairSumSorted(arr, 10);
    return 0;
}