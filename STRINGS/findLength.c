#include<stdio.h>

int StringLength(const char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {

    }
    return i;
}

int main()
{
    char s[] = "dinesh kumar";
    int len = StringLength(s);
    printf("length: %d\n", len);
    return 0;
}