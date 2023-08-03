#include<stdio.h>

void CountingWords(char s[])
{
    int i = 0, wordCount = 1; 
    
    //this loop will handle the case in which if user enters the spaces at the beginning of string
    //so to make user we we start our counting from first word onwards
    for (; s[i] != '\0'; i++)
    {
        if(s[i] != ' ')
        {
          break;
        }
    }
    
    
    for (; s[i] != '\0'; i++)
    {
        if((s[i] == ' ' && s[i-1] != ' ') && (s[i] == ' ' && s[i+1] != '\0'))
        {
             wordCount++;
        }
    }

    printf("total words: %d\n", wordCount);
}

int main()
{
    char s[] = "   hi, my name is dinesh ";
    CountingWords(s);
    return 0;
}