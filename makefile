P1: main.o scanner.o FSAT.o testScanner.o tokens.o
	g++ -o P1 main.o scanner.o FSAT.o testScanner.o tokens.o

main.o: main.cpp testScanner.h
	g++ -c main.cpp

testScanner.o: testScanner.cpp scanner.h FSAT.h token.h
	g++ -c testScanner.cpp

scanner.o: scanner.cpp tokens.h token.h
	g++ -c scanner.cpp token.h

FSAT.o: FSAT.cpp
	g++ -c FSAT.cpp

tokens.o: tokens.cpp
	g++ -c tokens.cpp

