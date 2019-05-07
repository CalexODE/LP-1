#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>


using namespace std;

class Dado
{
private:
	int nLados;//Número de lados
	int nDados;//Número de dados

public:
	void setLados(int n);
	int getLados();

	void setDados(int n);
	int getDados();

	int jogarDados();
};