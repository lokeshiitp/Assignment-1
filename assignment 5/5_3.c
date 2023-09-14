#include <stdio.h>

int sum(int x)   //function declaration
{
    if(x!=0)
    return x+sum(x-1); //calling function within function
    else
    return x;   
}                   // end of function
int main() 
{
    int n=0;
    printf("input last number of range starting from 1 \n"); 
    scanf("%d",&n);       //accepting input from user
    int total = sum(n);
    printf("sum of numbers from 1 to %d is %d" ,n,total);   //output 
}