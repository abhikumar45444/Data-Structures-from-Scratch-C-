#include<stdio.h>

void Palindrome(char s[])
{
  int i = 0, j = 0;
  for ( j = 0; s[j] != '\0'; j++);

  j = j - 1;
  
  while (i < j)
  {
    if (s[i] != s[j])
    {
       printf("not palindrome\n");
       return;
    }
    i++;
    j--;
  }
  
  printf("palindrome\n");
}

int main()
{
    char s[] = " madam ";
    Palindrome(s);
    return 0;
}