//#include <iostream>
//#include <ctime>
//#include <stdlib.h>
//#include <string>

//#include "jogo.hpp"
//#include "dado.hpp"
#include "menu.hpp"

//void menu();

int main()
{

	menu();

	return 0;
}
	/**
	oJogo j;

	j.criarDado(10, 2);

	j.mostrarDado();

	j.jogarDado();

	j.adicionarJogador("Alexandre");

	j.adicionarJogador("Outro");

	string nome;
	nome = j.getJogadorAtivos(0);
	std::cout << nome << std::endl;

	j.retirarJogador(1);

	Dado dado;
	dado.setLados(6);
	std::cout<<"lados: " << dado.getLados() << std::endl;



	//oJogo jogo;
	//jogo.criarDado(6, 1);

	srand((unsigned)time(0)); //para gerar números aleatórios reais.
    int maior = 6;
    int menor = 1;
    int aleatorio = rand()%(maior-menor+1) + menor;
    std::cout << "Numero Aleatorio = " << aleatorio << std::endl;
    */
