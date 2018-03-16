#include <stdlib.h>
#include <stdio.h>
#include "bracket.h"


/** Allocate a team. */
team* get_team()
{
    return (team*) malloc(sizeof(team));
}


/** Return the winning team, free the loser. */
team* get_winner_free_loser(team* t1, team* t2)
{
    team* winner = game(t1, t2);
    printf("%20s vs %-20s Winner: %s\n", t1->teamName, t2->teamName, winner->teamName);
    if (t1 == winner) {
        free(t2);
    } else {
        free(t1);
    }
    return winner;
}

team* process_bracket_group(bracket_stack* s)
{
    // Base case
    if (size(s) == 1) {
        team* t = get_team();
        pop(s, t);
        // Return winner of bracket group
        return t;
    }

    // Working stack
    bracket_stack ws;
    initialize(&ws);
    team* winner;
    while (!is_empty(s)) {
        team* t1 = get_team();
        team* t2 = get_team();
        pop(s, t1);
        pop(s, t2);
        winner = get_winner_free_loser(t1, t2);

        push(&ws, winner->teamName, winner->seed);
        free(winner);
    }

    // Recurse until a single team remains
    return process_bracket_group(&ws);
}
