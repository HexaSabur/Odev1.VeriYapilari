all: derle calistir

derle:
	g++ -I ./include/ -o ./lib/DosyaOku.o -c ./src/DosyaOku.cpp
	g++ -I ./include/ -o ./lib/Gen.o -c ./src/Gen.cpp
	g++ -I ./include/ -o ./lib/BD.o -c ./src/BD.cpp
	g++ -I ./include/ -o ./lib/DNA.o -c ./src/DNA.cpp
	g++ -I ./include/ -o ./lib/Kromozom.o -c ./src/Kromozom.cpp
	g++ -I ./include/ -o ./bin/Main ./lib/DosyaOku.o ./lib/Gen.o ./lib/BD.o ./lib/DNA.o ./lib/Kromozom.o ./src/Main.cpp

calistir:
	./bin/Main