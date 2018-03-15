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
    t->seed = seed;

    node->prev = s->head;
    s->head = node;
    ++s->size;
}


void pop(bracket_stack* s, team* t)
{
    if (is_empty(s)) {
        return;
    }

    stack_node* node = s->head;
    // Discard result if team is null.
    if (t == NULL) {
        strcpy(t->teamName, node->t->teamName);
        t->seed = node->t->seed;
    }
    s->head = node->prev;
    free(node->t);
    free(node);
}


void peek(bracket_stack* s, team* t)
{
    if (is_empty(s)) {
        return;
    }

    stack_node* node = s->head;
    strcpy(t->teamName, node->t->teamName);
    t->seed = node->t->seed;
}


bool is_empty(bracket_stack* s)
{
    return s->head == NULL;
}


int size(bracket_stack* s)
{
    return s->size;
}


void free_stack(bracket_stack* s)
{
    if (s == NULL || is_empty(s)) {
        return;
    }
    stack_node* n = s->head;
    while (n != NULL) {
        stack_node* nf = n;
        n = n->prev;
        free(nf);
    }
    initialize(s);
}


void free_stack_all(bracket_stack* s)
{
    if (s == NULL) {
        return;
    }
    free_stack(s);
    free(s);
}
