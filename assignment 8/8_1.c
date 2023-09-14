#include <stdio.h>
#include <stdlib.h>

int prefix(char s1[1000],char s2[1000] )        // function declaration of strings for prefix
{
    int count=0;
    
    for(int i=0;s2[i]!='\0';i++)
    {
        if(s1[i]!=s2[i])
            return -1;
        else
            count++;
    }
    if(count!=0)
        return 1;
}
int compare(char s1[1000],char s2[1000])          // function declaration of strings for compare

{ int count=0;
  for(int i=0;s1[i]!='\0'&&s2[i]!='\0';i++)
  {
      if(s1[i]>s2[i])
        return 1;
      else if(s1[i]<s2[i])
        return -1;
      else
      count++;
  }
  if(count!=0)
    return 0;
}
int substring(char src[1000], char str[1000]) // a function to search if s2 is substring of s1 or not
{
   int i, j, firstOcc;
   i = 0, j = 0;

   while (src[i] != '\0') { // a loop to check the first occurrence

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
         return (firstOcc);// returning the first occurrence if found
      if (src[i] == '\0')
         return (-1);// returning -1 as it first occurrence is not found.

      i = firstOcc + 1;
      j = 0;
   }
}
int main()                        // main function declaration
{
    char choice,loc,value;
    char s1[1000],s2[1000];

    printf("enter the choice a,b,c:");
    scanf("%c",&choice);

    char dummy;
    scanf("%c", &dummy);
   
    switch(choice)
    {
        case 'a':printf("Compare the strings");

          printf("\n Enter string s1:");
          scanf(" %[^\n]",s1);
         
          printf("\n Enter string s2:");
          scanf(" %[^\n]",s2);

          value=compare(s1,s2);
          
          if(value==0)
          printf("string s1 and s2 are equal");
          
          else if(value>0)
            printf("string s1>string s2");
         
          else
            printf("string s1<string s2");

          break;

        case 'b':printf("To check if s2 is prefix of s1 or not");

          printf("\n Enter string s1:");
          scanf(" %[^\n]",s1);
         
          printf("\n Enter string s2:");
          scanf(" %[^\n]",s2);
          
          value=prefix(s1,s2);
          
          if(value==1)
          printf("string s2 is prefix of string s1");
         
          else
            printf("string s2 is not prefix of s1");
       
        break;

        case 'c':printf("To check if s2 is substring of s1 or not");
        printf("\n Enter string s1:");
          scanf(" %[^\n]",s1);
          printf("\n Enter string s2:");
          scanf(" %[^\n]",s2);

        loc=substring(s1,s2);

        if(loc==-1)
        printf("The string s2 is not a substring of s1");

        else
            printf("The s2 is found at %d in s1",loc);

        break;
       
        default:printf("Please enter the choice among a,b and c");
    }
}