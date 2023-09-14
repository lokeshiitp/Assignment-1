#include <stdio.h>

int main()
{
    int radius;
    float pi = 3.14;
    printf("enter radius \n");
    scanf("%d", &radius);

    printf("the area is %f\n", pi * radius * radius);
    return 0;

}