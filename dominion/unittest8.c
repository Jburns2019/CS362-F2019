#include "unitTest.h"

void checkOutMinion(int numOfPlayers, int choice1, int choice2, int choice3, int handPos, int currentPlayer) {

    currentPlayer = 0;
    numOfPlayers = 2;
    choice1 = 1;
    choice2 = 0;
    choice3 = 0;
    handPos = 0;
    
    // set the card array
    int k[10] = { embargo, minion, tribute, steward, salvager, ambassador, village, smithy, adventurer, feast };
    
    // declare the post game state 
    struct gameState *post = newGame();
      
    // set up the game and pre edited state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    
    post->hand[currentPlayer][0] = minion;
    post->hand[currentPlayer][1] = silver;
    post->hand[currentPlayer][2] = silver;
    post->hand[currentPlayer][3] = silver;
    post->hand[currentPlayer][4] = silver;
    post->handCount[currentPlayer] = 5;
    post->whoseTurn = 0;
            
    int runningTotal = 0;
    for (int i = 0; i < post->handCount[currentPlayer]; i++) {
        if (post->hand[currentPlayer][i] == copper)
        {
            runningTotal += 1;
        }
        else if (post->hand[currentPlayer][i] == silver)
        {
            runningTotal += 2;
        }
        else if (post->hand[currentPlayer][i] == gold)
        {
            runningTotal += 3;
        }
    }
    playCard(handPos, choice1, choice2, choice3, post);
    assert(post->coins - runningTotal != 0, "PASSED: The coins are getting increased in the minion switch case.", "\n\tERROR: The coins are not getting incremented correctly in the minion switch case. Check line 964\n");
    
    return;
}

void checkOutSteward(int numOfPlayers, int choice1, int choice2, int choice3, int handPos, int currentPlayer) {

    currentPlayer = 0;
    numOfPlayers = 2;
    choice1 = 2;
    choice2 = 0;
    choice3 = 0;
    handPos = 0;
    
    // set the card array
    int k[10] = { embargo, minion, tribute, steward, salvager, ambassador, village, smithy, adventurer, feast };
    
    // declare the post game state 
    struct gameState *post = newGame();
      
    // set up the game and pre edited state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    
    post->hand[currentPlayer][0] = steward;
    post->hand[currentPlayer][1] = silver;
    post->hand[currentPlayer][2] = silver;
    post->hand[currentPlayer][3] = silver;
    post->hand[currentPlayer][4] = silver;
    post->handCount[currentPlayer] = 5;
    post->whoseTurn = 0;
    
    int runningTotal = 0;
    for (int i = 0; i < post->handCount[currentPlayer]; i++) {
        if (post->hand[currentPlayer][i] == copper)
        {
            runningTotal += 1;
        }
        else if (post->hand[currentPlayer][i] == silver)
        {
            runningTotal += 2;
        }
        else if (post->hand[currentPlayer][i] == gold)
        {
            runningTotal += 3;
        }
    }
    playCard(handPos, choice1, choice2, choice3, post);
    assert(post->coins - runningTotal != 0, "PASSED: The coins are getting increased in the steward switch case.", "\n\tERROR: The coins are not getting incremented correctly in the steward switch case. Check line 1015\n");
    
    return;
}

void checkOutTribute(int numOfPlayers, int choice1, int choice2, int choice3, int handPos, int currentPlayer) {

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
      
    // set up the game and pre edited state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    
    post->hand[currentPlayer][0] = tribute;
    post->hand[currentPlayer][1] = silver;
    post->hand[currentPlayer][2] = silver;
    post->hand[currentPlayer][3] = silver;
    post->hand[currentPlayer][4] = silver;
    post->handCount[currentPlayer] = 5;
    post->whoseTurn = 0;
    
    int nextPlayer = currentPlayer + 1;
    post->hand[nextPlayer][0] = tribute;
    post->hand[nextPlayer][1] = gold;
    post->hand[nextPlayer][2] = gold;
    post->hand[nextPlayer][3] = gold;
    post->hand[nextPlayer][4] = gold;
    post->handCount[nextPlayer] = 5;
    
    int runningTotal = 0;
    for (int i = 0; i < post->handCount[currentPlayer]; i++) {
        if (post->hand[currentPlayer][i] == copper)
        {
            runningTotal += 1;
        }
        else if (post->hand[currentPlayer][i] == silver)
        {
            runningTotal += 2;
        }
        else if (post->hand[currentPlayer][i] == gold)
        {
            runningTotal += 3;
        }
    }
    playCard(handPos, choice1, choice2, choice3, post);
    assert(post->coins - runningTotal != 0, "PASSED: The coins are getting increased in the tribute switch case.", "\n\tERROR: The coins are not getting incremented correctly in the tribute switch case. Check line 1073\n");
    
    return;
}

void checkOutEmbargo(int numOfPlayers, int choice1, int choice2, int choice3, int handPos, int currentPlayer) {

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
      
    // set up the game and pre edited state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    
    post->hand[currentPlayer][0] = embargo;
    post->hand[currentPlayer][1] = silver;
    post->hand[currentPlayer][2] = silver;
    post->hand[currentPlayer][3] = silver;
    post->hand[currentPlayer][4] = silver;
    post->handCount[currentPlayer] = 5;
    post->whoseTurn = 0;
            
    int runningTotal = 0;
    for (int i = 0; i < post->handCount[currentPlayer]; i++) {
        if (post->hand[currentPlayer][i] == copper)
        {
            runningTotal += 1;
        }
        else if (post->hand[currentPlayer][i] == silver)
        {
            runningTotal += 2;
        }
        else if (post->hand[currentPlayer][i] == gold)
        {
            runningTotal += 3;
        }
    }
    playCard(handPos, choice1, choice2, choice3, post);
    assert(post->coins - runningTotal != 0, "PASSED: The coins are getting increased in the embargo switch case.", "\n\tERROR: The coins are not getting incremented correctly in the embargo switch case. Check line 1182\n");
    
    return;
}

void checkOutSalvager(int numOfPlayers, int choice1, int choice2, int choice3, int handPos, int currentPlayer) {

    currentPlayer = 0;
    numOfPlayers = 2;
    choice1 = 1;
    choice2 = 0;
    choice3 = 0;
    handPos = 0;
    
    // set the card array
    int k[10] = { embargo, minion, tribute, steward, salvager, ambassador, village, smithy, adventurer, feast };
    
    // declare the post game state 
    struct gameState *post = newGame();
      
    // set up the game and pre edited state.
    initializeGame(numOfPlayers, k, numOfPlayers, post);
    
    post->hand[currentPlayer][0] = salvager;
    post->hand[currentPlayer][1] = silver;
    post->hand[currentPlayer][2] = silver;
    post->hand[currentPlayer][3] = silver;
    post->hand[currentPlayer][4] = silver;
    post->handCount[currentPlayer] = 5;
    post->whoseTurn = 0;
            
    int runningTotal = 0;
    for (int i = 0; i < post->handCount[currentPlayer] - 1; i++) {
        if (post->hand[currentPlayer][i] == copper)
        {
            runningTotal += 1;
        }
        else if (post->hand[currentPlayer][i] == silver)
        {
            runningTotal += 2;
        }
        else if (post->hand[currentPlayer][i] == gold)
        {
            runningTotal += 3;
        }
    }
    playCard(handPos, choice1, choice2, choice3, post);
    assert(post->coins - runningTotal != 0, "PASSED: The coins are getting increased in the salvager switch case.", "\n\tERROR: The coins are not getting incremented correctly in the salvager switch case. Check line 1212\n");
    
    return;
}


int main() {
    printf("Initialize variables.\n");
    
    //Set the needed integer variables.
    int numOfPlayers = 0, choice1 = 0, choice2 = 0, choice3 = 0, handPos = 0, currentPlayer = 0;
    
    //Let the debugger know that the testing has started.
    printf("Start Testing For The faulty Coin Updating In CardEffects.\n");
    
    checkOutMinion(numOfPlayers, choice1, choice2, choice3, handPos, currentPlayer);
    
    checkOutSteward(numOfPlayers, choice1, choice2, choice3, handPos, currentPlayer);
    
    checkOutTribute(numOfPlayers, choice1, choice2, choice3, handPos, currentPlayer);
    
    checkOutEmbargo(numOfPlayers, choice1, choice2, choice3, handPos, currentPlayer);
    
    checkOutSalvager(numOfPlayers, choice1, choice2, choice3, handPos, currentPlayer);
    
    printf("Testing For Faulty Coin Updating Is Completed.\n");
    
    return 0;
}