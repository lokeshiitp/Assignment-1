#include<stdio.h>
#include<string.h>

int search(char[], char[]);

int main() {
   int loc1,loc2;

   char P[1000];
   char Q[1000];
   char R[1000];
   printf("enter string P:");
   gets(P);
   printf("enter string Q:");
   gets(Q);
   printf("enter string R:");
   gets(R);
   loc1 = search(P, Q);
   loc2= search(P,R);
   if (loc1 == -1||loc2==-1)
      printf("\nNot found");

   else
     {
       int lastQ;
       lastQ=loc1+strlen(Q)-1;
       if(loc2>loc1)
       {
           if((loc2-lastQ)>1)
            printf("\nQ*R starts at:%d",loc1);
           else
            printf("\nnot found");
       }
       else
        printf("\nnot found");

     }

   return (0);
}

int search(char src[1000], char str[1000])
{
   int i, j, firstOcc;
   i = 0, j = 0;

   while (src[i] != '\0') {

      while (src[i] != str[0] && src[i] != '\0')
         i++;

      if (src[i] == '\0')
         return (-1);

      firstOcc = i;

      while (src[i] == str[j] && src[i] != '\0' && str[j] != '\0') {
         i++;
         j++;
      }

      if (str[j] == '\0')
         return (firstOcc);
      if (src[i] == '\0')
         return (-1);

      i = firstOcc + 1;
      j = 0;
   }
}