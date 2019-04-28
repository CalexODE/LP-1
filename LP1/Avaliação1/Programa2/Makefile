jogador.o: jogador.cpp jogador.hpp
	g++ jogador.cpp -c

dado.o: dado.cpp dado.hpp
	g++ dado.cpp -c

jogo.o: jogo.cpp jogo.hpp dado.o jogador.o
	g++ jogo.cpp jogador.o dado.o -c

main: main.cpp jogo.o
	g++ main.cpp jogo.o -o main

clear:
	rm *.o
	rm main
