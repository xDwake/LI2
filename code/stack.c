#include <stdio.h>

typedef struct {
    long array[10240];
    int p;
} STACK;

STACK new_stack() {
  STACK s;
  s.p = 0;
  return s;
}

#define PUSH (s,v)      \
    s.array[s.pos++] = v;

#define POP(s)          \
    s.array[--s.pos]


void print_stack(STACK s){
        for(int i=0;i<s.p;i++){
             printf ("%ld", s.array[i]);
        }
        printf("\n");
}
