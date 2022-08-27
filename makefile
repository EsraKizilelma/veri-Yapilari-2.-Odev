all: compile run

compile:
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Radix.o ./lib/AVL.o ./lib/Node.o ./lib/Dosya.o ./src/Test.cpp
	
run:
	./bin/Test