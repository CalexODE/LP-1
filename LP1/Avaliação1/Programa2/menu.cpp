#include "menu.hpp"

#include <unistd.h>

void menu()
{	
	system("clear");
	cout<< "Bem vindo ao jogo que eu não sei o nome!"<< endl<<endl;

	int j=1;
	oJogo jogo;
	string nome;
	int numeroParaAtingir;

	//Loop para adicionar jogadores
	while(true)
	{
		cout<<"Jogador "<< j <<": ";
		cin >> nome;

		jogo.adicionarJogador(nome);

		string r;

		cout<<"Mais jogadores?[y/n]: ";
		cin >> r;

		if((r.compare("y") == 0) or (r.compare("Y")==0)){}
		else{break;}

		j++;
		cout<<endl;
	}
	cout<<endl<<"escolhemos os jogadores, agora vamos jogar"<<endl<<endl;

	//Valor máximo a ser atingido
	cout<<"Número pra atingir: ";
	cin>>numeroParaAtingir;
	jogo.setNParaAtingir(numeroParaAtingir);

	//Cria 2 dados de 6 lados
	jogo.criarDado(2, 6);

	int rodada = 1;//Rodada atual
	int jogadorAtual = 1;
	
	string nome_jogador_atual;
	int decisao;

	while(true)
	{

		cout <<" Sua vez, "<< jogo.getNomeJogadorAtivo(jogadorAtual-1) <<endl<<"Pontuacao Atual: "<<jogo.getPontuacaoJogadorAtivo(jogadorAtual-1)<<endl;
		cout << "1 - Jogar dado"<<endl<<"2 - parar"<<endl << "-> ";
		cin>>decisao;

		//Decisão do jogador entre jogar dado ou parar

		//Retira jogador caso escolha por parar
		if(decisao == 2)
		{
			jogo.retirarJogador(jogadorAtual-1,0);
			jogadorAtual--;
		}

		//Joga o dado para jogador que tem a vez
		else
		{
			//Joga dado
			jogo.jogarDado(jogadorAtual-1);
			cout<<"Soma dos dados: "<<jogo.getPontuacaoJogadorAtivo(jogadorAtual-1)<<endl;

			//Caso sua pontuação ultrapasse o valor máximo que pode ser atingido ele será removido
			if (jogo.pontuacaoDoJogador(jogadorAtual-1) >= jogo.getNParaAtingir())
			{
				jogo.retirarJogador(jogadorAtual-1,1);
				jogadorAtual--;
			}
		}

		jogadorAtual++;
		cout<<endl;

		//Verifica se ainda há jogadores na rodada
		if (jogadorAtual > jogo.totalDeJogadores())
		{
			if (jogo.totalDeJogadores()==0)break;
			jogadorAtual=1;
		}
	}

	//Organiza vetor para listar pontuação e vencedores
	jogo.organizarVencedores();

	//Mostra lista de todos jogadores mostrando sua classificação
	for (int i = 0; i < jogo.totalDeJogadoresF(); i++)
	{
		cout <<i+1<< "º: "<< jogo.getNomeJogadorFora(i) <<" :"<<jogo.getPontuacaoJogadorFora(i)<<endl;
	}
}