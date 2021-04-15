/**
 * @file auxiliar.h 
 * \brief Módulo das funções auxiliares.
 */ 
#include "stack.h"
#include <string.h>

DATA get_elem(STACK *s,int n);

void choose_soma (STACK *s);
void choose_subtrai (STACK *s);
void choose_multiplica (STACK *s);
void choose_divide (STACK *s);
void choose_decrementa (STACK *s);
void choose_incrementa (STACK *s);
void choose_modulo (STACK *s);
void choose_potencia (STACK *s);
void choose_troca (STACK *s);
void choose_roda(STACK *s);
void choose_converteC (STACK *s);
void choose_converteI (STACK *s);
void choose_converteF (STACK *s);
void choose_L (STACK *s);