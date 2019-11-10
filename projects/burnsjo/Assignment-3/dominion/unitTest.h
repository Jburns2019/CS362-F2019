#ifndef _UNIT_TEST_H
#define _UNIT_TEST_H

#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

#define DEBUG 1
#define NOISY_TEST 1

void assert(int cond1, int cond2, char *tMess, char *fMess);

#endif