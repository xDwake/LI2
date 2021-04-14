/**
 * @file parser.c 
 * \brief Funções auxiliares do programa.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"
#include "auxiliares.h"
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
        else if(strcmp (token, "-") == 0) {
          choose_subtrai (s);
        }   
        else switch (*token){
                case '+':
                  choose_soma(s); break;
                case '*':
                  choose_multiplica(s); break;
                case '/':
                  choose_divide(s); break;
                case '(':
                  choose_decrementa(s); break;
                case ')':
                  choose_incrementa(s); break;
                case '&':
                  choose_E(s); break;
                case '|':
                  choose_ou(s); break;
                case '%':
                  choose_modulo(s); break;
                case '^':
                  choose_xor(s); break;
                case '~':
                  choose_not(s); break;
                case '#':
                  choose_potencia(s); break;
                case '_':
                  push(s,get_elem(s,0)); break;
                case ';':
                  pop(s); break;
                case '\\':
                  choose_troca(s); break;
                case '@':
                  choose_roda(s); break;
                case '$':
                  choose_copia(s); break;
                case 'c':
                  choose_converteC(s); break;
                case 'i':
                  choose_converteI(s); break;
                case 'f':
                  choose_converteF(s); break;
                case 'l':
                  choose_L(s); break;
                default: 
                  push_DOUBLE(s,val_d); break;    
        }
    }  
    print_stack(s);
}