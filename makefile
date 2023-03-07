main: main.o driver.o FSAT.o testScanner.o tokens.o
	g++ -o main main.o driver.o FSAT.o testScanner.o tokens.o

main.o: main.cpp driver.h
	g++ -c main.cpp

driver.o: driver.cpp testScanner.h FSAT.h
	g++ -c driver.cpp

testScanner.o: testScanner.cpp tokens.h
	g++ -c testScanner.cpp

FSAT.o: FSAT.cpp
	g++ -c FSAT.cpp

tokens.o: tokens.cpp
	g++ -c tokens.cpp

