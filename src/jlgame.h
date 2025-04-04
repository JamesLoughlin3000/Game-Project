#ifndef JLGAME_H
#define JLGAME_H

#define ROWS 6                  //number of rows in all 2D arrays
#define CHARS 8                 //number of characters allocated to all strings, also columns in all 2d arrays
#define REPEATS 3               //number of repeats per round
#define RANDOM_MAX 3            //maximum value of decider variable

/*Check whether a given answer is equal to the expected answer*/
unsigned short int check(char expected[CHARS], char given[CHARS]) {

    unsigned short int outcome = 1;                     //either 0 or 1, value returned at the end

    for (int c=0; c<CHARS && (expected[c] != '\0' || given[c] != '\0'); c++) {   //loop for each character in the string(s) so long as there are no null chracters
        if (expected[c] != given[c]) {                  //if a pair of characters, and therefore the strings as a whole, are not equal
            outcome = 0;                                //set outcome to false
        }
    }
    return outcome;                                     //return value of outcome
}

#endif
