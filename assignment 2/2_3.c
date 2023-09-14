#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num,a,b,c;
    printf("Enter a 3 digit number:");
    scanf("%d",&num);
    if(num>99 && num<1000)
    {
        a=num%10;
        b=((num-a)%100)/10;
        c=num/100;
        printf("output:");
        printf("%d",a);
        printf("%d",b);
        printf("%d",c);
    }
    else
    {
        printf("\nThe number entered is not 3 digit!\nPlease enter a 3 digit number");
    }
    return 0;
}