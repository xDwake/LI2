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
/*
void short_OU (STACK *s);
void short_E (STACK *s);
void short_minor (STACK *s);
void short_higher (STACK *s);
void if_then_else (STACK *s);
void choose_igual (STACK *s);
void choose_menor (STACK *s);
void choose_maior (STACK *s);
void choose_nao(STACK *s);



void fill_var(STACK *var);
void replace_elem(STACK *s, STACK *var, int x);
void choose_letter(STACK *s, STACK*var, int x);
*/
int checks_type(STACK *s);