#include "unitTest.h"

int main() {
    printf("Initialize variables.\n");
    
    //Inititalize the integer variables to be used later.
    int currentPlayer, choice1, choice2, handPos, numberOfPlayers;
    
    //Set the values in a way that gets a cursury glance at what happened.
    numberOfPlayers = 2;
    choice1 = 0;
    choice2 = 0;
    currentPlayer = 1;
    handPos = 0;
    
    // set your card array
    int k[10] = { baron, minion, tribute, ambassador, mine, steward, village, smithy, adventurer, feast };
    
    // declare the post game state 
    struct gameState *post = newGame();
    
    //Let the Debugger know that the testing has started.
    printf("Start Testing For The Mine Function.\n");
      
    // set the game and pre-played game.
    initializeGame(numberOfPlayers, k, numberOfPlayers, post);
    struct gameState *pre = newGame();
    memcpy(pre, post, sizeof(struct gameState));
    
    int failure = playMine(post, currentPlayer, choice1, choice2, handPos);
     assert(failure, -1, "PASSED: The card was appropriately not played as the cards selected were of the same value.", "\n\tERROR: The card was played even though it should not have.\n");
    
    //Set the game again.
    initializeGame(numberOfPlayers, k, numberOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    //Force a couple if statements open to look for bug 1.
    post->hand[currentPlayer][1] = mine;
    post->hand[currentPlayer][choice1] = copper;
    choice2 = silver;
    failure = playMine(post, currentPlayer, choice1, choice2, handPos);
    assert(failure, 0, "PASSED: The smallest value choice one can have is correct.", "\n\tERROR: Check that the smallest value you can have is copper not copper+1\n");
    
    //Set the game again.
    initializeGame(numberOfPlayers, k, numberOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    //Set variables to get more coverage.
    post->hand[currentPlayer][choice1] = copper+1;
    choice2 = silver;
    failure = playMine(post, currentPlayer, choice1, choice2, handPos);
    assert(failure, 0, "\n\tERROR: Check that the smallest value you can have is copper not copper+1\n", "PASSED: The smallest value choice one can have is correct.");
    
    
    //Set the game again.
    initializeGame(numberOfPlayers, k, numberOfPlayers, post);
    memcpy(pre, post, sizeof(struct gameState));
    
    //Set variables to get access to bug2.
    currentPlayer = 1;
    post->hand[currentPlayer][choice1] = silver;
    choice2 = gold;
    playMine(post, currentPlayer, choice1, choice2, handPos);
    assert(post->hand[currentPlayer][choice1], pre->hand[currentPlayer][choice1], "\n\tERROR: The previous player is having their card swapped instead of the currentPlayer.\n", "PASSED: The current player is having their deck changed.");
    
    printf("Testing For The Mine Function Is Completed.\n");
    
    return 0;
}
