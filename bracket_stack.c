#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "bracket_stack.h"


void initialize(bracket_stack* s)
{
    s->head = NULL;
    s->size = 0;
}


void push(bracket_stack* s, char* name, int seed)
{
    stack_node* node = (stack_node*) malloc(sizeof(stack_node));
    team* t = (team*) malloc(sizeof(team));
    strcpy(t->teamName, name);

    node->prev = s->head;
    s->head = node;
    ++s->size;
}


void pop(bracket_stack* s, team* t)
{

}


void peek(bracket_stack* s, team* t)
{
    
}


bool is_empty(bracket_stack* s)
{
    return s->head == NULL;
}
