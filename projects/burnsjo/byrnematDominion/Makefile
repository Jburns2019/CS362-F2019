CFLAGS= -Wall -fpic -coverage -lm -std=c99



#header files:
rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

unitTest.o: unitTest.h unitTest.c dominion.o; \
  gcc -c unitTest.c -g $(CFLAG)



#running individual files:
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

randomtestcard1: dominion.o unitTest.o randomtestcard1.c; \
  gcc  -o  randomtestcard1  randomtestcard1.c  -g  dominion.o  rngs.o unitTest.o $(CFLAGS)

randomtestcard2: dominion.o unitTest.o randomtestcard2.c; \
  gcc  -o  randomtestcard2  randomtestcard2.c  -g  dominion.o  rngs.o unitTest.o $(CFLAGS)
  
randomtestcard3: dominion.o unitTest.o randomtestcard3.c; \
  gcc  -o  randomtestcard3  randomtestcard3.c  -g  dominion.o  rngs.o unitTest.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)



#individual tests:
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

runRandomTest1: randomtestcard1; \
  ./randomtestcard1 &> randomtestcard1.out; \
  gcov -b -f dominion.c >> randomtestcard1.out; \
  cat dominion.c.gcov  >> randomtestcard1.out

runRandomTest2: randomtestcard2; \
  ./randomtestcard2 &> randomtestcard2.out; \
  gcov -b -f dominion.c >> randomtestcard2.out; \
  cat dominion.c.gcov  >> randomtestcard2.out

runRandomTest3: randomtestcard3; \
  ./randomtestcard3 &> randomtestcard3.out; \
  gcov -b -f dominion.c >> randomtestcard3.out; \
  cat dominion.c.gcov >> randomtestcard3.out



#group tests:
randomtestresults: randomtestcard1 randomtestcard2 randomtestcard3; \
  ./randomtestcard1 &> randomtestresults.out; \
  ./randomtestcard2 >> randomtestresults.out; \
  ./randomtestcard3 >> randomtestresults.out; \
  gcov -b -f dominion.c >> randomtestresults.out; \
  cat dominion.c.gov >> randomtestresults.out; \
  cat randomtestresults.out

unittestresults: testDrawCard unitTest1 unitTest2 unitTest3 unitTest4 unitTest5; \
  ./unitTest1 &> unitTestResults.out; \
  ./unitTest2 >> unitTestResults.out; \
  ./unitTest3 >> unitTestResults.out; \
  ./unitTest4 >> unitTestResults.out; \
  ./unitTest5 >> unitTestResults.out; \
  ./testDrawCard >> unitTestResults.out; \
  gcov -b -f dominion.c >> unitTestResults.out; \
	cat dominion.c.gcov >> unitTestResults.out; \
  cat unitTestResults.out

testresults: testDrawCard unitTest1 unitTest2 unitTest3 unitTest4 unitTest5 randomtestcard1 randomtestcard2 randomtestcard3; \
  ./unitTest1 &> testResults.out; \
  ./unitTest2 >> testResults.out; \
  ./unitTest3 >> testResults.out; \
  ./unitTest4 >> testResults.out; \
  ./unitTest5 >> testResults.out; \
  ./testDrawCard >> testResults.out; \
  ./randomtestcard1 >> testResults.out; \
  ./randomtestcard2 >> testResults.out; \
  ./randomtestcard3 >> testResults.out; \
  gcov -b -f dominion.c >> testResults.out; \
	cat dominion.c.gcov >> testResults.out; \
  cat testResults.out

#Player setup:
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player



#Cleanup:
clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out *.exe playdom player testDrawCard unitTest1 unitTest2 unitTest3 unitTest4 unitTest5 randomtestcard1 randomtestcard2 randomtestcard3
