#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include <math.h>


void PUSH (long val, long stack[], int p){  //elemento,stack,indice
    stack[p] = val;

}

long POP (long stack[], int p){

    return (stack[p]);
}

void print_stack(long stack[],int p){
    for(int i=0;i<p;i++){
             printf ("%ld", stack[i]);
        }
        printf("\n");
}


void parser (char *line){ 
    long stack[10240];
    int p=0;     
    char *limits = " \t\n";
    for (char *token = strtok(line,limits); token != NULL; token = strtok(NULL, limits)) { // everytime there's a " ", "\t" or "\n" the elements in between are saved as tokens
        char *rem;
        long val_i = strtol(token, &rem, 10); // strtol is used to find INT's on the input 
        if (strlen(rem) == 0){
           PUSH(val_i,stack,p);
           p++;
        } 
        else if (strcmp(token, "+") == 0){
                p--;
                long y = POP(stack,p);
                p--;
                long x = POP(stack,p);
                PUSH(x+y,stack,p);
                p++;
        }
        else if (strcmp(token, "-") == 0){
                p--;
                long x = POP(stack,p);
                p--;
                long y = POP(stack,p);
                PUSH (y-x,stack,p);
                p++;
        }
        else if (strcmp(token, "*") == 0){
                p--;
                long x = POP(stack,p);
                p--;
                long y = POP(stack,p);
                PUSH (y*x,stack,p);
                p++;
        } 
        else if (strcmp(token, "/") == 0){
                p--;
                long x = POP(stack,p);
                p--;
                long y = POP(stack,p);
                PUSH (y/x,stack,p);
                p++;
        }
        else if (strcmp(token, "(") == 0){
                p--;
                long x = POP(stack,p);
                PUSH (x-1,stack,p);
                p++;
        }
        else if (strcmp(token, ")") == 0){
                p--;
                long x = POP(stack,p);
                PUSH (x+1,stack,p);
                p++;
        }
        else if (strcmp(token, "&") == 0){
                p--;
                long x = POP(stack,p);
                p--;
                long y =POP(stack,p);
                PUSH (x&y,stack,p);
                p++;
        }
        else if (strcmp(token, "|") == 0){
                p--;
                long x = POP(stack,p);
                p--;
                long y = POP(stack,p);
                PUSH (x|y,stack,p);
                p++;
        }
        else if (strcmp(token, "%") == 0){
                p--;
                long x = POP(stack,p);
                PUSH(abs(x),stack,p);
                p++;
        }
        else if (strcmp(token, "^") == 0){
                p--;
                long x = POP(stack,p);
                p--;
                long y = POP(stack,p);
                PUSH (x^y,stack,p);
                p++;
        }
        else if (strcmp(token, "~") == 0){
                p--;
                long x = POP(stack,p);
                PUSH (~x,stack,p);
                p++;
        }
        else if (strcmp(token, "#") == 0){
                p--;
                long x = POP(stack,p);
                p--;
                long y = POP(stack,p);
                PUSH (pow(x,y),stack,p);
                p++;
        }
    }  
    print_stack(stack,p);
}    
