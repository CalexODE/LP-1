#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>


using namespace std;

class Dado
{
private:
	int nLados;
	int nDados;

public:
	//Dado();
	//Dado(int nLados, int nDados);
	void setLados(int n);
	int getLados();

	void setDados(int n);
	int getNumDados();

	int jogarDados();
};