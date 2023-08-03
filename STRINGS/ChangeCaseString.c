#include<stdio.h>

void ChangeCase(char s[])
{
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (s[i] >= 97 && s[i] <= 122)
      {
        s[i] = s[i] - 32;
      }
      else if(s[i] >= 'A' && s[i] <= 'Z')
      {
          s[i] = s[i] + 32;
      }
      
   }
   
}

int main()
{
    char s[] = "DinESh0101";
    ChangeCase(s);
    printf("%s\n", s);
    return 0;
}