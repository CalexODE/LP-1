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

int oJogo::totalDeJogadores()
{
	return vecJogadoresAtivos.size();
}

int oJogo::totalDeJogadoresF()
{
	return vecJogadoresFora.size();
}

int oJogo::pontuacaoDoJogador(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresAtivos.begin();
	return (v+i)->getPontuacao();
}

void oJogo::jogarDado(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresAtivos.begin();

	(v+i)->setPontuacao(dado.jogarDados());
	cout << (v+i)->getPontuacao() << endl;
}

//altera para return string
string oJogo::getJogadorAtivos(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresAtivos.begin();
	return (v+i)->getNome();
}

string oJogo::getNomeJogadorFora(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresFora.begin();

	return (v+i)->getNome();// + to_string((v+i)->getPontuacao());
}

int oJogo::getPontuacaoJogadorFora(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresFora.begin();

	return (v+i)->getPontuacao();// + to_string((v+i)->getPontuacao());
}


void oJogo::retirarJogador(int i)
{
	cout << "retirar"<< endl;
	vector<Jogador>::iterator jAtivos;
	jAtivos = vecJogadoresAtivos.begin();

	cout <<"i: "<< i << endl;//tirar
	vecJogadoresFora.push_back(*(jAtivos+i));

	vecJogadoresAtivos.erase(jAtivos+i);
	vector<Jogador>::iterator jFora;//tirar

	//cout << vecJogadoresAtivos.size() << endl;//tirar
	jFora = vecJogadoresFora.begin();//tirar

	//cout <<"jogares fora"<< *jFora << endl;//tirar
}
void oJogo::organizarVencedores()
{
	vector<Jogador>::iterator j;
	j = vecJogadoresFora.begin();

	string nomeAux;
	int pontAux;
	for (int cont = 0; cont < vecJogadoresFora.size(); cont++)
	{
		for (int cont2 = cont+1; cont2 < vecJogadoresFora.size(); cont2++)
		{
			if ((j+cont)->getPontuacao()<(j+cont2)->getPontuacao())
			{
				nomeAux = (j+cont)->getNome();
				pontAux = (j+cont)->getPontuacao();

				(j+cont)->setNome((j+cont2)->getNome());
				(j+cont)->setPontuacao((j+cont2)->getPontuacao());

				(j+cont2)->setNome(nomeAux);
				(j+cont2)->setPontuacao(pontAux);
			}
		}
	}




	/**
	vector<int>::iterator i;

	j = vecJogadoresFora.begin()

	pon
	for (int cont = 0; cont < vecJogadoresFora.size(); cont++)
	{
		
	}
	*/
}
//void setOrdemDeVitoria()
//{
//	this->ordemDeVitoria[] = 
//}
//string oJogo::jogadoresFora(int i)
