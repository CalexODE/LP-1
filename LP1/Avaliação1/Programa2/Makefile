jogador.o: jogador.cpp jogador.hpp
	g++ jogador.cpp -c

dado.o: dado.cpp dado.hpp
	g++ dado.cpp -c

jogo.o: jogo.cpp jogo.hpp
	g++ jogo.cpp -c

menu.o:menu.cpp menu.hpp
	g++ menu.cpp -c
main: main.cpp dado.o jogador.o jogo.o menu.o
	g++ main.cpp jogo.o dado.o jogador.o menu.o -o main

clear:
	rm *.o
	rm main
