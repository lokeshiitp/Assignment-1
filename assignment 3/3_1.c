/* Q=1, program to take a matrix A of order m*n as input 
and find all elements A[i][j] such that it, is smallest
 in the ith row and largest in the jth column.*/

#include<stdio.h>
void main()
{
	int  m,n,i,j,k,p,r,c;
	int flag=1;
	double s,l;
	printf("Enter the number of rows\n");
	scanf("%d",&m);
	printf("Enter the number of columns\n");
	scanf("%d",&n);
	float A[m][n];
	for(i=0;i<m;i++)
	{
		if(i==0)
		printf("Enter the 1st row\n");
		else if(i==1)
		printf("Enter the 2nd row\n");
		else if(i==2)
		printf("Enter the 3rd row\n");
		else
		printf("Enter the %dth row\n",i+1);
		for(j=0;j<n;j++)
		{
			scanf("%f",&A[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		flag=1;
		s=A[i][0];
		l=A[i][0];
		r=i+1;
		c=1;
		for(j=0;j<n;j++)
		{
			if(s>A[i][j])
			{
				s=l=A[i][j];
				c=j+1;
			}
		}	
		for(k=0;k<m;k++)
		{
			if(l<A[k][c-1])
			flag=0;
		}
		if(flag==1)
		printf("The element in row %d and column %d which is %f is such an element that is smallest in ith row and largest in jth column\n",r,c,l);
	}
	if(flag==0)
	printf("There is no such element that is smallest in ith row and largest in jth column\n");
}						
