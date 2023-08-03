#include<stdio.h>
#include<string.h>

int StringCompare(char s1[], char s2[])
{
    int i,j;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        if(s1[i] < s2[i])
        {
            return -1;
        }
        else if(s1[i] > s2[i])
        {
            return 1;
        }
    }

    if(s1[i] == '\0' && s2[i] == '\0')
    {
        return 0;
    }
    else if(s1[i] < s2[i])
    {
        return -1;
    }
    else 
    {
        return 1;
    }
}

int main()
{
    char s1[] = "Dinesh kumar";
    char s2[] = "Dinesh Kumar";
    int result2 = strcmp(s1,s2);
    int result = StringCompare(s1,s2);
    printf("res1 %d    re2 %d\n",result, result2);
    return 0;
}