#include <stdio.h>
#include <math.h>

int main()
{   
    //Part a) of the question.
    int n;
    //Taking the size of the array from the user.
    printf("Enter the value of size of the array you want to create: \n");
    scanf("%d", &n);
    int arr[n];

    printf("Now enter the elements of the array: \n");
    //Taking the elements of the array from the user using a for loop.
    for (int i = 0; i < n; i++)
    {
        int array_element;
        scanf("%d", &array_element);
        //Checking if the element is unique or not.
        for (int j = 0; j < i; j++)
        {
            if (array_element == arr[j])
            {
                printf("Sorry!! please input only unique elements.");
            }
        }
        scanf("%d", &arr[i]);
    }

    int low = 0, high = n - 1;

    while (low < high)
    {
        //Creating a temperary variable to reverse the array.
        int temp;
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }

    //Printing the reversed array.
    printf("The revesed array is as follows:\n ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    //Part b) of the question
    int l, r, minimum_sum, sum, minimum_l, minimum_r;

    minimum_l = 0;
    minimum_r = 1;
    minimum_sum = arr[0] + arr[1];

    for (l = 0; l < n - 1; l++)
    {
        for (r = l + 1; r < n; r++)
        {
            sum = arr[l] + arr[r];
            if (abs(minimum_sum) > abs(sum))
            {
                minimum_sum = sum;
                minimum_l = l;
                minimum_r = r;
            }
        }  
    }

    printf("The two elements with the minimum sum are %d %d.\n", arr[minimum_l], arr[minimum_r]);

    return 0;
}