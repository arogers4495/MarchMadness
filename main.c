#include <stdio.h>

int main() {
    int i;

    FILE *myFile;
    myFile = fopen("finalMarchMadness.txt", "r");
    //check to see if null
    if (myFile == NULL) {
        printf("Could not open file.\n");
    } else {
        //iterate through the text & collect team name/seed
        for (i = 0; i < 68; ++i) {
            //create temp variables for the scan here
            char teamName[20];
            int teamSeed;
            fscanf(myFile, "%s,%d", teamName, &teamSeed);
        }
        return 0;

    }
}