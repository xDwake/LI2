/**
 * @file Ficheiro que contém a função principal do programa
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "parser.h"
#include "stack.h"

/**
 * \brief Função Main do programa.
 * 
 * Lê o input do utilizador e invoca a função parser.
 * 
 * @returns Devolve o valor 0.
 */
int main (){
    char line[10240];

    assert( fgets(line, 10240,stdin) != NULL);
    assert( line[strlen(line)-1] == '\n');
    
    parser(line);
    return 0;
}