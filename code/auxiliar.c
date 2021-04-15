/**
 * @file auxiliar.c 
 * \brief Funções auxiliares do programa.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "auxiliar.h"
#include "stack.h"

/**
 * \brief Função que retorna o elemento em determinada posição.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * @param n Posição, na stack, do elemento.
 * @returns Elemento na posição n da stack.
 */
DATA get_elem(STACK *s,int n){
  return s->stack[s->n_elems - n-1];
}

/**
 * \brief Função que realiza a operação soma.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_soma (STACK *s){
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

/**
 * \brief Função que realiza a operação subtração.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_subtrai (STACK *s){
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

/**
 * \brief Função que realiza a operação multiplicação.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_multiplica (STACK *s){
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

/**
 * \brief Função que realiza a operação divisão.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_divide (STACK *s){
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

/**
 * \brief Função que realiza a operação de decremento.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_decrementa (STACK *s){
    DATA elem = top(s);
    TYPE type = elem.type;
    long x; double y; char z;
    switch(type) {
      case LONG:
        x = pop_LONG(s);
        push_LONG(s,x-1); break;
      case DOUBLE:
        y = pop_DOUBLE(s);
        push_DOUBLE(s,y-1); break;
      case CHAR:
        z = pop_CHAR(s);
        push_CHAR(s,z-1); break;
      default: 
        break;  
    }
}

/**
 * \brief Função que realiza a operação de incremento.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 *
 */
void choose_incrementa (STACK *s){
    if (has_type((get_elem(s,0)),LONG)){
        long x = pop_LONG(s);
        push_LONG(s,x+1);
    }
    else if(has_type((get_elem(s,0)),DOUBLE)){
        double x = pop_DOUBLE(s);
                push_DOUBLE(s,x+1);
    }
    else if(has_type((get_elem(s,0)),CHAR)){
        char x = pop_CHAR(s);
        push_CHAR(s,x+1);
    }  
}

/**
 * \brief Função que realiza a operação de conjunção.
 * 
 * A função retira o elemento do topo da stack. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_E (STACK *s){
    long x = pop_LONG(s);
    long y = pop_LONG(s);
    push_LONG(s,x&y);
}

/**
 * \brief Função que realiza a operação disjunção.
 * 
 * A função retira o elemento do topo da stack. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_ou (STACK *s){
    long x = pop_LONG(s);
    long y = pop_LONG(s);
    push_LONG(s,x|y);
}

/**
 * \brief Função que realiza a operação módulo.
 * 
 * A função retira o elemento do topo da stack.  
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 *
 */
void choose_modulo (STACK *s){
    long x = pop_LONG(s);
    long y = pop_LONG(s);
    push_LONG(s,y%x);
}

/**
 * \brief Função que realiza a operação xor.
 * 
 * A função retira o elemento do topo da stack. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_xor (STACK *s){
    long x = pop_LONG(s);
    long y = pop_LONG(s);
    push_LONG(s,x^y);
}

/**
 * \brief Função que realiza a operação not.
 * 
 * A função retira o elemento do topo da stack.  
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_not (STACK *s){
    long x = pop_LONG(s);
    push_LONG(s,~x);
}

/**
 * \brief Função que realiza a operação potência.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_potencia (STACK *s){
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

/**
 * \brief Função que troca a posição dos elementos.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack os elementos resultantes.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_troca (STACK *s){
        DATA x = pop (s);
        DATA y = pop (s);
        push (s,x);
        push (s,y);   
}

/**
 * \brief Função que roda a posição dos elementos do topo da stack.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack os elementos resultantes.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_roda(STACK *s){
        DATA x = pop (s);
        DATA y = pop (s);
        DATA z = pop (s);
        push (s,y);
        push (s,x);
        push (s,z);   
}

/**
 * \brief Função que copia o elemento na n-ésima posição.
 * 
 * A função retira o elemento do topo da stack. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_copia (STACK *s){
    long x = pop_LONG(s);
    push(s,get_elem(s,x));
}    

/**
 * \brief Função que converte o elemento do topo da stack num char.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_converteC (STACK *s){
    DATA elem = top(s);
    TYPE type = elem.type;
    long x; double y;
    switch(type) {
      case LONG:
        x = pop_LONG(s);
        push_CHAR (s,(char)x); break;
      case DOUBLE:
        y = pop_DOUBLE(s);
        push_CHAR (s,(char)y); break;
      default:
        break;  
    }
}

/**
 * \brief Função que converte o elemento do topo da stack num long.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_converteI (STACK *s){
    DATA elem = top(s);
    TYPE type = elem.type;
    char x; double y; char *z; int w;
    switch(type) {
      case CHAR:
        x = pop_CHAR(s);
        push_LONG (s,(long)x); break;
      case DOUBLE:
        y = pop_DOUBLE(s);
        push_LONG (s,(long)y); break;
      case STRING:
        z = pop_STRING(s);
        w = atol(z);
        push_LONG(s,w); break;
      default: 
        break;   
    }
}

/**
 * \brief Função que converte o elemento do topo da stack num double.
 * 
 * A função verifica o tipo do elemento do topo da stack e retira-o. 
 * Realiza a operação e retorna ao topo da stack o elemento resultante.
 *
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_converteF (STACK *s){
    DATA elem = top(s);
    TYPE type = elem.type;
    char x; int y; char *z; double w;
    switch(type) {
      case CHAR:
        x = pop_CHAR(s);
        push_DOUBLE (s,(double)x); break;
      case LONG:
        y = pop_LONG(s);
        push_DOUBLE(s,(double)y); break;
      case STRING:
        z = pop_STRING(s);
        w = atof(z);
        push_DOUBLE(s,w);break;
      default:
        break;    
    }
}

/**
 * \brief Função que permite ler a linha seguinte.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_L (STACK *s){
    char linha[10240];
    assert( fgets(linha, 10240,stdin) != NULL);
    assert( linha[strlen(linha)-1] == '\n');
    push_STRING(s,&linha[0]);
}
