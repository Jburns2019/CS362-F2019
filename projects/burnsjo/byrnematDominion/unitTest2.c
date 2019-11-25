#include "unitTest.h"

int main() {
    printf("Initialize variables.\n");
    
    //Declare the integer variables that will be used.
    int numOfPlayers, choice1, choice2, handPos, currentPlayer;
    
    //Set the values of choice1, and choice2 to be 0 to check to see if the function checks em properly.
    numOfPlayers = 2;
    choice1 = 0;
    choice2 = 0;
    handPos = 0;
    currentPlayer = 1;
    
    // set your card array
    int k[10] = { baron, minion, tribute, ambassador, mine, steward, village, smithy, adventurer, feast };
    
    // declare the post game state 
    struct gameState *post = newGame();
    
    //Let the player know that the testing is beginning.
    printf("Start Testing The Minion Function.\n");
      
    // set the game and pre played state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    struct gameState *pre = newGame();
    memcpy(pre, post, sizeof(struct gameState));
    
     // Do a glossery check to ensure basic functionality supports playing.
    playMinion(post, handPos, currentPlayer, choice1, choice2);
     assert(post->numActions - 1, pre->numActions, "PASSED: The number of actions was incremented correctly.", "\n\tERROR: The num of actions was not incremented by 1 check for bug 1.\n");
     
     // set the game again.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    //change choice1 to 1 so that an ifstatement can be breached.
    choice1 = 1;
     playMinion(post, handPos, currentPlayer, choice1, choice2);
     assert(post->coins - 2, pre->coins, "PASSED: The number of coins was incremented correctly.", "\n\tERROR: The num of coins was not incremented by 2 check inside the first if statement.\n");
     
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    // change some variables so that another if statement can be breached.
    choice1 = 0;
    choice2 = 1;
    post->whoseTurn = currentPlayer;
     playMinion(post, handPos, currentPlayer, choice1, choice2);
    assert(post->playedCardCount - 1, pre->playedCardCount, "PASSED: The number of played cards was decremented correctly.", "\n\tERROR: The num of played cards was not decremented check for bug 2 in while loop.\n");
    printf("%d, %d\n", post->playedCardCount, pre->playedCardCount);
     
    //Tell the debugger that the testing is done.
    printf("Test For The Minion Function Is Completed.\n");
    
    return 0;
}
