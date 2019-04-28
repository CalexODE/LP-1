#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "jogo.hpp"
#include "dado.hpp"

int main()
{
	Dado dado;
	dado.setLados(6);
	std::cout<<"lados: " << dado.getLados() << std::endl;



	//oJogo jogo;
	//jogo.criarDado(6, 1);

	/**
	srand((unsigned)time(0)); //para gerar números aleatórios reais.
    int maior = 6;
    int menor = 1;
    int aleatorio = rand()%(maior-menor+1) + menor;
    std::cout << "Numero Aleatorio = " << aleatorio << std::endl;
    */
	return 0;
}
