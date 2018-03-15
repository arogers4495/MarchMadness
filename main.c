#include <stdio.h>

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

    //iterate through the text & collect team name/seed
    for (i = 0; i < 64; ++i) {
        //create temp variables for the scan here
        char teamName[50];
        int teamSeed;
        fscanf(myFile, " %[^,],%d", teamName, &teamSeed);
        printf("%d: %s, %d\n", i + 1,teamName, teamSeed);
    }
    fclose(myFile);
    return 0;
}
