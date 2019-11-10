#include "unitTest.h"

int main() {
    printf("Initialize variables.\n");
    
    //Initialize the integer values to be used.
    int numOfPlayers, choice1, choice2, handPos, currentPlayer;
    
    //Set the variables in a way that gets a curser glance of how the function is behaving.
    numOfPlayers = 2;
    choice1 = 1;
    choice2 = 2;
    handPos = 0;
    currentPlayer = 0;
    
    // set your card array
    int k[10] = { baron, minion, tribute, ambassador, mine, steward, village, smithy, adventurer, feast };
    
    // declare the post game state 
    struct gameState *post = newGame();
    
    //Let the debugger know that testing has started.
    printf("Start Testing For Ambassador Function.\n");
      
    // set the game and pre-game state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    struct gameState *pre = newGame();
    memcpy(pre, post, sizeof(struct gameState));
    
    //Luckily for me there are not too many if statements so maximum coverage is achieved with only one call. This means I have to test both assertions thoug.
    ambassadorHelper(choice1, choice2, handPos, post, currentPlayer);
     assert(post->supplyCount[post->hand[currentPlayer][choice1]] - choice2, pre->supplyCount[pre->hand[currentPlayer][choice1]], "PASSED: The supply count of the given card was increased properly.", "\n\tERROR: The supply count of the given card was not increased properly. Check for bug 2.\n");
     printf("Check the output. If player 1 had their cards revealed PASSED. If another player had their cards revealed then ERROR.\n");     
    
    //Let the debugger know that the testing of the function is done.
    printf("Tests For Ambassador Function Is completed.\n");
    
    return 0;
}
