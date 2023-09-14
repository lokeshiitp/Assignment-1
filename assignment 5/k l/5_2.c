#include <stdio.h>
#include <math.h>


/* Function declarations */
int reverse(int n);
int isPalindrome(int n);



int main()
{
    int n;     // n== any integer number

    /* Input any number from user */
    printf("Enter any number: ", n);
    scanf("%d", &n);

    if(isPalindrome(n) == 1)
    {
        printf("%d is palindrome number.\n", n);
    }
    else
    {
        printf("%d is NOT palindrome number.\n", n);
    }

    return 0;
}



/**
 * Function to check whether a number is palindrome or not.
 * This function returns 1 if the number is palindrome otherwise 0.
 */
int isPalindrome(int n)
{
    /*
     * Check if the given number is equal to
     * its reverse.
     */
    if(n == reverse(n))
    {
        return 1;
    }

    return 0;
}


/**
 * Recursive function to find reverse of any number
 */
int reverse(int n)
{
    /* Find number of digits in n(number) */
    int digit = (int)log10(n);

    /* Recursion base condition */
    if(n == 0)
        return 0;

    return ((n%10 * pow(10, digit)) + reverse(n/10));
}
