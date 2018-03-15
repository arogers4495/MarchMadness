#ifndef MARCHMADNESS_BRACKET_STACK_H
#define MARCHMADNESS_BRACKET_STACK_H

#include <stdbool.h>
#include "team.h"


// Stack node for internal use.
typedef struct stack_node_struct
{
    team t;
    struct stack_node_struct* prev;
} stack_node;


/**
 * A stack for storing teams in the NCAA March Madness bracket.
 */
typedef struct bracket_stack_struct
{
    stack_node* head;
    int size;
} bracket_stack;


/**
 * Initialize the stack to a valid empty state.
 */
void initialize(bracket_stack* s);

/**
 * Add a team to the stack.
 */
void push(bracket_stack* s, char* name, int seed);

/**
 * Return and remove the top element in the stack using the supplied team
 * pointer
 */
void pop(bracket_stack* s, team* t);

/**
 * Return without removing the top element in the stack using the supplied
 * team pointer.
 */
void peek(bracket_stack* s, team* t);

/**
 * Returns true if the stack has no elements.
 */
bool is_empty(bracket_stack* s);

/**
 * Return the number of elements on the stack.
 */
int size(bracket_stack* s);

/**
 * Free the internals of the stack, if they aren't null.
 */
void free_stack(bracket_stack* s);

/**
 * Free the internals of the stack and the stack itself.
 */
void free_stack_all(bracket_stack* s);

#endif //MARCHMADNESS_BRACKET_STACK_H
