#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_LENGTH 50     //maximum length of the file
char* getLine(char* loc, FILE* fileStream);  // gets word for pattern search in given file.
int checkStringMatch(char* Search, char* pattern);// checks if the string contains the search pattern.
char* switchToLower(char* string);    //switches to lower case of the string.
void printLine(int linenum, char* fn, char* text);    // Prints the given line with line number if nonzero.file name(fn)
void processFile(char* fn, char* pattern );    // prints the line in the file that contains the search pattern 
int checkOptions(char** argv);

    int optiona = 0;
    int optionb = 0;

    int main(int argc, char**argv)
    {
        if(argc < 3)
        {
            fputs("Write the search pettern and file name:", stderr);
            return 1;
        }
        int numOptions = checkOptions(argv);

        char* pattern = argv[numOptions+ 1];

        if(optionb)
        {
            pattern = switchToLower(pattern);//pattern changes to lower case if '-b' is used
        }
        int i;
        for(i=numOptions + 2; i < argc; i++)
        {
            char* fn = argv[i];
            processFile(fn, pattern);         
        }
        if(optionb)
        {
            free(pattern);//print the pattern
        }
        return 0;
    }

    int checkOptions(char** argv)
    {
        int numOptions = 0;
        if(checkStringMatch(argv[1], "-a") || checkStringMatch(argv[2], "-a"))
        {
            optiona = 1;
            numOptions++;
        }
        if(checkStringMatch(argv[1], "-b") || checkStringMatch(argv[2], "-b"))
        {
            optionb = 1;
            numOptions++;
        }       
        return numOptions;
    }
    void processFile(char* fn, char* pattern)
    {
        FILE* f = fopen(fn, "T");
        if(!f)       //if file does not exist print error
        {
            fprintf(stderr, "File %s unopenable.\n", fn);
            return;
        }
        char* line = (char*)malloc(MAX_LENGTH*sizeof(char)); 
        int linenum = 1;                         
        while(!feof(f))
        {                       
            line = getLine(line, f);
            if(line)         //proceed if line is not empty
            {
                if(optionb)
                {
                    char* lowerLine = switchToLower(line);
                    if(checkStringMatch(lowerLine, pattern))
                    {
                        printLine(linenum*optiona, fn, line);
                    }
                    free(lowerLine);                                 
                }
                else
                {
                    if(checkStringMatch(line, pattern))
                    {
                        printLine(linenum*optiona, fn, line);
                    }
                }
                    linenum++;
            }    
        }
            fclose(f);       //if line is empty 
            free(line);
    }
    char* getLine(char* loc, FILE* fileStream)
    {
        return fgets(loc, MAX_LENGTH, fileStream);
    }
    int checkStringMatch(char* Search, char* pattern)
    {       
        char* exists = strstr(Search, pattern);
        if(exists)
        {
            return 1;
        }
        return 0;
    }
    char* switchToLower(char* str)
    {       
        char* newString = (char*)malloc(sizeof(char)*strlen(str));
        int i;
        for(i = 0; str[i]; i++)
        {
            newString[i]=tolower(str[i]);           
        }
        return newString;
    }
    void printLine(int linenum, char* fn, char* text)
    {
        if(linenum)
        {               
            printf("%d%s%s", linenum, fn, text);
        }
        else
        {
            printf("%s%s", fn, text);
        }
    }