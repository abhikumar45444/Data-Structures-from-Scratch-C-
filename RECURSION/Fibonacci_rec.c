#include<stdio.h>

int fib(int n);

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    
    return fib(n - 2) + fib(n -1);
    
}

int main()
{
    int result = fib(7);
    printf("%d\n", result);
    return 0;
}