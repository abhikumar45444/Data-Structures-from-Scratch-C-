#include<stdio.h>

void AnagramStrings(char s1[], char s2[])
{
    char h[26] = {0};

    for (int i = 0; s1[i] != '\0'; i++)
    {
        h[s1[i] - 97]++;
    }

    for (int i = 0; s2[i] != '\0'; i++)
    {
        h[s2[i] - 97]--;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (h[i] != 0)
        {
            printf("Not anagram!\n");
            return;
        }
    }
    
    printf("Anagrams!\n");
    
}

int main()
{
    char s1[] = "abcd";
    char s2[] = "bcde";
    AnagramStrings(s1,s2);
    return 0;
}