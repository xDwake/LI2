#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "auxiliar.h"
#include "stack.h"


DATA get_elem(STACK *s,int n){
  return s->stack[s->n_elems - n-1];
}

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

void choose_E (STACK *s){
    long x = pop_LONG(s);
    long y = pop_LONG(s);
    push_LONG(s,x&y);
}

void choose_ou (STACK *s){
    long x = pop_LONG(s);
    long y = pop_LONG(s);
    push_LONG(s,x|y);
}

void choose_modulo (STACK *s){
    long x = pop_LONG(s);
    long y = pop_LONG(s);
    push_LONG(s,y%x);
}

void choose_xor (STACK *s){
    long x = pop_LONG(s);
    long y = pop_LONG(s);
    push_LONG(s,x^y);
}

void choose_not (STACK *s){
    long x = pop_LONG(s);
    push_LONG(s,~x);
}

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

void choose_troca (STACK *s){
    if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),LONG)){
        long x = pop_LONG(s);
        long y = pop_LONG(s);
        push_LONG(s,x);
        push_LONG(s,y);
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE)){
            double x = pop_DOUBLE(s);
            double y = pop_DOUBLE(s);
            push_DOUBLE(s,x);
            push_DOUBLE(s,y);
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),LONG)){
            double x = pop_DOUBLE(s);
            long y = pop_LONG(s);
            push_DOUBLE(s,x);
            push_LONG(s,y);
    }
    else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),DOUBLE)){
            long x = pop_LONG(s);
            double y = pop_DOUBLE(s);
            push_LONG(s,x);
            push_DOUBLE(s,y);
    }
    else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),CHAR)){
            long x = pop_LONG(s);
            char y = pop_CHAR(s);
            push_LONG(s,x);
            push_CHAR(s,y);
    }
    else if (has_type((get_elem(s,0)),CHAR) && has_type((get_elem(s,1)),LONG)){
            char x = pop_CHAR(s);
            long y = pop_LONG(s);
            push_CHAR(s,x);
            push_LONG(s,y);
    }
}

void choose_roda(STACK *s){
    if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),LONG) && has_type((get_elem(s,2)),LONG)){
        long x = pop_LONG(s);
        long y = pop_LONG(s);
        long z = pop_LONG(s);
        push_LONG(s,y);
        push_LONG(s,x);
        push_LONG(s,z);
    }
    else if (has_type((get_elem(s,0)),DOUBLE) && has_type((get_elem(s,1)),DOUBLE) && has_type((get_elem(s,2)),DOUBLE)){
            double x = pop_DOUBLE(s);
            double y = pop_DOUBLE(s);
            double z = pop_DOUBLE(s);
            push_DOUBLE(s,y);
            push_DOUBLE(s,x);
            push_DOUBLE(s,z);
    }
    else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),LONG) && has_type((get_elem(s,2)),CHAR)){
            long x = pop_LONG(s);
            long y = pop_LONG(s);
            char z = pop_CHAR(s);
            push_LONG(s,y);
            push_LONG(s,x);
            push_CHAR(s,z);
    }
    else if (has_type((get_elem(s,0)),LONG) && has_type((get_elem(s,1)),CHAR) && has_type((get_elem(s,2)),CHAR)){
            long x = pop_LONG(s);
            char y = pop_CHAR(s);
            char z = pop_CHAR(s);
            push_CHAR(s,y);
            push_LONG(s,x);
            push_CHAR(s,z);
    }
    else if (has_type((get_elem(s,0)),CHAR) && has_type((get_elem(s,1)),CHAR) && has_type((get_elem(s,2)),CHAR)){
            char x = pop_CHAR(s);
            char y = pop_CHAR(s);
            char z = pop_CHAR(s);
            push_CHAR(s,y);
            push_CHAR(s,x);
            push_CHAR(s,z);
    }
    else if (has_type((get_elem(s,0)),CHAR) && has_type((get_elem(s,1)),LONG) && has_type((get_elem(s,2)),LONG)){
            char x = pop_CHAR(s);
            long y = pop_LONG(s);
            long z = pop_LONG(s);
            push_LONG(s,y);
            push_CHAR(s,x);
            push_LONG(s,z);
    }
    else if (has_type((get_elem(s,0)),CHAR) && has_type((get_elem(s,1)),CHAR) && has_type((get_elem(s,2)),LONG)){
            char x = pop_CHAR(s);
            char y = pop_CHAR(s);
            long z = pop_LONG(s);
            push_CHAR(s,y);
            push_CHAR(s,x);
            push_LONG(s,z);
    }
}

void choose_copia (STACK *s){
    long x = pop_LONG(s);
    push(s,get_elem(s,x));
}    

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

void choose_L (STACK *s){
    char linha[10240];
    assert( fgets(linha, 10240,stdin) != NULL);
    assert( linha[strlen(linha)-1] == '\n');
    push_STRING(s,&linha[0]);
}    