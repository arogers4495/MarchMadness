#ifndef MARCHMADNESS_BRACKET_STACK_H
#define MARCHMADNESS_BRACKET_STACK_H

#include <stdbool.h>
#include "team.h"

typedef struct stack_node_struct
{
    team* t;
    struct stack_node_struct* prev;
} stack_node;

typedef struct bracket_stack_struct {
    stack_node* head;
    int size;
} bracket_stack;


void initialize(bracket_stack* s);

void push(bracket_stack* s, char* name, int seed);

void pop(bracket_stack* s, team* t);

void peek(bracket_stack* s, team* t);

bool is_empty(bracket_stack* s);

#endif //MARCHMADNESS_BRACKET_STACK_H
