#include "unitTest.h"

int main() {
    printf("Initialize variables.\n");
    
    //Set the needed integer variables.
    int numOfPlayers, choice1, choice2, choice3, handPos, currentPlayer;
    
    currentPlayer = 0;
    numOfPlayers = 2;
    choice1 = 0;
    choice2 = 0;
    choice3 = 0;
    handPos = 0;
    
    // set the card array
    int k[10] = { embargo, minion, tribute, steward, salvager, ambassador, village, smithy, adventurer, feast };
    
    // declare the post game state 
    struct gameState *post = newGame();
    
    //Let the debugger know that the testing has started.
    printf("Start Testing For The faulty Action Update When Duplicate In Tribute.\n");
      
    // set up the game and pre edited state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    
    post->hand[currentPlayer][0] = tribute;
    post->hand[currentPlayer][1] = gold;
    post->hand[currentPlayer][2] = gold;
    post->hand[currentPlayer][3] = gold;
    post->hand[currentPlayer][4] = gold;
    post->handCount[currentPlayer] = 5;
    post->whoseTurn = 0;
    
    int nextPlayer = currentPlayer + 1;
    post->hand[nextPlayer][0] = tribute;
    post->hand[nextPlayer][1] = gold;
    post->hand[nextPlayer][2] = gold;
    post->hand[nextPlayer][3] = gold;
    post->hand[nextPlayer][4] = gold;
    post->handCount[nextPlayer] = 5;
    
    
    playCard(handPos, choice1, choice2, choice3, post);
    assert(post->numActions == 2, "PASSED: The duplicate cards are getting handled properly.", "\n\tERROR: The duplicate cards are resulting in more actions. Check line 1065\n");
    
    printf("Testing For Faulty Action Update When Duplicate Completed.\n");
    
    return 0;
}