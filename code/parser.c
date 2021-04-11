/**
 * @file parser.c 
 * \brief Funções auxiliares do programa.
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
    STACK *s = create_stack();
    char *limits = " \t\n";
    for (char *token = strtok(line,limits); token != NULL; token = strtok(NULL, limits)) { // everytime there's a " ", "\t" or "\n" the elements in between are saved as tokens
        char *rem;
        long val_i = strtol(token, &rem, 10); // strtol is used to find INT's on the input 
        if (strlen(rem) == 0){
           push_LONG(s,val_i);
        } 
        else if (strcmp(token, "+") == 0){
                long y = pop_LONG(s);
                long x = pop_LONG(s);
                push_LONG(s,y+x);
                
        }
        else if (strcmp(token, "-") == 0){
                long x = pop_LONG(s);
                long y = pop_LONG(s);
                push_LONG(s,y-x);
                
        }
        else if (strcmp(token, "*") == 0){
                long x = pop_LONG(s);
                long y = pop_LONG(s);
                push_LONG(s,y*x);
                
        } 
        else if (strcmp(token, "/") == 0){
                long x = pop_LONG(s);
                long y = pop_LONG(s);
                push_LONG(s,y/x);
                
        }
        else if (strcmp(token, "(") == 0){
                long x = pop_LONG(s);
                push_LONG(s,x-1);
                
        }
        else if (strcmp(token, ")") == 0){
                long x = pop_LONG(s);
                push_LONG(s,x+1);
                
        }
        else if (strcmp(token, "&") == 0){
                long x = pop_LONG(s);
                long y = pop_LONG(s);
                push_LONG(s,x&y);
                
        }
        else if (strcmp(token, "|") == 0){
                long x = pop_LONG(s);
                long y = pop_LONG(s);
                push_LONG(s,x|y);
                
        }
        else if (strcmp(token, "%") == 0){
                long x = pop_LONG(s);
                long y = pop_LONG(s);
                push_LONG(s,y%x);
                
        }
        else if (strcmp(token, "^") == 0){
                long x = pop_LONG(s);
                long y = pop_LONG(s);
                push_LONG(s,x^y);
                
        }
        else if (strcmp(token, "~") == 0){
                long x = pop_LONG(s);
                push_LONG(s,~x);
                
        }
        else if (strcmp(token, "#") == 0){
                long x = pop_LONG(s);
                long y = pop_LONG(s);
                push_LONG(s,pow(y,x));
                
        }
    }  
    print_stack(s);
}