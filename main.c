#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "team.h"
#include "bracket_stack.h"
#include "bracket.h"


int main() {
    int i;

    FILE *myFile;
    myFile = fopen("finalMarchMadness.txt", "r");
    //check to see if null
    if (myFile == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    bracket_stack groups[4];
    for (i = 0; i < 4; ++i) {
        initialize(&groups[i]);
    }
    //iterate through the text & collect team name/seed
    for (i = 0; i < 64; ++i) {
        //create temp variables for the scan here
        char teamName[50];
        int teamSeed;
        fscanf(myFile, " %[^,],%d", teamName, &teamSeed);
        // Add teams to their bracket groups
        push(&groups[i / 16], teamName, teamSeed);
    }
    fclose(myFile);

    printf("Final Four:\n");
    team final_four[4];
    bracket_stack final_group;
    initialize(&final_group);
    for (i = 0; i < 4; ++i) {
        team* winner = process_bracket_group(&groups[i]);
        strcpy(final_four[i].teamName, winner->teamName);
        final_four[i].seed = winner->seed;
        printf("%d: %s, %d\n", i + 1, winner->teamName, winner->seed);

        push(&final_group, winner->teamName, winner->seed);
        free(winner);
    }

    team* champs = process_bracket_group(&final_group);
    printf("Winner Winner Chicken Dinner: %s\n", champs->teamName);
    return 0;
}
