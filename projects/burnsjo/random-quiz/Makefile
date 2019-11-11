CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: ; \
    gcc -o testme testme.c -g $(CFLAGS)

run: testme; \
    ./testme; \
    gcov -b -f testme.c; \
    cat testme.c.gcov

clean:; \
    rm -f *.o *.gcov *.gcda *.gcno testme