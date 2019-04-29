#include "dado.hpp"
/**
Dado::Dado()
{

}

Dado::Dado(int nLados = 6, int nDados = 1)
{
	this->nLados = nLados;
	this->nDados = nDados;
}
*/
void Dado::setLados(int n)
{
	this->nLados = n;
}
int Dado::getLados()
{
	return this->nLados;
}

void Dado::setDados(int n)
{
	this->nDados = n;
}
int Dado::getNumDados()
{
	return this->nDados;
}

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
	   	std::cout << "Numero Aleatorio = " << aleatorio << std::endl;
	   	usleep(1000000);//1 segundo = 1000000
	}
	return somaDosDados;
}