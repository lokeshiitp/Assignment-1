//Q=3,program to count the number of 1s in the binary representation of an integer.//

//To count the number of set bits(those that are 1) in binary representation of an integer.//

#include <stdio.h>
int main(){
    int n;
    //Taking input from the user.//
    printf("Please enter an integer: ");
    scanf("%d", &n);
    if (n>0) {
        
        int c = 0;
        //Running while loop till n>0.//
        while (n > 0) {
            
            c += n & 1;
            
            n =n >> 1;
        }
        // Printing the number of 1s.//
        printf("Numbers of 1s are: %d\n", c);
    } 
    //In case of error that is a negetive number is entered.//
    else {
        printf("Eror! Please enter positive integer only.\n");
    }
    return 0;
}						
