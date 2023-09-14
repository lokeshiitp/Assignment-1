#include<stdio.h>
void main()
{
    int size,i;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    if(size>0)
    {
        int arr[size];
        printf("Enter the integers\n");
        for(i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
        display(arr,size);
        search(arr,size);
        int s=make_unique(arr,size);
    }
    else
    printf("Invalid input\n");
}
void display(int arr1[],int size1)
{
    int i;
    printf("Array elements:\n");
    for(i=0;i<size1;i++)
    {
        printf("%d\t",arr1[i]);
    }
    printf("\n");
}
void search(int arr2[],int size2)
{
    int i,num,count=0;
    printf("Enter a number to search\n");
    scanf("%d",&num);
    for(i=0;i<size2;i++)
    {
        if(num==arr2[i])
        {
            printf("Element found in array with index = %d\n",i);
            count++;
        }
    }
    if(count==0)
    printf("Element not found\n");
}
int make_unique(int arr3[],int size3)
{
    int i,j,k,num,choice,count,flag,n=size3;
    begin:
    flag=1;
    printf("Enter 1 to remove duplicates of an element\n");
    printf("Enter 2 to display the current array\n");
    printf("Enter 3 to exit the program\n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        printf("Enter a number to remove its duplicate entries\n");
        scanf("%d",&num);
        count=0;
        for(i=0;i<n;i++)
        {
            if(arr3[i]==num)
            count++;
        }
        if(count>1)
        {
            for(i=n-1;i>=0;i--)
            {
                if(count>1)
                {
                    if(arr3[i]==num)
                    {
                        for(k=i;k<size3-1;k++)
                        {
                            arr3[k]=arr3[k+1];
                        }
                    n--;
                    count--;
                    }
                }
            }
            display(arr3,n);
            goto begin;
        }
        else
        {
            printf("No duplicate entry found\n");
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(arr3[i]==arr3[j])
                {
                    flag=0;
                    goto begin;
                }
            }
        }
        if(flag==1)
        printf("The array is unique, there are no repeating elements present\n");
        break;
        case 2:
        display(arr3,n);
        goto begin;
        case 3:
        goto end;
        default:
        printf("Invalid choice\n");
        goto begin;
        end:
        return 0;
    }
}