#include "jogo.hpp"

oJogo::oJogo()
{

}

void oJogo::adicionarJogador(string nome)
{
	//Não deixar usuário colocar jogadores com o mesmo nome
	Jogador j;
	j.setNome(nome);
	vecJogadoresAtivos.push_back(j);
}
void oJogo::criarDado(int nLados, int nDados)
{
	Dado dado;
	dado.setLados(nLados);
	dado.setDados(nDados);
	this->dado = dado;
	cout << "Lados: " << dado.getLados() << endl;
}

void oJogo::setNParaAtingir(int n)
{
	this->nParaAtingir = n;
}
int oJogo::getNParaAtingir()
{
	return this->nParaAtingir;
}

void oJogo::mostrarDado()
{
	cout<< "lados: "<<dado.getLados()<< " Quantidade: "<<dado.getNumDados()<<endl;
}
void oJogo::jogarDado()
{
	this->valorAtual += dado.jogarDados();
	cout << this->valorAtual << endl;
}

//altera para return string
void getJogador