#include "dado.hpp"

//get e set do número de lados do dado
void Dado::setLados(int n)
{
	this->nLados = n;
}
int Dado::getLados()
{
	return this->nLados;
}

//get e set do número de dados
void Dado::setDados(int n)
{
	this->nDados = n;
}
int Dado::getDados()
{
	return this->nDados;
}

//Função para "jogar"(gera números aleatórios) os dados baseado no número de lados e quantidade de dados
//Retorna a soma dos dados jogados
int Dado::jogarDados()
{
	int somaDosDados = 0;
	for (int i = 0; i <= nDados-1; i++)
	{
	    srand((unsigned)time(0)); //para gerar números aleatórios reais.
	    int maior = nLados;
	    int menor = 1;
	    int aleatorio = rand()%(maior-menor+1) + menor;
	    somaDosDados += aleatorio;
	   	std::cout << "Dado "<<i+1<<": "<< aleatorio<< std::endl;
	   	usleep(1000000);//1 segundo = 1000000
	}
	return somaDosDados;
}