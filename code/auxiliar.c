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
        push_LONG(s,pop_LONG(s)+pop_LONG(s));
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
        push_DOUBLE(s,pop_DOUBLE(s)+pop_DOUBLE(s));
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
        push_DOUBLE(s,pop_DOUBLE(s)+pop_LONG(s));
    }
    else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
        push_DOUBLE(s,pop_LONG(s)+pop_DOUBLE(s));
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
        push_LONG(s,pop_LONG(s)-x);
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
            double x = pop_DOUBLE(s);
            push_DOUBLE(s,pop_DOUBLE(s)-x);
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
            double x = pop_DOUBLE(s);
            push_DOUBLE(s,pop_LONG(s)-x);
    }
    else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
            long x = pop_LONG(s);
            push_DOUBLE(s,pop_DOUBLE(s)-x);
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
        push_LONG(s,pop_LONG(s)*pop_LONG(s));
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
            push_DOUBLE(s,pop_DOUBLE(s)*pop_DOUBLE(s));
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
            push_DOUBLE(s,pop_LONG(s)*pop_DOUBLE(s));
    }
    else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
            push_DOUBLE(s,pop_DOUBLE(s)*pop_LONG(s));
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
        push_LONG(s,pop_LONG(s)/x);
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
            double x = pop_DOUBLE(s);
            push_DOUBLE(s,pop_DOUBLE(s)/x);
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
            double x = pop_DOUBLE(s);
            push_DOUBLE(s,pop_LONG(s)/x);
    }
    else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
            long x = pop_LONG(s);
            push_DOUBLE(s,pop_DOUBLE(s)/x);
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
    switch(type) {
      case LONG:
        push_LONG(s,pop_LONG(s)-1); break;
      case DOUBLE:
        push_DOUBLE(s,pop_DOUBLE(s)-1); break;
      case CHAR:
        push_CHAR(s,pop_CHAR(s)-1); break;
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
    DATA elem = top(s);
    TYPE type = elem.type;
    switch(type) {
      case LONG:
        push_LONG(s,pop_LONG(s)+1); break;
      case DOUBLE:
        push_DOUBLE(s,pop_DOUBLE(s)+1); break;
      case CHAR:
        push_CHAR(s,pop_CHAR(s)+1); break;
      default: 
        break;  
    }
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
    push_LONG(s,pop_LONG(s)%x);
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
        push_LONG(s,pow(pop_LONG(s),x));
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
            double x = pop_DOUBLE(s);
            push_DOUBLE(s,pow(pop_DOUBLE(s),x));
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
            double x = pop_DOUBLE(s);
            push_DOUBLE(s,pow(pop_LONG(s),x));
    }
    else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
            long x = pop_LONG(s);
            push_DOUBLE(s,pow(pop_DOUBLE(s),x));
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
    switch(type) {
      case LONG:
        push_CHAR (s,(char)pop_LONG(s)); break;
      case DOUBLE:
        push_CHAR (s,(char)pop_DOUBLE(s)); break;
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
    switch(type) {
      case CHAR:
        push_LONG (s,(long)pop_CHAR(s)); break;
      case DOUBLE:
        push_LONG (s,(long)pop_DOUBLE(s)); break;
      case STRING:
        push_LONG(s,atol(pop_STRING(s))); break;
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
    switch(type) {
      case CHAR:
        push_DOUBLE (s,(double)pop_CHAR(s)); break;
      case LONG:
        push_DOUBLE(s,(double)pop_LONG(s)); break;
      case STRING:
        push_DOUBLE(s,atof(pop_STRING(s)));break;
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
