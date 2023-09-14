#include <stdio.h>

int main()
{
    int n;
    printf("Write an integer n \n");
    scanf("%d", &n);
    int sum=(n*(n+1))/2;
    printf("The sum of series 1+2+3+4+....+n is %d\n", sum);
    
    return 0;
}
