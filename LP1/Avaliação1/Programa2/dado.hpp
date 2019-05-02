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
	void setLados(int n);
	int getLados();

	void setDados(int n);
	int getNumDados();

	int jogarDados();
};