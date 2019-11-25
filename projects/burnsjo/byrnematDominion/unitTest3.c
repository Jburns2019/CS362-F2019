#include "unitTest.h"

int main() {
    printf("Initialize variables.\n");
    
    //Initialize the integer variables that will be in use.
    int numOfPlayers, nextPlayer, currentPlayer;
    
    //make an edge case to see how the function runs.
    numOfPlayers= 2;
    nextPlayer = 0;
    currentPlayer = 1;
    //Initialize the array like cardEffects does.
    int tributeRevealedCards[2] = {-1, -1};
    
    // set your card array
    int k[10] = { baron, minion, tribute, ambassador, mine, steward, village, smithy, adventurer, feast };
    
    // declare the post game state 
    struct gameState *post = newGame();
    
    //Let the debugger know that testing has started.
    printf("Start Testing For Tribute Function.\n");
      
    // set the game and pre-played state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    struct gameState *pre = newGame();
    memcpy(pre, post, sizeof(struct gameState));
    
    //Check to see if the overview of the function is okay.
    playTribute(post, nextPlayer, tributeRevealedCards, currentPlayer);
    assert(post->numActions - 2, pre->numActions, "PASSED: The numOfActions was incremented correctly.", "\n\tERROR: The numOfActions was not incremented by 2.\n");
    printf("%d, %d\n", post->numActions, pre->numActions);
    
    // set the game again.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    //Change some variables to gain access to a new if statement.
    post->deckCount[nextPlayer] = 1;
    post->discardCount[nextPlayer] = 0;
    playTribute(post, nextPlayer, tributeRevealedCards, currentPlayer);
    assert(post->deckCount[nextPlayer], 0, "PASSED: The deck count was decremented correctly for the next player.", "\n\tERROR: The deck count was not decremented check the first if block.\n");
    
    // set the game again.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    //Change some variables to gain access to a new if statement.
    post->deckCount[nextPlayer] = 0;
    post->discardCount[nextPlayer] = 1;
    playTribute(post, nextPlayer, tributeRevealedCards, currentPlayer);
    assert(post->discardCount[nextPlayer], 0, "PASSED: The discard count was decremented correctly for the next player.", "\n\tERROR: The discard count was not decremented check the first if block.\n");
    
    // set the game again.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    //change the variables to the state needed to get into where the first bug occurs.
    post->deckCount[nextPlayer] = 0;
    post->discardCount[nextPlayer] = 0;
    playTribute(post, nextPlayer, tributeRevealedCards, currentPlayer);
    printf("Check the output to see if No cards to reveal was mentioned. If it was this PASSED, if it was not check that the last statement shows if DEBUG not DEBUG + 1\n");
    
    // set the game again.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    //Set the state in a way that forces the second bug to run.
    currentPlayer = 0;
    nextPlayer = 1;
    post->deckCount[nextPlayer] = 1;
    post->discardCount[nextPlayer] = 0;
    playTribute(post, nextPlayer, tributeRevealedCards, currentPlayer);
    assert(post->handCount[currentPlayer] - 2, pre->handCount[currentPlayer], "PASSED: Only the currentPlayer drew a card.", "\n\tERROR: The current player did not draw 2 cards, check for error 2.\n");
    
    //Let the debugger know that testing is complete.
    printf("Testing For Tribute Function Is Complete.\n");
    return 0;
}
