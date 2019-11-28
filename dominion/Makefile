CFLAGS= -Wall -fpic -coverage -lm -std=c99



#header files:
rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

JohnsCorrectedDominion.o: dominion.h JohnsCorrectedDominion.c rngs.o
	gcc -c JohnsCorrectedDominion.c -g  $(CFLAGS)

unitTest.o: unitTest.h unitTest.c JohnsCorrectedDominion.o; \
  gcc -c unitTest.c -g $(CFLAG)



#running individual files:
playdom: JohnsCorrectedDominion.o playdom.c
	gcc -o playdom playdom.c -g JohnsCorrectedDominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: JohnsCorrectedDominion.o testdrawcard.c; \
  gcc -o testDrawCard testdrawcard.c -g JohnsCorrectedDominion.o rngs.o $(CFLAGS)

unitTest8: JohnsCorrectedDominion.o unitTest.o unittest8.c; \
  gcc  -o  unitTest8  unittest8.c  -g  JohnsCorrectedDominion.o  rngs.o  unitTest.o $(CFLAGS)

unitTest9: JohnsCorrectedDominion.o unitTest.o unittest9.c; \
  gcc  -o  unitTest9  unittest9.c  -g  JohnsCorrectedDominion.o  rngs.o  unitTest.o $(CFLAGS)

unitTest10: JohnsCorrectedDominion.o unitTest.o unittest10.c; \
  gcc  -o  unitTest10  unittest10.c  -g  JohnsCorrectedDominion.o  rngs.o  unitTest.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)



#individual tests:
runUnitTest8: unitTest8; \
  ./unitTest8 &> unitTest8Result.out; \
  gcov -b -f JohnsCorrectedDominion.c >> unitTest8Result.out; \
  cat JohnsCorrectedDominion.c.gcov >> unitTest8Result.out

runUnitTest9: unitTest9; \
  ./unitTest9 &> unitTest9Result.out; \
  gcov -b -f JohnsCorrectedDominion.c >> unitTest9Result.out; \
  cat JohnsCorrectedDominion.c.gcov >> unitTest9Result.out

runUnitTest10: unitTest10; \
  ./unitTest10 &> unitTest10Result.out; \
  gcov -b -f JohnsCorrectedDominion.c >> unitTest10Result.out; \
  cat JohnsCorrectedDominion.c.gcov >> unitTest10Result.out

runTestDrawCard: testDrawCard; \
  ./testDrawCard &> unitTestDResult.out; \
	gcov -b -f JohnsCorrectedDominion.c >> unitTestDResult.out; \
	cat JohnsCorrectedDominion.c.gcov >> unitTestDResult.out



#group tests:
unittestresults: unitTest8 unitTest9 unitTest10; \
  ./unitTest8 &> unitTestResults.out; \
  ./unitTest9 >> unitTestResults.out; \
  ./unitTest10 >> unitTestResults.out; \
  gcov -b -f JohnsCorrectedDominion.c >> unitTestResults.out; \
	cat JohnsCorrectedDominion.c.gcov >> unitTestResults.out; \
  cat unitTestResults.out

testresults: testDrawCard unitTest8 unitTest9 unitTest10; \
  ./unitTest8 &> testResults.out; \
  ./unitTest9 >> testResults.out; \
  ./unitTest10 >> testResults.out; \
  ./testDrawCard >> testResults.out; \
  gcov -b -f JohnsCorrectedDominion.c >> testResults.out; \
	cat JohnsCorrectedDominion.c.gcov >> testResults.out; \
  cat testResults.out

#Player setup:
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player



#Cleanup:
clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out *.exe playdom player testDrawCard unitTest8 unitTest9 unitTest10

