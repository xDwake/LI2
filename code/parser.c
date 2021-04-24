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
    //STACK *var = create_stack();
    //fill_var(var);
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
        } /*
        else if(strcmp(token,"e|") == 0) {
          short_OU (s);
        } 
        else if(strcmp(token,"e&") == 0) {
          short_E (s);
        } 
        else if(strcmp(token,"e>") == 0) {
          short_higher (s);
        } 
        else if(strcmp(token,"e<") == 0) {
          short_minor (s);
        }
        else if (strcmp(token,":A") == 0){
          replace_elem(s,var,0);
        }
        else if (strcmp(token,":B") == 0){
          replace_elem(s,var,1);
        }
        else if (strcmp(token,":C") == 0){
          replace_elem(s,var,2);
        }
        else if (strcmp(token,":D") == 0){
          replace_elem(s,var,3);
        }
        else if (strcmp(token,":E") == 0){
          replace_elem(s,var,4);
        }
        else if (strcmp(token,":F") == 0){
          replace_elem(s,var,5);
        }
        else if (strcmp(token,":G") == 0){
          replace_elem(s,var,6);
        }
        else if (strcmp(token,":H") == 0){
          replace_elem(s,var,7);
        }
        else if (strcmp(token,":I") == 0){
          replace_elem(s,var,8);
        }
        else if (strcmp(token,":J") == 0){
          replace_elem(s,var,9);
        }
        else if (strcmp(token,":K") == 0){
          replace_elem(s,var,10);
        }
        else if (strcmp(token,":L") == 0){
          replace_elem(s,var,11);
        }
        else if (strcmp(token,":M") == 0){
          replace_elem(s,var,12);
        }
        else if (strcmp(token,":N") == 0){
          replace_elem(s,var,13);
        }
        else if (strcmp(token,":O") == 0){
          replace_elem(s,var,14);
        }
        else if (strcmp(token,":P") == 0){
          replace_elem(s,var,15);
        }
        else if (strcmp(token,":Q") == 0){
          replace_elem(s,var,16);
        }
        else if (strcmp(token,":R") == 0){
          replace_elem(s,var,17);
        } 
        else if (strcmp(token,":S") == 0){
          replace_elem(s,var,18);
        }
        else if (strcmp(token,":T") == 0){
          replace_elem(s,var,19);
        }
        else if (strcmp(token,":U") == 0){
          replace_elem(s,var,20);
        }
        else if (strcmp(token,":V") == 0){
          replace_elem(s,var,21);
        }
        else if (strcmp(token,":W") == 0){
          replace_elem(s,var,22);
        }
        else if (strcmp(token,":X") == 0){
          replace_elem(s,var,23);
        } 
        else if (strcmp(token,":Y") == 0){
          replace_elem(s,var,24);
        }
        else if (strcmp(token,":Z") == 0){
          replace_elem(s,var,25);
        } */
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
                  push_LONG(s,pop_LONG(s)&pop_LONG(s)); break;
                case '|':
                  push_LONG(s,pop_LONG(s)|pop_LONG(s)); break;
                case '%':
                  choose_modulo(s); break;
                case '^':
                  push_LONG(s,pop_LONG(s)^pop_LONG(s)); break;
                case '~':
                  push_LONG(s,~pop_LONG(s)); break;
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
                  push(s,get_elem(s,pop_LONG(s))); break;
                case 'c':
                  choose_converteC(s); break;
                case 'i':
                  choose_converteI(s); break;
                case 'f':
                  choose_converteF(s); break;
                case 'l':
                  choose_L(s); break; /*
                case '?':
                  if_then_else(s); break;
                case '=':
                  choose_igual(s); break;
                case '<':
                  choose_menor(s); break;
                case '>':
                  choose_maior(s); break;
                case '!':
                  choose_nao(s); break; 
                case 'A':
                  choose_letter(s,var,25); break;
                case 'B':
                  choose_letter(s,var,24); break;
                case 'C':
                  choose_letter(s,var,23); break;
                case 'D':
                  choose_letter(s,var,22); break;
                case 'E':
                  choose_letter(s,var,21); break;
                case 'F':
                  choose_letter(s,var,20); break;
                case 'G':
                  choose_letter(s,var,19); break;
                case 'H':
                  choose_letter(s,var,18); break;
                case 'I':
                  choose_letter(s,var,17); break;
                case 'J':
                  choose_letter(s,var,16); break; 
                case 'K':
                  choose_letter(s,var,15); break;
                case 'L':
                  choose_letter(s,var,14); break; 
                case 'M':
                  choose_letter(s,var,13); break;
                case 'N':
                  choose_letter(s,var,12); break;
                case 'O':
                  choose_letter(s,var,11); break;
                case 'P':
                  choose_letter(s,var,10); break;
                case 'Q':
                  choose_letter(s,var,9); break;
                case 'R':
                  choose_letter(s,var,8); break;
                case 'S':
                  choose_letter(s,var,7); break;
                case 'T':
                  choose_letter(s,var,6); break;
                case 'U':
                  choose_letter(s,var,5); break;
                case 'V':
                  choose_letter(s,var,4); break;
                case 'W':
                  choose_letter(s,var,3); break;
                case 'X':
                  choose_letter(s,var,2); break;
                case 'Y':
                  choose_letter(s,var,1); break;
                case 'Z':
                  choose_letter(s,var,0); break; */                                                          
                default: 
                  push_DOUBLE(s,val_d); break;    
        }
    }  
    print_stack(s);
}