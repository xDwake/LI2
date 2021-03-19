#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "parser.c"

int main (){
    char line [10240];

    assert( fgets(line, 10240,stdin) != NULL);
    assert( line[strlen(line)-1] == '\n');
    
    parser(line);
    return 0;
}