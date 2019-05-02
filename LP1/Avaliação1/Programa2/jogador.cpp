#include "jogador.hpp"

Jogador::Jogador()
{
	this->pontuacao = 0;
}


void Jogador::setNome(string nome)
{
	this->nome = nome;
}
string Jogador::getNome()
{
	return this->nome;
}

void Jogador::setPontuacao(int pontuacao)
{
	this->pontuacao += pontuacao;
}
int Jogador::getPontuacao()
{
	return this->pontuacao;
}