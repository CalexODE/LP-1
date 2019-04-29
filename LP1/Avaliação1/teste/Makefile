
bola.o:bola.cpp bola.hpp
	g++ bola.cpp -c

pessoa.o:pessoa.cpp pessoa.hpp bola.o
	g++ pessoa.cpp bola.o -c

main:main.cpp pessoa.o bola.o
	g++ main.cpp pessoa.o bola.o -o main

clear:
	rm *.o
	rm main;
