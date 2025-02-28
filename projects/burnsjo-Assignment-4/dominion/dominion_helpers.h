#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state,
                int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int baronHelper(struct gameState *state, int choice1, int currentPlayer);
int minionHelper(struct gameState *state, int handPos, int currentPlayer, int choice1, int choice2);
int tributeHelper(struct gameState *state, int nextPlayer, int currentPlayer, int tributeRevealedCards[]);
int ambassadorHelper(int choice1, int choice2, int handPos, struct gameState *state, int currentPlayer);
int mineHelper(int currentPlayer, int choice1, int choice2, struct gameState *state, int handPos);
int cardEffect(int card, int choice1, int choice2, int choice3,
               struct gameState *state, int handPos, int *bonus);

#endif
