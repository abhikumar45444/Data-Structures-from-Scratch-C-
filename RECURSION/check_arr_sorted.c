#include<stdio.h>

int arraySorted(int arr[], int len)
{
    if(len < 2)
    {
        printf("array is sorted!\n");
        return 1;
    }
    if(arr[len - 1] >= arr[len - 2])
    {
        return arraySorted(arr, len - 1);
    }
    else
    {
        printf("array is not sorted!!\n");
        return 1;
    }
    
}

int main()
{
    //int array[10] = {2,3,1,4,5,2,4,5,6,8};
    int array[10] = {0,1};
    arraySorted(array, 2);
    return 0;
}