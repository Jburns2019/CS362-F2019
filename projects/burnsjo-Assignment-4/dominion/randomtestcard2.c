#include "unitTest.h"

int main () {
    //make variables avaiable.
    int numOfPlayers, choice1, choice2, currentPlayer, handPlace;
    
    //Set up the card set.
    int k[10] = { baron, minion, tribute, ambassador, mine, steward, village, smithy, adventurer, feast };
    numOfPlayers = 4;
    
    //set up the game state.
    struct gameState *post = newGame();
    initializeGame(numOfPlayers, k, numOfPlayers, post);

    struct gameState *pre;
    printf ("Testing The Minion Function.\n");

    printf ("RANDOM TESTS.\n");
    //Ensure a different stream everytime.
    srand(time(NULL));

    for (int i = 0; i < 10000; i++) {
        //initialize the variability every time.
        choice1 = rand() % 2;
        choice2 = rand() % 2;
        handPlace = rand() % (MAX_HAND+1);
        currentPlayer = rand() % (MAX_PLAYERS + 1);
        post->whoseTurn = rand() % (MAX_PLAYERS + 1);
        
        //Set up the pre state.
        pre = newGame();
        memcpy (pre, post, sizeof(struct gameState));
        
        minionHelper(post, handPlace, currentPlayer, choice1, choice2);
        
        //Check out what is happening and see if it is reasonable.
        assert(post->numActions - 1, pre->numActions, "PASSED: The number of actions was incremented correctly.", "\n\tERROR: The num of actions was not incremented by 1 check for bug 1.\n");
        
        if (choice1) {
            assert(post->coins - 2, pre->coins, "PASSED: The number of coins was incremented correctly.", "\n\tERROR: The num of coins was not incremented by 2 check inside the first if statement.\n");
        }
        else if (choice2) {
            
            int found = 0;
            int j = 0;
            while (!found && j < MAX_PLAYERS) {
                if (pre->handCount[j] > 4) {
                    assert(post->playedCardCount - 1, pre->playedCardCount, "PASSED: The number of played cards was decremented correctly.", "\n\tERROR: The num of played cards was not decremented check for bug 2 in while loop.\n");
                    found = 1;
                }
                else {
                    j++;
                }
                
            }
        }
        //Make a new game for the next round.
        post = newGame();
        initializeGame(numOfPlayers, k, numOfPlayers, post);
    }

    printf("Test For The Minion Function Is Completed.\n");

    return 0;
}