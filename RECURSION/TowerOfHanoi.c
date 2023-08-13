#include<stdio.h>

void TOH(int disks, int fromRod, int usingRod, int toRod)
{
    if(disks > 0)
    {
         TOH(disks - 1, fromRod,toRod,usingRod);
         printf("%d to %d\n", fromRod, toRod);
         TOH(disks - 1, usingRod,fromRod,toRod);
    }
}

int main()
{
    TOH(3,1,2,3);
    return 0;
}