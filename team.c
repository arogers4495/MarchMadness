#include "team.h"


team* game(team* t1, team* t2)
{
    return (t1->seed < t2->seed) ? t1 : t2;
}
