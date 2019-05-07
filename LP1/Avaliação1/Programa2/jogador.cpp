#include "jogador.hpp"

//Construtor
Jogador::Jogador()
{
	this->pontuacao = 0;
}

//get e set do Nome do jogador
void Jogador::setNome(string nome)
{
	this->nome = nome;
}
string Jogador::getNome()
{
	return this->nome;
}


//get e set da pontuação do jogador
void Jogador::setPontuacao(int pontuacao)
{
	this->pontuacao = pontuacao;
}
int Jogador::getPontuacao()
{
	return this->pontuacao;
}

//incrementa valor(parámetro) à pontuação atual do jogador
void Jogador::aumentarPontuacao(int pontuacao)
{
	this->pontuacao += pontuacao;
}