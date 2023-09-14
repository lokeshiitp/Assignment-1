#include <stdio.h>

int main()
{
   int n,gap=1;
   scanf("%d",&n);
   for(int i=n;i>0;i=i-2)
   {
       for(int j=1;j<gap;j++)
       {
           printf(" ");
       }
       for(int j=1;j<=i;j++)
       {
           printf("*");
       }
       printf("\n");
       gap++;
       
   }

    return 0;
}