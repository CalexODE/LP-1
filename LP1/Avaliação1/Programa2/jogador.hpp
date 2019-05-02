#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class Jogador
{
private:
	string nome;
	int pontuacao;

public:
	Jogador();

	void setNome(string nome);
	string getNome();

	void setPontuacao(int pontuacao);
	int getPontuacao();

};