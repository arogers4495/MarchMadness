#ifndef MARCHMADNESS_TEAM_H
#define MARCHMADNESS_TEAM_H

typedef struct team_struct
{
    char teamName[50];
    int seed;
} team;

team* game(team* t1, team* t2);

#endif //MARCHMADNESS_TEAM_H
