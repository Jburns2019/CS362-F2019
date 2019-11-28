#include "unitTest.h"

void assert(int conditional, char *tMess, char *fMess) {
    conditional %= 2;
    if (conditional < 0) {
        conditional = 0 - conditional;
    }
    
    if (conditional) {
        printf("%s \n", tMess);
    }
    else {
        printf("%s \n", fMess);
    }
}