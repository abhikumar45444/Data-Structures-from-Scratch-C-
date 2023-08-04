#include<stdio.h>

void DuplicateUsingBit(char s[])
{
    int h = 0;
    int x = 1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        x = 1;
        x = x << (s[i] - 97);
        if((x & h) > 0)
        {
            printf("duplicate is %c\n", s[i]);
            
        }
        else
        {
            h = h | x;
        }
    }
}

int main()
{
    char s[] = "finding";
    DuplicateUsingBit(s);
    return 0;
}