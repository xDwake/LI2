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
        double val_d = strtod(token,&rem);
        long val_i = strtol(token, &rem, 10); // strtol is used to find INT's on the input
        if (strlen(rem) == 0){
           push_LONG(s,val_i);
        } 
        else if (strcmp(token, "+") == 0){
                if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),LONG)){
                        long x = pop_LONG(s);
                        long y = pop_LONG(s);
                        push_LONG(s,y+x);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
                        double x = pop_DOUBLE(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,y+x);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
                        double x = pop_DOUBLE(s);
                        long y = pop_LONG(s);
                        push_DOUBLE(s,y+x);
                }
                else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
                        long x = pop_LONG(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,y+x);
                } 
        }
        else if (strcmp(token, "-") == 0){
                if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),LONG)){
                        long x = pop_LONG(s);
                        long y = pop_LONG(s);
                        push_LONG(s,y-x);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
                        double x = pop_DOUBLE(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,y-x);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
                        double x = pop_DOUBLE(s);
                        long y = pop_LONG(s);
                        push_DOUBLE(s,y-x);
                }
                else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
                        long x = pop_LONG(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,y-x);
                }     
        }
        else if (strcmp(token, "*") == 0){
                if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),LONG)){
                        long x = pop_LONG(s);
                        long y = pop_LONG(s);
                        push_LONG(s,y*x);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
                        double x = pop_DOUBLE(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,y*x);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
                        double x = pop_DOUBLE(s);
                        long y = pop_LONG(s);
                        push_DOUBLE(s,y*x);
                }
                else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
                        long x = pop_LONG(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,y*x);
                }     
        } 
        else if (strcmp(token, "/") == 0){
                if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),LONG)){
                        long x = pop_LONG(s);
                        long y = pop_LONG(s);
                        push_LONG(s,y/x);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
                        double x = pop_DOUBLE(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,y/x);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
                        double x = pop_DOUBLE(s);
                        long y = pop_LONG(s);
                        push_DOUBLE(s,y/x);
                }
                else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
                        long x = pop_LONG(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,y/x);
                }     
        }
        else if (strcmp(token, "(") == 0){
                if (has_type((get_elem(s,0)),LONG)){
                        long x = pop_LONG(s);
                        push_LONG(s,x-1);
                }
                else if(has_type((get_elem(s,0)),DOUBLE)){
                        double x = pop_DOUBLE(s);
                        push_DOUBLE(s,x-1);
                } 
        }
        else if (strcmp(token, ")") == 0){
                if (has_type((get_elem(s,0)),LONG)){
                        long x = pop_LONG(s);
                        push_LONG(s,x+1);
                }
                else if(has_type((get_elem(s,0)),DOUBLE)){
                        double x = pop_DOUBLE(s);
                        push_DOUBLE(s,x+1);
                }            
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
                if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),LONG)){
                        long x = pop_LONG(s);
                        long y = pop_LONG(s);
                        push_LONG(s,pow(y,x));
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
                        double x = pop_DOUBLE(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,pow(y,x));
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
                        double x = pop_DOUBLE(s);
                        long y = pop_LONG(s);
                        push_DOUBLE(s,pow(y,x));
                }
                else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
                        long x = pop_LONG(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,pow(y,x));
                }     
        }
        else if (strcmp(token, "_") == 0){
                push(s,get_elem(s,0));
        }
        else if (strcmp(token, ";") == 0){
                pop(s);
        }
        else if (strcmp(token, "\\") == 0){
                if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),LONG)){
                        long x = pop_LONG(s);
                        long y = pop_LONG(s);
                        push_LONG(s,x);
                        push_LONG(s,y);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
                        double x = pop_DOUBLE(s);
                        double y = pop_DOUBLE(s);
                        push_DOUBLE(s,x);
                        push_DOUBLE(s,y);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
                        double x = pop_DOUBLE(s);
                        long y = pop_LONG(s);
                        push_DOUBLE(s,x);
                        push_LONG(s,y);
                }
                else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
                        long x = pop_LONG(s);
                        double y = pop_DOUBLE(s);
                        push_LONG(s,x);
                        push_DOUBLE(s,y);
                }     
        }
        else if (strcmp(token, "@") == 0){
                if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),LONG) && has_type((get_elem(s,1)),LONG)){
                        long x = pop_LONG(s);
                        long y = pop_LONG(s);
                        long z = pop_LONG(s);
                        push_LONG(s,y);
                        push_LONG(s,x);
                        push_LONG(s,z);
                }
                else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
                        double x = pop_DOUBLE(s);
                        double y = pop_DOUBLE(s);
                        double z = pop_DOUBLE(s);
                        push_DOUBLE(s,y);
                        push_DOUBLE(s,x);
                        push_DOUBLE(s,z);
                } // poderá ser preciso meter mais 6 condições
        }
        else if (strcmp(token, "$") == 0){
                long x = pop_LONG(s);
                push(s,get_elem(s,x));
        } 
        else if (strcmp(token, "c") == 0){
                if (has_type((get_elem(s,0)),LONG)){
                        long x = pop_LONG (s);
                        push_CHAR (s,(char)x);
                }
                else if (has_type((get_elem(s,0)),DOUBLE)){
                        double x = pop_DOUBLE (s);
                        push_CHAR (s,(char)x);
                }
                /*else if (has_type((get_elem(s,0)),STRING)){ // ---> dont know yet 
                        char *x = pop_STRING (s);
                        push_CHAR (s,y);
                }*/
                
        }
        else if (strcmp(token, "i") == 0){
                if (has_type((get_elem(s,0)),DOUBLE)) {
                        double x = pop_DOUBLE (s);
                        push_LONG (s,(long) x);
                }
                else if (has_type((get_elem(s,0)),CHAR)){
                        char x = pop_CHAR (s);
                        push_LONG (s,(long)x);
                }
                else if (has_type((get_elem(s,0)),STRING)){
                        char *x = pop_STRING (s);
                        long y = atol(x);
                        push_LONG (s,y);
                }
        }
        else if (strcmp(token,"f") == 0){
                if (has_type((get_elem(s,0)),LONG)) {
                        long x = pop_LONG (s);
                        push_DOUBLE (s,(double)x);
                }
                else if (has_type((get_elem(s,0)),CHAR)) {
                        char x = pop_CHAR (s);
                        push_DOUBLE (s,(double)x);
                }
                else if (has_type((get_elem(s,0)),STRING)) {
                        char *x = pop_STRING (s);
                        double y = atof (x);
                        push_DOUBLE (s,y);
                }
        }
        /*else if (strcmp(token,'s') == 0){
                if (has_type((get_elem(s,0)),LONG)) {
                        long x = pop_LONG (s);
                        
                }
                else if (has_type((get_elem(s,0)),DOUBLE)) {
                        double x = pop_DOUBLE(s);
                        double c = 
                        
                }
        }*/
        else push_DOUBLE (s,val_d);
    }  
    print_stack(s);
}