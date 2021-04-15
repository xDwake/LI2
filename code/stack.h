/**
 * @file stack.h 
 * \brief Módulo das funções da stack.
 */ 
 
#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

/**
* \brief Enumera os diferentes tipos de dados como potências da base 2.
*
*/
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;

/**
* \brief Máscaras dos tipos.
*
*/
#define INTEGER  (LONG | CHAR)
#define NUMBER   (INTEGER | DOUBLE)

/**
* \brief Estrutura que define os tipos de dados aceites pela stack.
*
*/
typedef struct data {
  TYPE type;
  // Esta parte devia ser transformada numa union mais tarde
  long LONG;
  double DOUBLE;
  char CHAR;
  char *STRING;
} DATA;

/**
*
* \brief Estrutura stack onde são guardados os elementos
*
* @param size Tamanho da stack.
*
* @param n_elems Indice do elemento.
*
*/
typedef struct stack {
  DATA *stack;
  int size;
  int n_elems;
} STACK;

/**
*
* \brief Funções que permitem navegar na stack.
*
* @param elem Elemento a ser adicionado à stack.
*
* @param s Estrutura stack onde são guardados os elementos.
*
* @param mask Máscara que permite verificar o tipo do elemento.
*
*/
int has_type(DATA elem, int mask);
STACK *create_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
int is_empty(STACK *s);
void print_stack(STACK *s);

/**
 * \brief Função que permite criar uma variante das funções pop e push, restritas a um tipo.
 * 
 * @param _type Tipo do elemento.
 *
 * @param _name Nome do elemento.
 */
#define STACK_OPERATION_PROTO(_type, _name)   \
  void push_##_name(STACK *s, _type val);     \
  _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif
