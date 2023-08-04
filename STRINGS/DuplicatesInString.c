#include<stdio.h>

void Duplicates(char s[])
{
    char h[26] = {0};
    
    for (int i = 0; s[i] != '\0'; i++)
    {
        h[s[i] - 97]++; 
    }

    for (int i = 0; i < 26; i++)
    {
        if (h[i] > 1)
        {
            printf("%c is duplicate %d times\n", i + 97, h[i]);
        }
    }
}

int main()
{
    char s[] = "madam";
    Duplicates(s);
    return 0;
}