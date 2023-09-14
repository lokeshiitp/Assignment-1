#include <stdio.h>
void main()
{  int n,s,a,d,f;
    printf(" .................");
    scanf("%d",&n);
    int data[n];
    printf("....................... \n");
    for (int i = 1; i <= n; i++)
        scanf("%d", data + i);
    for(int k=1;k<=n/2;k++)
            printf("%d\t",*(data+(n/2-k+1)));
    if(n%2!=0)
        printf("%d\t",*(data+(n/2+1)));
    for(int j=1;j<=n/2;j++)
            printf("%d\t",*(data+(n-j+1)));
}