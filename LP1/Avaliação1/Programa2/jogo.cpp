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
	//cout << "Lados: " << dado.getLados() << endl;
}

void oJogo::setNParaAtingir(int n)
{
	this->nParaAtingir = n;
}
int oJogo::getNParaAtingir()
{
	return this->nParaAtingir;
}

//retir
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

	(v+i)->aumentarPontuacao(dado.jogarDados());
	//cout << (v+i)->getPontuacao() << endl;
}

//altera para return string
string oJogo::getNomeJogadorAtivo(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresAtivos.begin();

	return (v+i)->getNome();
}
int oJogo::getPontuacaoJogadorAtivo(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresAtivos.begin();

	return (v+i)->getPontuacao();
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

void oJogo::retirarJogador(int i, int c)
{
	//cout << "retirar"<< endl;
	vector<Jogador>::iterator jAtivos;
	vector<Jogador>::iterator jFora;

	jFora = vecJogadoresFora.begin();
	jAtivos = vecJogadoresAtivos.begin();

	//cout <<"i: "<< i << endl;//tirar
	if (c == 0)
	{
		vecJogadoresFora.insert(jFora,*(jAtivos+i));
	}
	else
	{
		vecJogadoresFora.push_back(*(jAtivos+i));		
	}
	vecJogadoresAtivos.erase(jAtivos+i);

	//cout << vecJogadoresAtivos.size() << endl;//tirar

	//cout <<"jogares fora"<< *jFora << endl;//tirar
}
void oJogo::organizarVencedores()
{
	vector<Jogador>::iterator j;
	j = vecJogadoresFora.begin();

	for (int cont = 0; cont < vecJogadoresFora.size(); cont++)
	{
		int pontAux = 0;
		string nomeAux = " ";
		int insertPos = cont;

		for (int cont2 = cont+1; cont2 < vecJogadoresFora.size(); cont2++)
		{
			if ((j+insertPos)->getPontuacao()<(j+cont2)->getPontuacao() && (j+cont2)->getPontuacao() < this->nParaAtingir)
			{
				insertPos = cont2;
			}
		}
		//cout <<"cont: "<< cont <<" nome:"<<(j+cont)->getNome() <<" pont:"<<(j+cont)->getPontuacao()<<endl;
		//cout <<"cont2: "<< insertPos <<" nome:"<<(j+insertPos)->getNome() <<" pont2:"<<(j+insertPos)->getPontuacao()<<endl;
		nomeAux = (j+cont)->getNome();
		pontAux = (j+cont)->getPontuacao();

		(j+cont)->setNome((j+insertPos)->getNome());
		(j+cont)->setPontuacao((j+insertPos)->getPontuacao());

		(j+insertPos)->setNome(nomeAux);
		(j+insertPos)->setPontuacao(pontAux);
		//cout <<"depois de trocar:" << endl;
		//cout <<"cont: "<< cont <<" nome:"<<(j+cont)->getNome() <<" pont:"<<(j+cont)->getPontuacao()<<endl;
		//cout <<"cont2: "<< insertPos <<" nome:"<<(j+insertPos)->getNome() <<" pont2:"<<(j+insertPos)->getPontuacao()<<endl;
	}
}
