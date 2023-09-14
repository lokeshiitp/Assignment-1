#include <stdio.h>

int decimal_binary(int a)         //decimal to binary
{
    if (a==0)                  // for a=0 binary will be o
        return 0;
    else
        return ((a%2)+10*decimal_binary(a/2));     // for other integer numbers 
}

void main()
{
   int n;

   printf("Enter a decimal number\n");
   scanf("%d",&n);
   printf("Decimal(%d) = Binary(%d)\n",n,decimal_binary(n));
}
