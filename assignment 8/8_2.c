#include<stdio.h>
#define max 500
int compare(char s1[], char s2[]);     // function declaration for comaring s1 and s2
int prefix(char s1[], char s2[], int d);  //function declaration for checking prefix
int substring(char s1[], char s2[], int l);  // function declaration for substring 
void main()
{
    int res, c, i=0, l1=0, l2=0;
    char choice;
    char str1[max];
    char str2[max];
    puts("Enter string 1");
    gets(str1); //inputs str1
    puts("Enter string 2");
    gets(str2); //inputs str2
    printf("Enter:\na to Compare strings\nb to Check for Prefix\nc for Substring matching\n");
    scanf("%c",&choice);
    switch(choice)  //proceeds according to the choice of user
    {
        case 'a':
            res=compare(str1, str2);
            if(res == 1)
                printf("String 1 is greater than String 2\n");
            else if(res == -1)
                printf("String 1 is lesser than String 2\n");
            else
                printf("String 1 and String 2 are equal\n");
            break;
        case 'b':
            for(int p=0; str1[p]!='\0';p++)
            {
                l1++;
            }
            for(int p=0; str2[p]!='\0';p++)
            {
                l2++;
            }
            res=prefix(str1, str2, l1-l2);
            if(res == 1)
                printf("String 2 is a prefix of String 1\n");
            else
                printf("String 2 is not a prefix of String 1\n");
            break;
        case 'c':
            res=substring(str1, str2, 0);
            if(res == -1)
                printf("String 2 is not a substring of String 1\n");
            else
                printf("String 2 is a substring of String 1 found at Index: %d\n",res);
            break;
        default:
            printf("Invalid choice\n");
    }
}
int compare(char s1[], char s2[])   //recursive fUNCTION which compares string s1 and s2
{
    static int i=0;
    if(s1[i] != '\0')   //keeps comparing until s1 is exhausted
    {
        if(s1[i] > s2[i])
            return 1;
        else if(s1[i] < s2[i])
            return -1;
        else
        {
            i++;
            compare(s1, s2);
        }
        
    }
    else   
        return 0;
}
int prefix(char s1[], char s2[], int d)    //recursive fUNCTION which checks whether string s2 is prefix of s1 or not
{
    if(d < 0)
        return -1;
    static int j=0;
    if(s2[j] != '\0' || s1[j] != '\0')  //checks if either of the strings have ended or not
    {
        if(s1[j] == s2[j])
        {
            j++;
            prefix(s1, s2, d);
        }
        else
            return -1;
    }
    return 1;
}
int substring(char *s1, char *s2, int l)    //recursive fUNCTION which checks whether s2 is substring of s1 or not and returns the index if found
{
    static int i=0;
    int j=0;
    if(*s1 =='\0' && *s2 != '\0')   
        return -1;
    if(*s2 == '\0')
        return l;
    if(*s1 == *s2)
    {
        i++;
        return substring(s1+1, s2+1, l);
    }
    if(i != 0)
        j=i;
    i=0;
    return substring(s1+1-j, s2-j, l+1);
}