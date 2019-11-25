#include "unitTest.h"

int main () {
    //make variables avaiable.
    int numOfPlayers, choice1, currentPlayer, card, supplycount, handPlace, test;
    
    //Set up the card set.
    int k[10] = { baron, minion, tribute, ambassador, mine, steward, village, smithy, adventurer, feast };
    numOfPlayers = 4;
    
    //set up the game state.
    struct gameState *post = newGame();
    initializeGame(numOfPlayers, k, numOfPlayers, post);

    struct gameState *pre;
    printf ("Testing The Baron Function.\n");

    printf ("RANDOM TESTS.\n");
    
    //Ensure a different stream everytime.
    srand(time(NULL));

    for (int i = 0; i < 100000; i++) {
        //initialize the variability every time.
        currentPlayer = rand() % (MAX_PLAYERS+1);
        card = rand() % 27;
        supplycount = rand() % (MAX_DECK+1);
        handPlace = rand() % (MAX_HAND+1);
        
        post->supplyCount[card] = supplycount;
        choice1 = rand() % 2;
        post->hand[currentPlayer][handPlace] = card;
        post->handCount[currentPlayer] = handPlace;
        
        //Set up the pre state.
        pre = newGame();
        memcpy (pre, post, sizeof(struct gameState));
        
        test = baronHelper(post, choice1, currentPlayer);
        
        //Check out what is happening and see if it is reasonable.
        assert(post->numBuys - 1, pre->numBuys, "PASSED: The numOfBuys was incremented correctly.", "\n\tERROR: The numOfBuys was not incremented.\n");
        
        if (choice1 > 0) {
            assert(test, -1, "\n\tERROR: The while loop is not 0.\n", "PASSED: The while loop is set to 0.");
            if (pre->hand[currentPlayer][handPlace] == estate) {
              assert(post->coins - 4, pre->coins, "PASSED: The coins were incremented correctly if there is an estate card and choice1 is 1.", "\n\tERROR: The coins were not incremented by 4 properly.\n");
            }
        }
        
        //Make a new game for the next round.
        post = newGame();
        initializeGame(numOfPlayers, k, numOfPlayers, post);
    }

    printf("Test For The Baron Function Is Completed.\n");

    return 0;

}