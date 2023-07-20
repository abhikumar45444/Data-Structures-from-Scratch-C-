
/*  ************************************ ARRAY ADT (ABSTRACT DATA TYPE) **********************************************
 *  ADT means :–
 *  1) Representation of Data.
 *  2) Set of Operations on the Data.
 
 *  C/C++ provides Array as a basic data structure. 
 *  Representation of data is defined by the language compiler itself. 
 *  But the operations on the data are not defined by the compiler. We have to implement or provide the operations on Array data structure. 
 *  So, data structure array and the set of operations together we can call it as Abstract Data Type (ADT).
 * ____________________________________________________________________________________________________________________*/

#define _CRTDBG_MAP_ALLOC
#include<stdio.h>
#include<stdlib.h>
//#include<crtdbg.h>

//Representation of Data
struct Array         // created a structure for array ADT
{
    //these are called the properties or DATA of array DS
    int *A;          // a pointer of type int which will be used for pointer array on heap.
    int size;        // size variable for creating a dynamic array of size inputed by user.
    int length;      // length will store the total elements currently present in array.  size of array can be 10 but it is possible that all the space are not filled.

};


//these are the methods or functions or Operations that we perform on array ADT.
void Display(struct Array *arr);
void Add(struct Array *arr, int n);
void Insert(struct Array *arr, int index, int n);
int Delete(struct Array *arr, int index);
int LinearSearch(struct Array *arr, int key);
int LinearSearchTranspostion(struct Array *arr, int key);
int LinearSearchMoveToFront(struct Array *arr, int key);
int BinarySearch(struct Array arr, int key);
// Basic functions : 
int Get(struct Array arr, int index);
void Set(struct Array *arr, int index, int value);
int Max(struct Array arr);
int Min(struct Array arr);
int Sum(struct Array arr);
float Avg(struct Array arr);
void swap(int *num1, int *num2);
//Reverse, shift and rotation functions
void Reverse_Method1(struct Array *arr);
void Reverse_Method2(struct Array *arr);
void LeftShift(struct Array *arr);
void RightShift(struct Array *arr);
void LeftRotate(struct Array *arr);
void RightRotate(struct Array *arr);
//some other Important functions (on sorted array)
void InsertSorted(struct Array *arr, int value);
int IsSorted(struct Array arr);
void ArrangeNegatives(struct Array *arr);
struct Array* Merge(struct Array *arr1, struct Array *arr2);
//Set Operations on Array : union, intersection, difference, set memebership
struct Array* Union(struct Array *arr1, struct Array *arr2);
struct Array* UnionSorted(struct Array *arr1, struct Array *arr2);
struct Array* Intersection(struct Array *arr1, struct Array *arr2);
struct Array* IntersectionSorted(struct Array *arr1, struct Array *arr2);
struct Array* Difference(struct Array *arr1, struct Array *arr2);
struct Array* DifferenceSorted(struct Array *arr1, struct Array *arr2);



int main()
{

    struct Array arr,arr1, arr2;  //created an object of type strcut Array 
    int n, m;
    
    // printf("Enter the size of array: ");
    // scanf("%d", &arr.size);  //taking input for size of array from user. 
     
    // arr.A = (int*)malloc(sizeof(int) * arr.size); // this step will create the dynamic array of size userdefined on heap and assigned the address to pointer A. 
    // arr.length = 0; //initially there will bi no element in the array.
    
    // for (int i = 0; i < arr.size; i++)
    // {
    //     arr.A[i] = 0;
    // }
    
    // printf("enter the number of elements: ");
    // scanf("%d", &n);

    // printf("Enter all the elements:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr.A[i]);  // taking input for elements.
    // }
    // arr.length = n;   // icrementing the length of array as the elements are filled in.






    printf("Enter the size of arrays: ");
    scanf("%d %d", &arr1.size, &arr2.size);  //taking input for size of array from user. 
     
    arr1.A = (int*)malloc(sizeof(int) * arr1.size); // this step will create the dynamic array of size userdefined on heap and assigned the address to pointer A. 
    arr2.A = (int*)malloc(sizeof(int) * arr2.size);
    arr1.length = 0; //initially there will bi no element in the array.
    arr2.length = 0;

    for (int i = 0; i < arr1.size; i++)
    {
        arr1.A[i] = 0;
        arr2.A[i] = 0;
    }
    
    printf("enter the number of elements: ");
    scanf("%d %d", &n, &m);

    printf("Enter all the elements of array 1:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1.A[i]);  // taking input for elements.
    }
    arr1.length = n;   // icrementing the length of array as the elements are filled in.
    
    printf("Enter all the elements of array 2:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2.A[i]);  // taking input for elements.
    }
    arr2.length = m;
    Display(&arr1);
    Display(&arr2);



     //Display(&arr);
    //Add(&arr, 8);
    //Insert(&arr, 1, 9);
    //printf("%d\n",Delete(&arr, 2));
    //printf("element %d is present at index %d\n",8,LinearSearch(&arr, 8));
    // printf("element %d is present at index %d\n",8,LinearSearchTranspostion(&arr, 8));
    //  Display(&arr);
    // printf("element %d is present at index %d\n",8,LinearSearchTranspostion(&arr, 8));
    // Display(&arr);
    // printf("element %d is present at index %d\n",8,LinearSearchTranspostion(&arr, 8));
    // Display(&arr);
    //  printf("element %d is present at index %d\n",8,LinearSearchMoveToFront(&arr, 8));
    //  Display(&arr);
    // printf("element %d is present at index %d\n",8,LinearSearchMoveToFront(&arr, 8));
    // Display(&arr);
    // printf("element %d is present at index %d\n",8,LinearSearchMoveToFront(&arr, 8));
    // Display(&arr);
    //  printf("index %d\n",8,BinarySearch(arr, 8));
    //  Display(&arr);
    // printf("index %d\n",8,BinarySearch(arr, 8));
    // Display(&arr);
    // printf("index %d\n",8,BinarySearch(arr, 8));
    // Display(&arr);
    //LeftShift(&arr);
    //RightShift(&arr);
    //printf("index %d\n",8,BinarySearch(arr, 8));
    //InsertSorted(&arr, 18);
    //ArrangeNegatives(&arr);
    //struct Array *arr3 = Merge(&arr1, &arr2);
    // struct Array *arr3 = Union(&arr1, &arr2);
    //struct Array *arr3 = UnionSorted(&arr1, &arr2);
    // struct Array *arr3 = Intersection(&arr1, &arr2);
    //struct Array *arr3 = IntersectionSorted(&arr1, &arr2);
    struct Array *arr3 = Difference(&arr1, &arr2);
    //struct Array *arr3 = DifferenceSorted(&arr1, &arr2);
    Display(arr3);
    free(arr.A);
    arr.A = NULL;
    //_CrtDumpMemoryLeaks();
    return 0;
}


void Display(struct Array *arr)            // function to display the elements of array -> return nothing, take single parameter of type struct Array
{
    for (int i = 0; i < arr->length; i++)
    {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}


void Add(struct Array *arr, int n)          //function to append the value at the end of array.  T.C = O(1)
{
      if (arr->length < arr->size)
      {
          arr->A[arr->length++] = n; // this will append the value the at end and after the stmt length will ve incresed because of (++) postfix opr.
          //(arr->length)++;
      }
      else
      {
          printf("array is full!!\n");
      }
          
}

void Insert(struct Array *arr, int index, int n)  // function to insert the value at a particular index.   T.C = max->O(n)  min->O(1)
{
    int length = arr->length;
     if (index >= 0 && index <= length)
     {
         for (int i = length; i > index; i--)   // loop will start from the length because we have to shift all element to the right to make space avail for index.
         {
             arr->A[i] = arr->A[length - 1];
         }
         arr->A[index] = n;
         arr->length++;
     }
     else
     {
         printf("something wrong!!\n");
     }
     
}


//function to delete an element at particular index
int Delete(struct Array *arr, int index)                 // T.C = min->O(1) max->O(n)
{
    int x = 0;
   if(index >= 0 && index < arr->length)                // elment can only deleted from length of array.
   {
    x = arr->A[index];                                // --> time = 1
    for (int i = index; i < (arr->length - 1); i++)  // loop will execute from index specified till length - 1 we only want to move elements till last - 1. shifting all elements to left.
    {
        arr->A[i] = arr->A[i+1];                    //--> time = 0 - n
    }
    arr->length--;                                 //--> time = 1         
                                                  // f(n) = 1+0+1 for min   , for max  f(n) = 1+n+1 
    //printf("deleted element is %d from index %d\n", x, index);
    return x;
   }
}


// this Linear search operation is simplest it take key value which is to be found and return index of number if found O/W retrurn -1  
int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)  //start searching linearly from index 0 till n to find the number
    {
        if(key == arr->A[i])  //compares key value with every location linearly if success return index
        {
            return i;
        }
    }
    return -1;  // this will execute when value is not present in array this is not valid index means search unsuccessful
    
}


// improved version of linear search in which if element is found we swap the key value with adjacent left value every time the same element is searched for this will gradually decrease the T.C
int LinearSearchTranspostion(struct Array *arr, int key) 
{
    for(int i = 0; i < arr->length; i++)
    {
        
        if(key == arr->A[i])
        {
            if(i == 0)  // if searched element is at first position we dont need to perform swap as it is already best.
            {
                return i;
            }
            swap(&arr->A[i],&arr->A[i-1]);  //swaping searched value with left element one time
            return i;
        }
    }
    return -1;
}


//this is another approach to improve Linear Search , and we dont have to pass array as reference we can it by vvalue as it is not changing the values
int LinearSearchMoveToFront(struct Array *arr, int key)
{
    for(int i = 0; i < arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}


// in searching function we are not changing the values of array, so passing it as call by value is ok we dont have to pass it as reference.
int BinarySearch(struct Array arr, int key)
{
    int low = 0,high = arr.length - 1,mid;  // low will to set to 0th index, high will be set to last element index, mid will be set to mid value(floor)
    
    while ( low <= high)  // loop will run until the key is found or low index and high index crosses each other
    {
        mid = (low + high) / 2;

        if(key == arr.A[mid]) // checking mid value is equal to key value
        {
            return mid;
        }
        else if(key > mid)  // if key value is greater than mid that means value is present on right hand side of mid so make low mid + 1 (+ 1 because we already checked for mid) 
        {
            low = mid + 1;
            //mid = (low + high) / 2;
        }
        else               // if key value is smaller than mid that means value is present on left hand side of mid so make high = mid - 1 (+ 1 because we already checked for mid)
        {
            high = mid - 1;
            //mid = (low + high) / 2; 
        }
    }
    return -1;
}


int Get(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}


void Set(struct Array *arr, int index, int value)
{
    if(index >= 0 && index < arr->length)
    {
        arr->A[index] = value;
    }
    else
    {
        printf("invalid index!!\n");
    }
}

int Max(struct Array arr)
{
   int max = arr.A[0];
   for (int i = 1; i < arr.length; i++)
   {
       if(arr.A[i] > max)
       {
           max = arr.A[i];
       }
   }

   return max;
}


int Min(struct Array arr)
{
   int min = arr.A[0];
   for (int i = 1; i < arr.length; i++)
   {
       if(arr.A[i] < min)
       {
           min = arr.A[i];
       }
   }
   
   return min;
}


int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    
    return sum;
}


float Avg(struct Array arr)  // we can call sum function in it also to make function style more modular
{
    float average = 0, sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    
    average = sum / arr.length;

    return average;
}


void Reverse_Method1(struct Array *arr)  //thid method require a auxiliary copy array let say 'B' 
{
    int *b;
    b = (int*)malloc(arr->size * sizeof(int));

    for (int i = arr->length - 1, j = 0; i >= 0; i--,j++)  // first we will copy all elements from array A from last postion to Array B from first position
    {
        b[j] = arr->A[i];
    }

    for (int i = 0; i < arr->length; i++)  // then copy back all elements from array B to A from first position till last position
    {
        arr->A[i] = b[i];
    }

    free(b);
    b = NULL;
}

void Reverse_Method2(struct Array *arr)  // this method we swap the fist and last position with help of i = 0, j = arr->length-1 variable till i<j
{
    for (int i = 0, j = arr->length-1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    } 
}


void LeftShift(struct Array *arr) //this method removes the first position element from array by shifting all the element towards LHS
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = 0;
    
}


void RightShift(struct Array *arr) //this method removes the last position element from array by shifting all the element towards RHS
{
    for (int i = arr->length-1; i >=0 ; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = 0;
}


// this method will make the first element last element 
// by performing rotation on array it first shift all elements to left than put first element to lastt position
void LeftRotate(struct Array *arr)  
{
    int temp = arr->A[0];

    for (int i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
}


// this method will make the last element first element 
// by performing rotation on array it first shift all elements to right than put last element to first position
void RightRotate(struct Array *arr)
{
   int temp = arr->A[arr->length-1];

    for (int i = arr->length-1; i >= 0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}


//this function will inserted an element in sorted arrar at its sorted location
void InsertSorted(struct Array *arr, int value)
{
    int i = arr->length-1; // we will start from last element 
    if(arr->length == arr->size)
    {
        return;
    }
    while(i >= 0 && arr->A[i] > value) // we will start from last element if element is greater than value than shift the eleement till the value place is found
    {
        arr->A[i+1] = arr->A[i];
        i--;   // index will decremented till to be inserted element location - 1
    }
    arr->A[++i] = value; //we will put the value at index + 1 loaction
    arr->length++;
}



int IsSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}



// this functions arranges the -ve values on LHS and +ve values of RHS
void ArrangeNegatives(struct Array *arr)
{
    int i, j;   // we wil use two index variables i will point to 0th indx and j will point to last element
    i = 0;
    j = arr->length-1;
    while(i < j) // index i is less than index j we will perform interchanging and checking
    {
        while(arr->A[i] < 0)  // i will check for all the +ve elements
            i++;
        while(arr->A[j] >= 0)  // j will check for all the -ve elements
            j--;

        if(i < j)   // when both pair of -ve and +ve will found interchange the elements
        {
            swap(&arr->A[i], &arr->A[j]);
        }     
    }
}



// this method merges 2 array using a third array and return the Combined array
struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));  // created 3rd array
    arr3->size = arr1->size + arr2->size;

    int i = 0, j = 0, k = 0;  // we will use 3 index variables pointing to r arrays at index 0
    
    while(i < arr1->length && j < arr2->length) // loop will run until of the array is completely copied to 3rd array
    {
        if(arr1->A[i] < arr2->A[j])    // if array a of i is smaller than array b of j than copy a of i into array c and increment i and k
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else                          // if array b of j is smaller than array a of i than copy b of j into array c and increment j and k                           
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
     
     // when of the loop is finished it is possible that some of the elements will be remaining so we will run loop that index onwards to copy those remaining elmt

    for(; i < arr1->length; i++)
       arr3->A[k++] = arr1->A[i++];

    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = arr1->length + arr2->length;
    return arr3;    
}



//this method unions elemts of set A and set B and duplicate values are copied only once
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3;   //we will use 3rd array for copying all the elements
    arr3 = (struct Array *)malloc(sizeof(struct Array));  
    arr3->size = arr1->size + arr1->size;
    arr3->length = 0;
    int i, j, k;

    for (i = 0; i < arr1->length; i++)  //lets first copy all the element of Set A in to 3rd Array 
    {
        arr3->A[i] = arr1->A[i];
        arr3->length++;
    }

    for (j = 0; j < arr2->length; j++)  //now we will check for every element of Set A in Set B if element is present in Set B Dont copy it if it is not present copy it
    {
        for (k = 0; k < arr1->length; k++)
        {
            if(arr2->A[j] == arr1->A[k])
            {
                 break;
            }
        }
        
        if (k == arr1->length)
        {
            arr3->A[i++] = arr2->A[j];
            arr3->length++;
        }
    }

    return arr3;
}


//this method works for sorted Sets and here we will use the merge method with some modification
struct Array* UnionSorted(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;
    
    int i = 0, j = 0, k = 0;
    
    while(i < arr1->length && j < arr2->length) // we will set index i,j,k to first element of array 1 and array 2 and 3 repectively and loop will until one list is traversed
    {
        if(arr1->A[i] < arr2->A[j])  // whichever is smaller copy it to third array
        {
            arr3->A[k++] = arr1->A[i++];
            //arr3->length++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
            //arr3->length++;
        }
        else
        {
            arr3->A[k++] = arr1->A[i++]; // if both element are equal copy from anyone and increment all indexes by one
            j++;
            //arr3->length++;
        }
    }

    for(; i < arr1->length; i++)  // it is possible that some elements were left when above while didcontinued, this will copy the remaining elements
    {
        arr3->A[k++] = arr1->A[i];
        //arr3->length++;
    }

    for(; j < arr2->length; j++)  // this will copy the remaining elements
    {
        arr3->A[k++] = arr2->A[j];
        //arr3->length++;
    }
    
    arr3->length = k;

    return arr3;
}


//this method copy those elements only which are present in both the Sets
struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;
    
    int i = 0, j = 0, k = 0;

    for(i = 0; i < arr1->length; i++)
    {
        for(j = 0; j < arr2->length; j++)
        {
            if(arr1->A[i] == arr2->A[j])
            {
                arr3->A[k++] = arr1->A[i];
                arr3->length++;
                break;
            }
        }
    }

    return arr3;
}



struct Array* IntersectionSorted(struct Array *arr1, struct Array *arr2)
{
     struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;
    
    int i = 0, j = 0, k = 0;

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
            arr3->length++;
        }
    }

    return arr3;
}



// this method will copy all the element from a which are not there in Set B and copies the value of Set A only.
struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;
    
    int i = 0, j = 0, k = 0;
    
    for ( i = 0; i < arr1->length; i++)
    {
        for ( j = 0; j < arr2->length; j++)
        {
            if(arr1->A[i] == arr2->A[j])
            {
               break;
            }
        }

        if(j == arr2->length)
        {
            arr3->A[k++] = arr1->A[i];
            arr3->length++; 
        }
    }

    return arr3;
    
}



struct Array* DifferenceSorted(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;
    
    int i = 0, j = 0, k = 0;

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            arr3->length++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
        arr3->length++;
    }
    
    // or 'i' var can be assigned to the value of 'k' var at the end to reduce the code lines
    return arr3;
}



void swap(int *num1, int *num2)
{
   int temp;
   temp = *num1;
   *num1 = *num2;
   *num2 = temp;
}