#include <iostream>
#include <vector>

#include "jogador.hpp"
//#include "dado.hpp"

using namespace std;

class oJogo
{
private:
	vector<Jogador> vecJogadores;
	//Dado dado;
	int nParaAtingir;

public:
	void adicionarJogador(string nome);
	void criarDado(int nLados, int nDados);

	void setNParaAtingir(int n);
	int getNParaAtingir();

	void jogarDado();
};