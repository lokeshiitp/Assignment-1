// code for generate the power sets of given array

#include <math.h> 
#include <stdio.h> 

enum Type { INT, CHAR }; 
//Function to checking that character is digit or not 
int isDigit(char c) { return '0' <= c && c <= '9'; } 

//Function to checking that character is an alphabet or not 
int isAlpha(char c) { return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'); } 

//Function to ignoring all character of current line / 
void ignoreTillNewLine(FILE *in) { 
    while (getc(in) != '\n' && !feof(in)) 
    ;
    } 
    // Function to read array form the file to return whether input is in correct format. 
/* @param in FILE * 
* @param nums char * 
* @param nums_size char * 
* @param arr_type enum Type * 
* @return int */
int readArray(FILE *in, char *nums, int *nums_size, enum Type *arr_type) { 
    char c; 
    int i = 0; 
    
    if ((c = getc(in)) == '[') { // if first character of line starting  with '[' 
    
    c = getc(in); 
    // loop till end of array, line or file is reached 
    while (c != ']' && c != '\n' && !feof(in)) { 
                            // assing the type of numbers array 
    if (i == 0) {         // if numbers doesn't have any element yet 
    if (c == '\'') 
    *arr_type = CHAR; 
    else if (isDigit(c) || c == '-') 
    *arr_type = INT; 
    else { 
        if (c != '\n') ignoreTillNewLine(in); 
        return 0; 
        
    } 
        
    } 
    if (*arr_type == CHAR) {       // if array type is CHARACTER 
    c = getc(in); 
    if (isAlpha(c)) { 
        nums[i++] = c; 
        c = getc(in); 
        if (c != '\'') { 
            if (c != '\n') ignoreTillNewLine(in); 
            
        } 
        
    } else { 
        if (c != '\n') ignoreTillNewLine(in); 
        return 0; 
        
    } 
        
    } else {          // if array type is INTEGER 
    if (c == '-') { 
                            // MAX INT RANGE (-8<=nums[i]<=8)
        nums[i++] = -(getc(in) - '0'); 
        
    } else if (isDigit(c)) { 
        nums[i++] = c - '0'; 
        
    } else { 
        if (c != '\n') ignoreTillNewLine(in); 
        return 0; 
        
    } 
        
    } 
    c = getc(in); 
    if (c == ',') c = getc(in); 
    if (c == ' ') c = getc(in); 
        
    } 
    *nums_size = i; 
    ignoreTillNewLine(in); 
    return 1; 
        
    } 
    if (c != '\n') ignoreTillNewLine(in); 
    return 0; 
    
} /* * Function to print the Power Set of the nums array. 
* @param out FILE * 
* @param nums char * 
* @param nums_size int 
* @param type enum Type **/ 
void printPowerSet(FILE *out, char *nums, int nums_size, enum Type type) { 
    fprintf(out, "[[]"); 
    // loop from 1 to size of power set 
    for (size_t i = 1; i < pow(2, nums_size); i++) { 
        fprintf(out, ", ["); 
        for (int j = 0; j < nums_size; j++) { 
            if (i & (1 << j)) { // if jth bit of the 'i' is set 
            fprintf(out, (type == INT) ? "%d, " : "'%c', ", nums[j]); 
                
            } 
            
        } 
        fseek(out, -2, SEEK_CUR); 
        fprintf(out, "]"); 
        
    } 
    fprintf(out, "]\n"); 
    
} 
int main() { 
    FILE *in = fopen("input.txt", "r");      // open input file in read mode 
    FILE *out = fopen("output.txt", "w");   // open output file in write mode 
    
    char nums[7]; 
    int nums_size = 0; 
    enum Type arr_type; 
    
    while (!feof(in)) { 
        if (readArray(in, nums, &nums_size, &arr_type)) { 
            printPowerSet(stdout, nums, nums_size, arr_type); 
            printPowerSet(out, nums, nums_size, arr_type); 
            
        } else { 
            printf( "Error, input is not in correct format. Use [] with elements " "separated by, .E.g., [1, 2, 3]\n"); 
            fprintf( out, "Error, input is not in correct format. Use [] with elements " "separated by, .E.g., [1, 2, 3]\n"); 
            
        } 
        
    } 
    return 0; 
    
}