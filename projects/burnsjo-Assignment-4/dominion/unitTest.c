#include "unitTest.h"

void assert(int cond1, int cond2, char *tMess, char *fMess) {
    if (cond2 == cond1) {
        printf("%s \n", tMess);
    }
    else {
        printf("%s \n", fMess);
    }
}