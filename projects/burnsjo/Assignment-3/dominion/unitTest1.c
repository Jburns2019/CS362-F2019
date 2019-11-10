#include "unitTest.h"

int main() {
    printf("Initialize variables.\n");
    
    //Set the needed integer variables.
    int numOfPlayers, choice1, currentPlayer;
    
    //make the current player the 2nd player (0 indexed) and the choice be 0.
    currentPlayer = 1;
    numOfPlayers = 2;
    choice1 = 0;
    
    // set the card array
    int k[10] = { baron, minion, tribute, ambassador, mine, steward, village, smithy, adventurer, feast };
    
    // declare the post game state 
    struct gameState *post = newGame();
    
    //Let the debugger know that the testing has started.
    printf("Start Testing For The Baron Function.\n");
      
    // set up the game and pre edited state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    struct gameState *pre = newGame();
    memcpy(pre, post, sizeof(struct gameState));
     
    
    baronHelper(post, choice1, currentPlayer);
    assert(post->numBuys - 1, pre->numBuys, "PASSED: The numOfBuys was incremented correctly.", "\n\tERROR: The numOfBuys was not incremented.\n");
    
    //Set up the game again for another test.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    //change choice1 to 1 so that an if statement can be breached. Checking for bug2, if it occurs then the function fails and the coverage is not obtained. 
    choice1 = 1;
    int failure = baronHelper(post, choice1, currentPlayer);
    //check for bug 2.
    assert(failure, -1, "\n\tERROR: The while loop is not 0.\n", "PASSED: The while loop is set to 0.");
    
    //Set up the game again for another test.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    //change the hand that is checked first so that the if statement runs.
    post->hand[currentPlayer][0] = estate;
    baronHelper(post, choice1, currentPlayer);
    assert(post->coins - 4, pre->coins, "PASSED: The coins were incremented correctly if there is an estate card and choice1 is 1.", "\n\tERROR: The coins were not incremented by 4 properly.\n");
    
    printf("Test For The Baron Function Is Completed.\n");
    
    return 0;
}
