jogador.o: jogador.cpp jogador.hpp
	g++ jogador.cpp -c

dado.o: dado.cpp dado.hpp
	g++ dado.cpp -c

jogo.o: jogo.cpp jogo.hpp jogador.o
	g++ jogo.cpp jogador.o -c

main: main.cpp jogo.o dado.o
	g++ main.cpp jogo.o dado.o -o main

clear:
	rm *.o
	rm main
