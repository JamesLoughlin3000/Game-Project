/*PROOF OF CONCEPT*/
/*CALL AND RESPONSE*/

#include <stdio.h>
#include <stdlib.h>
#include <jlgame.h>

int main() {
    /*Declare string arrays*/
    char calls[ROWS][CHARS] = {             //array of calls
        "bacon",
        "cheese",
        "new",
        "rice",
        "roast",
        "woolly"
    };
    char responses1[ROWS][CHARS] = {        //first set of responses, where each row corresponds to that same number of row in the calls array and the other response arrays
        "roll",
        "toastie",
        "york",
        "cracker",
        "potato",
        "jumper"
    };
    char responses2[ROWS][CHARS] = {        //second set of responses
        "lardons",
        "cake",
        "jersey",
        "pudding",
        "beef",
        "hat"
    };
    char responses3[ROWS][CHARS] = {        //third set of reponses
        "rashers",
        "string",
        "orleans",
        "crispies",
        "chicken",
        "mammoth"
    };

    /*Initialise other variables*/
    unsigned short int alive = 1;           //indicates whether the player has entered a wrong answer
    unsigned int cycles = 0;                //counts the amount of call-response cycles executed
    char current[CHARS];                    //response currently in use for a given round, as a string
    char ans[CHARS];                        //user's answer as a string
    int index = 0;                          //index of chosen call and response in their respective arrays for a given round
    int decider = 0;                        //dictates which responses array to take current response from for a given round
    
    /*PLAY GAME*/

    do {                                                //execute all this in the curly brackets, then repeat indefinitely while the variable alive is true
        cycles++;                                       //increment cycles by 1
        if (cycles > 1) {                               //if it isn't round 1
            index = rand() % ROWS;                      //randomly pick which index to use
            decider = rand() % RANDOM_MAX;              //randomly pick which array of responses to use
        }

        for (int c=0; c<CHARS; c++) {                       //loop for each character in a string
            switch (decider) {                              //decide which set of responses to use based on the randomly genereated integer
                case 0: {
                    current[c] = responses1[index][c];          //use response from responses1
                    break;
                }
                case 1: {
                    current[c] = responses2[index][c];          //use response from responses2
                    break;
                }
                case 2: {
                    current[c] = responses3[index][c];          //use response from responses3
                    break;
                }
            }
        }
        
        //  !!! SHOULD DISPLAY ROLL FIRST TIME !!!

        printf("When I say %s, you say %s!\n", calls[index], current);      //set out to the user what will be called and which response will be expected
    
        /*call 3 times*/
        for (int c=0; c<REPEATS && alive; c++) {            //loop for each character in a string so long as the user is in the game
            printf("%s!\n", calls[index]);                  //print the current call
            scanf("%s",&ans);                               //scan in the user's response from the keyboard

            /*if ans != current*/
            if (! check(current, ans)) {                    //if the expected response and given response are not equal

                printf("\n%s! You were supposed to say %s!\n\n", current, current);         //print game over message
                alive = 0;                                                              //set alive to false

            }
        }
    } while (alive);


    /*DISPLAY RESULTS*/

    //print message telling the user how many rounds they completed
    if (cycles == 1)    printf("You lasted through %d round.", cycles);     
    else                printf("You lasted through %d rounds.", cycles);    

    return 0;                                                               //terminate program successfully
}
