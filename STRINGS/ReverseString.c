#include<stdio.h>


void Swap(char *s1, char *s2)
{
    char temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void ReverseString(char s[])
{
    int i = 0,j = 0;

    for ( j = 0; s[j] != '\0'; j++)
    {
        
    }
    
    j = j - 1;
    while (i < j)
    {
        Swap(&s[i], &s[j]);
        // char temp;
        // temp = s[i];
        // s[i] = s[j];
        // s[j] = temp;
        i++;
        j--;
    }
    
}

int main()
{
    char s[] = "Dinesh";
    ReverseString(s);
    printf("%s\n", s);
    return 0;
}