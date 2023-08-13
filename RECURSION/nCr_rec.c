#include<stdio.h>

int C(int n, int r);

//func to calc. nCr using recursive approach (recursive approach can be implemented and find out using pascal triangle in which the selected term is addition of terms exactly above it).
int C(int n, int r)
{
    if(r == 0 || n == r)     //we know that r value can only be between 0 to n and when r = 0 value will be 1 example 1C0 = 1 
                            //and when n=r means value 1 example 1C1 = 1.                   
   {
       return 1;
   }

   return C(n-1, r-1) + C(n-1, r);  // every term is calculated using the addition of terms exactly above it.
                                   // example -> 4C2 = 3C1 + 3C2
                         
}

int main()
{
    int result = C(0,0);
    printf("%d", result);
    return 0;
}

/*                               ***********         pascal triangle         *********************

                                                                0
                                                                 C
                                                                  0
                                            
                                                       1                   1
                                                        C                   C
                                                         0                   1
                                            
                                              2                 2                    2   
                                               C                 C                    C
                                                0                 1                     2
                                    
                                     3                 3                    3                  3   
                                      C                 C                    C                  C
                                       0                 1                     2                 3

                          4                 4                    4                  4                   4
                           C                 C                    C                  C                    C
                            0                 1                     2                 3                     4
             
 */                                               