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
  switch(checks_type(s)){
    case 0:
      push_LONG(s,pop_LONG(s)+pop_LONG(s)); break;
    case 1:
      push_DOUBLE(s,pop_DOUBLE(s)+pop_DOUBLE(s)); break;
    case 2:
      push_DOUBLE(s,pop_LONG(s)+pop_DOUBLE(s)); break;
    case 3:
      push_DOUBLE(s,pop_DOUBLE(s)+pop_LONG(s)); break;
    default:
      break;
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
  switch(checks_type(s)){
    case 0: ;
      long y=pop_LONG(s); push_LONG(s,pop_LONG(s)-y);
      break;
    case 1: ;
      double w=pop_DOUBLE(s); push_DOUBLE(s,pop_DOUBLE(s)-w);
      break;
    case 2: ;
      long z=pop_LONG(s); push_DOUBLE(s,pop_DOUBLE(s)-z);
      break;
    case 3: ;
      double t=pop_DOUBLE(s); push_DOUBLE(s,pop_LONG(s)-t);
      break;  
    default:
      break;
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
  switch(checks_type(s)){
    case 0:
      push_LONG(s,pop_LONG(s)*pop_LONG(s)); break;
    case 1:
      push_DOUBLE(s,pop_DOUBLE(s)*pop_DOUBLE(s)); break;
    case 2:
      push_DOUBLE(s,pop_LONG(s)*pop_DOUBLE(s)); break;
    case 3:
      push_DOUBLE(s,pop_DOUBLE(s)*pop_LONG(s)); break;
    default:
      break;
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
  switch(checks_type(s)){
    case 0: ;
      long y=pop_LONG(s); push_LONG(s,pop_LONG(s)/y);
      break;
    case 1: ;
      double w=pop_DOUBLE(s); push_DOUBLE(s,pop_DOUBLE(s)/w);
      break;
    case 2: ;
      long z=pop_LONG(s); push_DOUBLE(s,pop_DOUBLE(s)/z);  
      break;
    case 3: ;
      double t=pop_DOUBLE(s); push_DOUBLE(s,pop_LONG(s)/t);
      break;  
    default:
      break;
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
    switch(top(s).type) {
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
    switch(top(s).type) {
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
  switch(checks_type(s)){
    case 0: ;
      long y=pop_LONG(s); push_LONG(s,pow(pop_LONG(s),y));
      break;
    case 1: ;
      double w=pop_DOUBLE(s); push_DOUBLE(s,pow(pop_DOUBLE(s),w));
      break;
    case 2: ;
      long z=pop_LONG(s); push_DOUBLE(s,pow(pop_DOUBLE(s),z));  
      break;
    case 3: ;
      double t=pop_DOUBLE(s); push_DOUBLE(s,pow(pop_LONG(s),t));
      break;  
    default:
      break;
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
    switch(top(s).type) {
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
    switch(top(s).type) {
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
    switch(top(s).type) {
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

/**
 * \brief Função que testa a disjunção entre dois elementos.
 *
 * Função correspondente ao "E" lógico mas com shortcut. 
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void short_E (STACK *s) {
  switch(checks_type(s)){
    case 0: ;
      long y = pop_LONG(s);
      if (pop_LONG(s) != 0 && y) push_LONG (s,y);
      else push_LONG (s,0);
      break;
    case 1: ;
      double w = pop_DOUBLE(s);
      if (pop_DOUBLE(s) != 0 && w) push_DOUBLE (s,w);
      else push_LONG (s,0); 
      break;
    case 2: ;
      long z = pop_LONG(s); 
      if (pop_DOUBLE(s) != 0 && z) push_LONG (s,z);
      else push_LONG (s,0);
      break;
    case 3: ;
      double t = pop_DOUBLE(s); 
      if (pop_LONG(s) != 0 && t) push_DOUBLE (s,t);
      else push_LONG (s,0);
      break;  
    default:
      break;
  }
}

/**
 * \brief Função que testa a conjunção entre dois elementos.
 *
 * Função correspondente ao "Ou" lógico mas com shortcut. 
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void short_OU (STACK *s) {
  switch(checks_type(s)){
    case 0: ;
      long y = pop_LONG(s);
      long w = pop_LONG(s);
      if (w != 0) push_LONG (s,w);
      else if (y!=0) push_LONG (s,y);
           else push_LONG(s,0);
      break;
    case 1: ;
      double z = pop_DOUBLE (s);
      double t = pop_DOUBLE (s);
      if (t != 0) push_DOUBLE(s,t);
      else if (z!=0) push_DOUBLE (s,z);
           else push_LONG(s,0);
      break;
    case 2: ;
      long a = pop_LONG (s);
      double b = pop_DOUBLE (s);
      if (b != 0) push_DOUBLE (s,b);
      else if (a!=0) push_LONG (s,a);
           else push_LONG(s,0);
      break;
    case 3: ;
      double c = pop_DOUBLE (s);
      long d = pop_LONG (s);
      if (d != 0) push_LONG (s,d);
      else if (c!=0) push_DOUBLE (s,c);
           else push_LONG(s,0);
      break;  
    default:
      break;
  }
}

/**
 * \brief Função que procura o menor entre dois elementos.
 *
 * A função compara os dois elementos e coloca o menor na stack.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void  short_minor (STACK *s) {
  switch(checks_type(s)){
    case 0: ;
      long y = pop_LONG(s);
      long w = pop_LONG(s);
      if (y < w) push_LONG (s,y);
      else push_LONG (s,w);
      break;
    case 1: ;
      double z = pop_DOUBLE (s);
      double t = pop_DOUBLE (s);
      if (z < t) push_DOUBLE (s,z);
      else push_DOUBLE (s,t);
      break;
    case 2: ;
      long a = pop_LONG (s);
      double b = pop_DOUBLE (s);
      if (a < b) push_LONG (s,a);
      else push_DOUBLE (s,b);
      break;
    case 3: ;
      double c = pop_DOUBLE (s);
      long d = pop_LONG (s);
      if (c < d) push_DOUBLE (s,c);
      else push_LONG (s,d);
      break;  
    default:
      break;
  }
}

/**
 * \brief Função que procura o maior entre dois elementos.
 *
 * A função compara os dois elementos e coloca o maior na stack.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void short_higher (STACK *s) {
  switch(checks_type(s)){
    case 0: ;
      long y = pop_LONG(s);
      long w = pop_LONG(s);
      if (y > w) push_LONG (s,y);
      else push_LONG (s,w);
      break;
    case 1: ;
      double z = pop_DOUBLE (s);
      double t = pop_DOUBLE (s);
      if (z > t) push_DOUBLE (s,z);
      else push_DOUBLE (s,t);
      break;
    case 2: ;
      long a = pop_LONG (s);
      double b = pop_DOUBLE (s);
      if (a > b) push_LONG (s,a);
      else push_DOUBLE (s,b);
      break;
    case 3: ;
      double c = pop_DOUBLE (s);
      long d = pop_LONG (s);
      if (c > d) push_DOUBLE (s,c);
      else push_LONG (s,d);
      break;  
    default:
      break;
  }
}

/**
 * \brief Função correspondente à condição if-then-else.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void if_then_else (STACK *s) {
  DATA x = pop(s);
  DATA y = pop(s);
  DATA cond = pop(s);
  switch (cond.type){
    case CHAR:{ 
      if (cond.CHAR != 0) push (s,y);
      else push (s,x);
      break;
    } 
    case LONG:{
      if (cond.LONG != 0) push (s,y);
      else push (s,x);
      break;
    } 
    case DOUBLE:{
      if (cond.DOUBLE != 0) push (s,y);
      else push(s,x);
      break;
    }
    case STRING:{ 
      if (strcmp(cond.STRING, "")!= 0) push (s,y);
      else push (s,x);
      break;
    }   
  } 
}

/**
 * \brief Função que testa a igualdade entre dois elementos.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_igual (STACK *s){
  switch(checks_type(s)){
    case 0: ;
      long y = pop_LONG (s);
      long w = pop_LONG (s);
      if (y==w) push_LONG (s,1);
      else push_LONG(s,0);
      break;
    case 1: ;
      double z = pop_DOUBLE (s);
      double t = pop_DOUBLE (s);
      if (t==z) push_LONG (s,1);
      else push_LONG(s,0);
      break;
    case 2: ;
      long a = pop_LONG (s);
      double b = pop_DOUBLE (s);
      if (a==b) push_LONG (s,1);
      else push_LONG (s,0);
      break;
    case 3: ;
      double c = pop_DOUBLE (s);
      long d = pop_LONG (s);
      if (c==d) push_LONG(s,1);
      else push_LONG(s,0);
      break;  
    default:
      break;
  }
}

/**
 * \brief Função que testa se um elemento é menor que outro.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_menor (STACK *s){
  switch(checks_type(s)){
    case 0: ;
      long y = pop_LONG (s);
      long w = pop_LONG (s);
      if (w<y) push_LONG (s,1);
      else push_LONG(s,0);
      break;
    case 1: ;
      double z = pop_DOUBLE (s);
      double t = pop_DOUBLE (s);
      if (t<z) push_LONG (s,1);
      else push_LONG(s,0);
      break;
    case 2: ;
      long a = pop_LONG (s);
      double b = pop_DOUBLE (s);
      if (b<a) push_LONG (s,1);
      else push_LONG (s,0);
      break;
    case 3: ;
      double c = pop_DOUBLE (s);
      long d = pop_LONG (s);
      if (d<c) push_LONG(s,1);
      else push_LONG(s,0);
      break;
    case 4: ;
      char e = pop_CHAR (s);
      char f = pop_CHAR (s);
      if (f<e) push_LONG (s,1);
      else push_LONG(s,0);
      break;
    case 5: ;
      char g = pop_CHAR (s);
      long h = pop_LONG (s);
      if (h<g) push_LONG(s,1);
      else push_LONG(s,0);
      break;
    case 6: ;
      long i = pop_LONG (s);
      char j = pop_CHAR (s);
      if (j<i) push_LONG(s,1);
      else push_LONG(s,0);
      break; 
    default:
      break;
  }
}

/**
 * \brief Função que testa se um elemento é maior que outro.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_maior (STACK *s){
  switch(checks_type(s)){
    case 0: ;
      long y = pop_LONG (s);
      long w = pop_LONG (s);
      if (w>y) push_LONG (s,1);
      else push_LONG(s,0);
      break;
    case 1: ;
      double z = pop_DOUBLE (s);
      double t = pop_DOUBLE (s);
      if (t>z) push_LONG (s,1);
      else push_LONG(s,0);
      break;
    case 2: ;
      long a = pop_LONG (s);
      double b = pop_DOUBLE (s);
      if (b>a) push_LONG (s,1);
      else push_LONG (s,0);
      break;
    case 3: ;
      double c = pop_DOUBLE (s);
      long d = pop_LONG (s);
      if (d>c) push_LONG(s,1);
      else push_LONG(s,0);
      break;
    case 4: ;
      char e = pop_CHAR (s);
      char f = pop_CHAR (s);
      if (f>e) push_LONG (s,1);
      else push_LONG(s,0);
      break;
    case 5: ;
      char g = pop_CHAR (s);
      long h = pop_LONG (s);
      if (h>g) push_LONG(s,1);
      else push_LONG(s,0);
      break;
    case 6: ;
      long i = pop_LONG (s);
      char j = pop_CHAR (s);
      if (j>i) push_LONG(s,1);
      else push_LONG(s,0);
      break;     
    default:
      break;
  }
}

/**
 * \brief Função corresponte à negação.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 */
void choose_nao(STACK *s){
    DATA elem = pop(s);
    TYPE type = elem.type;
    switch(type) {
      case CHAR:
        if(elem.CHAR !=0) push_LONG(s,0);
        else push_LONG(s,1); 
        break;
      case LONG:
        if(elem.LONG !=0) push_LONG(s,0);
        else push_LONG(s,1); 
        break;
      case DOUBLE:
        if(elem.DOUBLE !=0) push_LONG(s,0);
        else push_LONG(s,1); 
        break;
      default:
        break;    
    } 
}

/**
 * \brief Função que preenche a stack das variaveis.
 * 
 * @param var Estrutura stack onde estão guardadas as variaveis.
 * 
 */
void fill_var(STACK *var){
  push_LONG(var,10);
  push_LONG(var,11);
  push_LONG(var,12);
  push_LONG(var,13);
  push_LONG(var,14);
  push_LONG(var,15);
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,0);
  push_CHAR(var,'\n');
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,0);
  push_CHAR(var,' ');
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,0);
  push_LONG(var,1);
  push_LONG(var,2);
}

/**
 * \brief Função que substitui uma variavel pelo topo da stack.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 * @param var Estrutura stack onde estão guardadas as variaveis.
 * 
 * @param x Indice do elemento a ser trocado.
 * 
 */
void replace_elem(STACK *s, STACK *var, int x){
  var->stack[x] = top(s); 
}

/**
 * \brief Função que vai buscar o valor de determinada variavel.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 * 
 * @param var Estrutura stack onde estão guardadas as variaveis.
 * 
 * @param x Indice da variavel.
 * 
 */
void choose_letter(STACK *s,STACK *var, int x){
  push(s,get_elem(var,x));
}

/**
 * \brief Função que verifica o tipo dos dois elementos do topo da stack.
 * 
 * Esta função cria identificadores para os diferentes pares de tipos dos elementos.
 * 
 * @param s Estrutura stack onde são guardados os elementos.
 *
 * @returns O identificador correspondente. 
 */ 
int checks_type(STACK *s){
  int r=11;
  if (has_type ((get_elem(s,0)),LONG) && has_type ((get_elem(s,1)),LONG)) r=0;
  else if (has_type ((get_elem(s,0)),DOUBLE) && has_type ((get_elem(s,1)),DOUBLE)) r=1;
  else if (has_type ((get_elem(s,0)),LONG) && has_type ((get_elem(s,1)),DOUBLE)) r=2;
  else if (has_type ((get_elem(s,0)),DOUBLE) && has_type ((get_elem(s,1)),LONG)) r=3;
  else if (has_type ((get_elem(s,0)),CHAR) && has_type ((get_elem(s,1)),CHAR)) r=4;
  else if (has_type ((get_elem(s,0)),CHAR) && has_type ((get_elem(s,1)),LONG)) r=5;
  else if (has_type ((get_elem(s,0)),LONG) && has_type ((get_elem(s,1)),CHAR)) r=6;
  return r; 
}