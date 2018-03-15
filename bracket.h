#ifndef MARCHMADNESS_BRACKET_H
#define MARCHMADNESS_BRACKET_H

#include "bracket_stack.h"
#include "team.h"

/**
 * Calculate the winner of a bracket group.
 *
 * This function will free teams as they are eliminated and will return
 * the overall winning team for the group.
 */
team* process_bracket_group(bracket_stack* s);

#endif //MARCHMADNESS_BRACKET_H
