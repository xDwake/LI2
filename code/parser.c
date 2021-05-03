/**
 * @file parser.c 
 * \brief Funções auxiliares do programa.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"
#include "auxiliar.h"
#include "guiao4.h"
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
    STACK *var = create_stack();
    fill_var(var);
    char *limits = " \t\n";
    for (char *token = strtok(line,limits); token != NULL; token = strtok(NULL, limits)) { // everytime there's a " ", "\t" or "\n" the elements in between are saved as tokens
        char *rem;
        double val_d = strtod(token,&rem);
        long val_i = strtol(token, &rem, 10); // strtol is used to find INT's on the input
        if (strlen(rem) == 0){
           push_LONG(s,val_i);
        }
        else if (is_adletterA_M(token)){
          choose_adletterA_M(s,var,token);
        }
        else if (is_adletterN_Z(token)){
          choose_adletterN_Z(s,var,token);
        }
        else if (is_elogic(token)){
          choose_elogic(s,token);
        }
        else if (itoc(token)) {
          choose_ooc(s,var,token);
        }
        else if (is_double(token)){
          push_DOUBLE(s,val_d);
        } 
        else if (is_string(token,'\"') || token[strlen(token)-1]=='\"'){
          get_string(s,token);
        }
        else push_STRING(s,token);
    }  
    print_stack(s);
}