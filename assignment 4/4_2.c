#include <stdio.h>

float Power(int m,int n);   //declaring function Power

int main()              //main function
{
    int m,n; float ans;         //declaring variables
    printf("Enter the values of m and n respectively:\n");
    scanf("%d%d",&m,&n);
    ans=Power(m,n);     //this calls the function Power by passing parameters(m and n) and stores its return value in variable ans.
    printf("The value of %d raised to power %d: %lf",m,n,ans);
    return 0;
}
//function Power definition
float Power(int m, int n)     
{
    float ans=1.0;
    int t=n;
    if(t<0)         //if n is negative it converts it into positive
     {
        t=t*(-1);
        for(int i=1;i<=t;i++)  //this loop raises the power of m by n
        ans=ans*m;
        ans=1/(ans);
     }
    else
     {
      for(int i=1;i<=t;i++)      //this loop raises the power of m by n
        ans=ans*m;  
     }
    if (m==0 && n==0){     //0^0 case
        printf("undefined");
    }
    else if(m==0 && n<0){    // 1/(0^x)
        printf("undefined");
    }
    return ans;     //returns ans to its call
}    