#include "unitTest.h"

int main () {
    //make variables avaiable.
    int numOfPlayers, currentPlayer, nextPlayer;
    
    //Set up the card set.
    int k[10] = { baron, minion, tribute, ambassador, mine, steward, village, smithy, adventurer, feast };
    int tributeRevealedCards[2] = {-1, -1};
    
    numOfPlayers = 4;
    
    //set up the game state.
    struct gameState *post = newGame();
    initializeGame(numOfPlayers, k, numOfPlayers, post);

    struct gameState *pre;
    printf ("Testing The Tribute Function.\n");

    printf ("RANDOM TESTS.\n");
    //Ensure a different stream everytime.
    srand(time(NULL));

    for (int i = 0; i < 50000; i++) {
        //initialize the variability every time.
        nextPlayer = rand() % (MAX_PLAYERS+1);
        currentPlayer = rand() % (MAX_PLAYERS+1);
        
        post->deckCount[nextPlayer] = rand() % (MAX_DECK + 1);
        post->discardCount[nextPlayer] = rand() % (MAX_DECK + 1);
        
        //Set up the pre state.
        pre = newGame();
        memcpy (pre, post, sizeof(struct gameState));
        
        playTribute(post, nextPlayer, tributeRevealedCards, currentPlayer);     
        
        //Check out what is happening and see if it is reasonable.
        int counter = 0;
        for (int j = 0; j < 2; j ++) {
            if (tributeRevealedCards[j] != copper && tributeRevealedCards[j] != silver && tributeRevealedCards[j] != gold && tributeRevealedCards[j] != estate && tributeRevealedCards[j] != duchy && tributeRevealedCards[j] != province && tributeRevealedCards[j] != gardens && tributeRevealedCards[j] != great_hall) {
                counter++;
            }
        }
        
        if (counter > 0) {
            assert(post->numActions - 2*counter, pre->numActions, "PASSED: The numOfActions was incremented correctly.", "\n\tERROR: The numOfActions was not incremented by 2.\n");
        }
        
        if ((pre->discardCount[nextPlayer] + pre->deckCount[nextPlayer]) <= 1) {
            if (pre->deckCount[nextPlayer] > 0) {
                assert(post->deckCount[nextPlayer] + 1, pre->deckCount[nextPlayer], "PASSED: The deck count was decremented correctly for the next player.", "\n\tERROR: The deck count was not decremented check the first if block.\n");
            }
            else if (pre->discardCount[nextPlayer] > 0) {
                assert(post->discardCount[nextPlayer] + 1, pre->discardCount[nextPlayer], "PASSED: The discard count was decremented correctly for the next player.", "\n\tERROR: The discard count was not decremented check the first if block.\n");
            }
            else {
                printf("Check the output to see if No cards to reveal was mentioned. If it was this PASSED, if it was not check that the last statement shows if DEBUG not DEBUG + 1\n");
            }
        }
        
        int found = 0;
        int j = 0;
        while (!found && j < 2) {
            if ((tributeRevealedCards[j] != copper && tributeRevealedCards[j] != silver && tributeRevealedCards[j] != gold) || tributeRevealedCards[j] == estate || tributeRevealedCards[j] == duchy || tributeRevealedCards[j] == province || tributeRevealedCards[j] == gardens || tributeRevealedCards[j] == great_hall) { //Victory Card Found
                assert(post->handCount[currentPlayer] - 2, pre->handCount[currentPlayer], "PASSED: Only the currentPlayer drew a card.", "\n\tERROR: The current player did not draw 2 cards, check for error 2.\n");
                found = 1;
            }
            j++;
        }
        
        //Make a new game for the next round.
        post = newGame();
        initializeGame(numOfPlayers, k, numOfPlayers, post);
    }

    printf("Test For The Tribute Function Is Completed.\n");

    return 0;
}