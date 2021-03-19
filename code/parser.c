#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

void parser (char *line){
    char *limits = " \t\n";
    for (char *token = strtok(line,limits); token != NULL; token = strtok(NULL, limits)) { // if everytime there's a " ", "\t" or "\n" the elements in between are saved as tokens
        char *rem;
        long val_i = strtol(token, &rem, 10); // strtol is used to find INT's on the input 
        if (strlen(rem) == 0){
           PUSH(val_i); 
        } 
        else if (strcmp(token, "+") == 0){ // 
                long y = POP();
                long x = POP();
                PUSH(x + y);
        }
        else if (strcmp(token, "-") == 0){
                long x = POP();
                long y = POP();
                PUSH (x - y);    
        }
        else if (strcmp(token, "*") == 0){
                long x = POP();
                long y = POP();
                PUSH (x * y);    
        } 
        else if (strcmp(token, "/") == 0){
                long x = POP();
                long y = POP();
                PUSH (x / y);
        }
        else if (strcmp(token, "(") == 0){
                long x = POP();
                PUSH (x-1);
        }
        else if (strcmp(token, ")") == 0){
                long x = POP();
                PUSH (x+1);
        }   
    PRINT_STACK();
}