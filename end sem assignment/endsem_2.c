#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n, count;
    count=0;
    system("clear");
    FILE *fp;
    char data[8];
    fp=fopen(argv[1], "r");     //Opening the file in read mode
    if(argc != 2)              //Checking for proper number of arguments
    {
        printf("Invalid Argument\n");
        exit(1);
    }
    if(fp == NULL)       //Checking file is present or not
        printf("Unable to open target file\n");
    else
        {
            int pos=0;
            fseek(fp, 0L, SEEK_END);         //Places the pointer at the end of file
            int s=ftell(fp);                //Store the length of string present in file
            while(1)
            {
                n=(rand()-(RAND_MAX/2))%s;     //Taking the remainder when divided by length of string present in file in order to have a random number randing from -ve length to +ve length
                fseek(fp, pos, SEEK_SET);
                fgets(data, 8, fp);
                if(strcmp(data,"diamond") == 0)
                {
                    printf("Diamond found at Index %d in %d moves\n", pos, count);
                    fclose(fp);      //for Closing the file
                    exit(1);
                }
                if((pos+n) < s-7 && (pos+n) >= 0)   //Checking whether the move is within file's limit or not
                {
                    pos=pos+n;
                    count++;
                }
                else
                    continue;
            }
        }
    return 0;
}