#include "jogador.hpp"
#include "dado.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class oJogo
{
private:
	vector<Jogador> vecJogadoresAtivos;
	vector<Jogador> vecJogadoresFora;
	vector<int> ordemDeVitoria;

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

	int pontuacaoDoJogador(int i);

	int totalDeJogadores();
	int totalDeJogadoresF();

	void jogarDado(int i);

	//alterar nome
	string getNomeJogadorAtivo(int i);
	int getPontuacaoJogadorAtivo(int i);

	void retirarJogador(int i, int c);

	void organizarVencedores();

	string getNomeJogadorFora(int i);
	int getPontuacaoJogadorFora(int i);
};