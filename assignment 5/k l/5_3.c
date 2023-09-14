#include <stdio.h>
int sumrecursive(int n)//recursive function defination
{
	if(n==1)
	return 1;
	else
	return (n+sumrecursive(n-1));//recursive call
}
int main()
{
	int x;
	printf("Input the last number of the range starting from one: ");
	scanf("%d",&x);
	printf("The sum of numbers from 1 to %d: %d",x,sumrecursive(x));//function call
	return 0;
}
