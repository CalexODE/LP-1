#include "jogador.hpp"
#include "dado.hpp"

#include <iostream>
#include <vector>


using namespace std;

class oJogo
{
private:
	vector<Jogador> vecJogadoresAtivos;
	vector<Jogador> vecJogadoresFora;
	Dado dado;
	int nParaAtingir;
	int valorAtual;

public:
	oJogo();

	void adicionarJogador(string nome);
	void criarDado(int nLados, int nDados);

	void setNParaAtingir(int n);
	int getNParaAtingir();

	void mostrarDado();//Para monitoramento

	void jogarDado();
};