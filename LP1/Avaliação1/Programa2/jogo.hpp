#include "jogador.hpp"
#include "dado.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class oJogo
{
private:
	vector<Jogador> vecJogadoresAtivos;//Jogadores que estão na rodada
	vector<Jogador> vecJogadoresFora;//Jogadores fora do rodada por perder o parar

	Dado dado;
	int nParaAtingir;//Valor máximo para atingir
	int valorAtual;

public:
	oJogo();

	void adicionarJogador(string nome);
	void criarDado(int nDados, int nLados);

	void setNParaAtingir(int n);
	int getNParaAtingir();

	int pontuacaoDoJogador(int i);

	int totalDeJogadores();
	int totalDeJogadoresF();

	void jogarDado(int i);

	string getNomeJogadorAtivo(int i);
	int getPontuacaoJogadorAtivo(int i);

	void retirarJogador(int i, int c);

	void organizarVencedores();

	string getNomeJogadorFora(int i);
	int getPontuacaoJogadorFora(int i);
};