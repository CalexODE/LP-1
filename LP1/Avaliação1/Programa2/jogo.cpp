#include "jogo.hpp"

oJogo::oJogo()
{
	this->valorAtual=0;
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
string oJogo::getJogadorAtivos(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresAtivos.begin();
	return (v+i)->getNome();
}


void oJogo::retirarJogador(int i)
{
	cout << "retirar"<< endl;
	vector<Jogador>::iterator jAtivos;
	jAtivos = vecJogadoresAtivos.begin();

	//cout << vecJogadoresAtivos.size() << endl;//tirar
	vecJogadoresFora.push_back(*(jAtivos+i));

	vecJogadoresAtivos.erase(jAtivos+i);
	vector<Jogador>::iterator jFora;//tirar

	//cout << vecJogadoresAtivos.size() << endl;//tirar
	jFora = vecJogadoresFora.begin();//tirar

	//cout <<"jogares fora"<< *jFora << endl;//tirar
}
