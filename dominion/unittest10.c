#include "unitTest.h"

int main() {
    printf("Initialize variables.\n");
    
    //Set the needed integer variables.
    int numOfPlayers, choice1, choice2, choice3, handPos, currentPlayer;
    
    currentPlayer = 0;
    numOfPlayers = 2;
    choice1 = 1;
    choice2 = 2;
    choice3 = 0;
    handPos = 0;
    
    // set the card array
    int k[10] = { embargo, minion, tribute, steward, salvager, ambassador, village, smithy, adventurer, feast };
    
    // declare the post game state 
    struct gameState *post = newGame();
    
    //Let the debugger know that the testing has started.
    printf("Start Testing For The faulty Duplicate Incrementing In The Ambassador Switch Statement.\n");
      
    // set up the game and pre edited state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    
    post->hand[currentPlayer][0] = ambassador;
    post->hand[currentPlayer][1] = silver;
    post->hand[currentPlayer][2] = silver;
    post->hand[currentPlayer][3] = silver;
    post->hand[currentPlayer][4] = gold;
    post->handCount[currentPlayer] = 5;
    post->whoseTurn = 0;
        
    int check = playCard(handPos, choice1, choice2, choice3, post);
    assert(check == 0, "PASSED: The number of duplicates is increased correctly.", "\n\tERROR: The number of duplicates is not increasing correctly. Check line 1102\n");
    
    printf("Testing For Faulty Duplicate Incrementing Is Completed.\n");
    
    return 0;
}