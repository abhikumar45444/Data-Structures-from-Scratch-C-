#include<stdio.h>

void VandC(char s[])
{
    int vCount = 0, cCount = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if((s[i] == 'a' || s[i] == 'A') || (s[i] == 'e' || s[i] == 'E') 
        || (s[i] == 'i' || s[i] == 'I') || (s[i] == 'o' || s[i] == 'O') 
        || (s[i] == 'u' || s[i] == 'U'))
          {
             vCount++;
          }
          else if((s[i] >= 'a' && s[i] < 'z') || (s[i] >= 'A' && s[i] < 'Z'))
          {
            cCount++;
          }
    }
    printf("vowels: %d, consonants: %d\n", vCount, cCount);
}

int main()
{
    char s[] = "Dinesh 210@##*@@(!_) KuMar 01";
    VandC(s);
    return 0;
}