#include<stdio.h>

int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int sum=(n*(n+1)*(2*n+1))/6;
    printf("sum of square of n numbers is %d\n",sum);
    return 0;
}