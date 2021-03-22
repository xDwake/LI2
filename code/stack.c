/**
 * @file Funções relacionadas com a stack.
 */  
#include <stdio.h>
#include "stack.h"

/**
 * \brief Função que realiza a operação PUSH na stack.
 * 
 * @param val O elemento a ser colocado na stack.
 * @param stack O array desigado para a stack.
 * @param p O inteiro que controla o índice da stack.
 */
void PUSH (long val, long stack[], int *p){
    stack[*p] = val;
    (*p)++;
}

/**
 * \brief Função que realiza a operação POP na stack.
 * 
 * @param stack O array designado para a stack.
 * @param p O inteiro que controla o índice da stack.
 * 
 * @returns O valor que está na stack com o índice decrementado.
 */ 
long POP (long stack[], int *p){
    (*p)--;
    return (stack[*p]);
}

/** 
 * \brief Função que imprime a stack existente.
 * 
 * @param stack O arrau designado para a stack.
 * @param p O inteiro que controla o índice da stack.
 */
void print_stack(long stack[],int p){
    for(int i=0;i<p;i++){
             printf ("%ld", stack[i]);
        }
        printf("\n");
}