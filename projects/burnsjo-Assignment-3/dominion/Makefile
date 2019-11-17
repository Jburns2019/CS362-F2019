CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

unitTest.o: unitTest.h unitTest.c dominion.o; \
  gcc -c unitTest.c -g $(CFLAG)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: dominion.o testdrawcard.c; \
gcc -o testDrawCard testdrawcard.c -g dominion.o rngs.o $(CFLAGS)

unitTest1: dominion.o unitTest.o unitTest1.c; \
gcc  -o  unitTest1  unitTest1.c  -g  dominion.o  rngs.o  unitTest.o $(CFLAGS)

unitTest2: dominion.o unitTest.o unitTest2.c; \
gcc  -o  unitTest2  unitTest2.c  -g  dominion.o  rngs.o  unitTest.o $(CFLAGS)

unitTest3: dominion.o unitTest.o unitTest3.c; \
gcc  -o  unitTest3  unitTest3.c  -g  dominion.o  rngs.o  unitTest.o $(CFLAGS)

unitTest4: dominion.o unitTest.o unitTest4.c; \
gcc  -o  unitTest4  unitTest4.c  -g  dominion.o  rngs.o  unitTest.o $(CFLAGS)

unitTest5: dominion.o unitTest.o unitTest5.c; \
gcc  -o  unitTest5  unitTest5.c  -g  dominion.o  rngs.o unitTest.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runUnitTest1: unitTest1; \
  ./unitTest1 &> unitTest1Result.out; \
  gcov -b -f dominion.c >> unitTest1Result.out; \
  cat dominion.c.gcov >> unitTest1Result.out

runUnitTest2: unitTest2; \
  ./unitTest2 &> unitTest2Result.out; \
  gcov -b -f dominion.c >> unitTest2Result.out; \
  cat dominion.c.gcov >> unitTest2Result.out

runUnitTest3: unitTest3; \
  ./unitTest3 &> unitTest3Result.out; \
  gcov -b -f dominion.c >> unitTest3Result.out; \
  cat dominion.c.gcov >> unitTest3Result.out

runUnitTest4: unitTest4; \
  ./unitTest4 &> unitTest4Result.out; \
  gcov -b -f dominion.c >> unitTest4Result.out; \
  cat dominion.c.gcov >> unitTest4Result.out

runUnitTest5: unitTest5; \
  ./unitTest5 &> unitTest5Result.out; \
  gcov -b -f dominion.c >> unitTest5Result.out; \
  cat dominion.c.gcov >> unitTest5Result.out

runTestDrawCard: testDrawCard; \
  ./testDrawCard &> unitTestDResult.out; \
	gcov -b -f dominion.c >> unitTestDResult.out; \
	cat dominion.c.gcov >> unitTestDResult.out


unittestresults: testDrawCard unitTest1 unitTest2 unitTest3 unitTest4 unitTest5; \
  ./unitTest1 &> unitTest1Result.out; \
  ./unitTest2 &> unitTest2Result.out; \
  ./unitTest3 &> unitTest3Result.out; \
  ./unitTest4 &> unitTest4Result.out; \
  ./unitTest5 &> unitTest5Result.out; \
  ./testDrawCard &> unitTestDResult.out; \
  cat unitTest1Result.out >> unitTestResult.out; \
  cat unitTest2Result.out >> unitTestResult.out; \
  cat unitTest3Result.out >> unitTestResult.out; \
  cat unitTest4Result.out >> unitTestResult.out; \
  cat unitTest5Result.out >> unitTestResult.out; \
  cat unitTestDResult.out >> unitTestResult.out; \
  gcov -b -f dominion.c >> unitTestResult.out; \
	cat dominion.c.gcov >> unitTestResult.out; \
  cat unitTestResult.out
  
  
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out *.exe testDrawCard unitTest1 unitTest2 unitTest3 unitTest4 unitTest5
