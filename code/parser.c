/**
 * @file Funções auxiliares do programa.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"
#include <math.h>

/**
 * \brief Função que recebe os inputs do utilizador e realiza as operações em conformidade.
 * 
 * Esta função separa os inputs por espaços, tabs ou mudanças de linha, e para a realização do guião 1 apenas realiza as operações
 * matemáticas com os inputs da forma estipulada pelo enunciado.
 * 
 * @param line A linha de inputs que foi lida.
 */ 
void parser (char *line){ 
    long stack[10240];
    int p=0;     
    char *limits = " \t\n";
    for (char *token = strtok(line,limits); token != NULL; token = strtok(NULL, limits)) { // everytime there's a " ", "\t" or "\n" the elements in between are saved as tokens
        char *rem;
        long val_i = strtol(token, &rem, 10); // strtol is used to find INT's on the input 
        if (strlen(rem) == 0){
           PUSH(val_i,stack,&p);
        } 
        else if (strcmp(token, "+") == 0){
                long y = POP(stack,&p);
                long x = POP(stack,&p);
                PUSH(x+y,stack,&p);
                
        }
        else if (strcmp(token, "-") == 0){
                long x = POP(stack,&p);
                long y = POP(stack,&p);
                PUSH (y-x,stack,&p);
                
        }
        else if (strcmp(token, "*") == 0){
                long x = POP(stack,&p);
                long y = POP(stack,&p);
                PUSH (y*x,stack,&p);
                
        } 
        else if (strcmp(token, "/") == 0){
                long x = POP(stack,&p);
                long y = POP(stack,&p);
                PUSH (y/x,stack,&p);
                
        }
        else if (strcmp(token, "(") == 0){
                long x = POP(stack,&p);
                PUSH (x-1,stack,&p);
                
        }
        else if (strcmp(token, ")") == 0){
                long x = POP(stack,&p);
                PUSH (x+1,stack,&p);
                
        }
        else if (strcmp(token, "&") == 0){
                long x = POP(stack,&p);
                long y =POP(stack,&p);
                PUSH (x&y,stack,&p);
                
        }
        else if (strcmp(token, "|") == 0){
                long x = POP(stack,&p);
                long y = POP(stack,&p);
                PUSH (x|y,stack,&p);
                
        }
        else if (strcmp(token, "%") == 0){
                long x = POP(stack,&p);
                long y = POP(stack,&p);
                PUSH (y%x,stack,&p);
                
        }
        else if (strcmp(token, "^") == 0){
                long x = POP(stack,&p);
                long y = POP(stack,&p);
                PUSH (x^y,stack,&p);
                
        }
        else if (strcmp(token, "~") == 0){
                long x = POP(stack,&p);
                PUSH (~x,stack,&p);
                
        }
        else if (strcmp(token, "#") == 0){
                long x = POP(stack,&p);
                long y = POP(stack,&p);
                PUSH (pow(y,x),stack,&p);
                
        }
    }  
    print_stack(stack,p);
}    
