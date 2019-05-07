#include "jogo.hpp"

//Construtor
oJogo::oJogo()
{
	this->valorAtual=0;
}

//Adiciona um novo jogador
void oJogo::adicionarJogador(string nome)
{
	Jogador j;
	j.setNome(nome);
	vecJogadoresAtivos.push_back(j);
}

//Cria dados baseado nos parémetros
void oJogo::criarDado(int nDados, int nLados)
{
	Dado dado;
	dado.setLados(nLados);
	dado.setDados(nDados);
	this->dado = dado;
}

void oJogo::setNParaAtingir(int n)
{
	this->nParaAtingir = n;
}
int oJogo::getNParaAtingir()
{
	return this->nParaAtingir;
}

//Retorna o número de jogadores ativos
int oJogo::totalDeJogadores()
{
	return vecJogadoresAtivos.size();
}

//Retorna o número de jogadores desistiram o perderam a rodada
int oJogo::totalDeJogadoresF()
{
	return vecJogadoresFora.size();
}

//Retorna a pontuação atual de um jogador específico
int oJogo::pontuacaoDoJogador(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresAtivos.begin();

	return (v+i)->getPontuacao();
}

//Joga dado e atribui a pontução para o jogador que o "jogou"
void oJogo::jogarDado(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresAtivos.begin();

	(v+i)->aumentarPontuacao(dado.jogarDados());
}

//Retorna o nome de um jogador ativo baseado na posição no vetor
string oJogo::getNomeJogadorAtivo(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresAtivos.begin();

	return (v+i)->getNome();
}

//Retorna a pontuação atual de um jogador ativo
int oJogo::getPontuacaoJogadorAtivo(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresAtivos.begin();

	return (v+i)->getPontuacao();
}

//Retorna o nome de um jogador, Fora da rodada, baseado na posição no vetor
string oJogo::getNomeJogadorFora(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresFora.begin();

	return (v+i)->getNome();
}

//Retorna a pontuação atual de um jogador Fora
int oJogo::getPontuacaoJogadorFora(int i)
{
	vector<Jogador>::iterator v;
	v = vecJogadoresFora.begin();

	return (v+i)->getPontuacao();
}

//Remove um jogador de um vetor para um outro vetor de jogadores que não estão mais jogando na rodada
//Primeiro parámetro é a posição do jogador no vetor
//Segundo parámetro indica se o jogador decidiu parar ou perdeu por exceder os pontos(0 - parou, 1 - perdeu)

//Obs: Todos os jogadores saem do vetor de ativos e vão para o vetor de jogadores fora, mesmo conseguindo a pontuação para vencer
void oJogo::retirarJogador(int i, int c)
{
	vector<Jogador>::iterator jAtivos;
	vector<Jogador>::iterator jFora;

	jFora = vecJogadoresFora.begin();
	jAtivos = vecJogadoresAtivos.begin();

	if (c == 0)
	{
		vecJogadoresFora.insert(jFora,*(jAtivos+i));
	}
	else
	{
		vecJogadoresFora.push_back(*(jAtivos+i));		
	}

	vecJogadoresAtivos.erase(jAtivos+i);

}

//Organiza o vetor de jogadores Fora com o método "Selection Sort" de organização.
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
		nomeAux = (j+cont)->getNome();
		pontAux = (j+cont)->getPontuacao();

		(j+cont)->setNome((j+insertPos)->getNome());
		(j+cont)->setPontuacao((j+insertPos)->getPontuacao());

		(j+insertPos)->setNome(nomeAux);
		(j+insertPos)->setPontuacao(pontAux);
	}
}
