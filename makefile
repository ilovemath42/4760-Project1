oss: main.o
	g++ -o oss main.o

main.o: main.cpp
	g++ -c main.cpp
