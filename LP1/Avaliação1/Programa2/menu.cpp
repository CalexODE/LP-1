#include "menu.hpp"

#include <unistd.h>

void menu()
{	
	system("clear");
	cout<< "Bem vindo ao jogo que eu não sei o nome!"<< endl<<endl;
	//usleep(1000000);

	int j=1;
	oJogo jogo;
	string nome;
	int numeroParaAtingir;

	//cout << jogo.totalDeJogadores()<<endl;
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

	cout<<"Número pra atingir: ";
	cin>>numeroParaAtingir;
	jogo.setNParaAtingir(numeroParaAtingir);

	jogo.criarDado(6,2);

	int rodada = 1;
	int jogadorAtual = 1;
	
	string nome_jogador_atual;
	int decisao;

	while(true)
	{
		//int total_de_jogadores = jogo.totalDeJogadores();

		
		//cout<<"jogadorAtual: "<<jogadorAtual<<endl;
		cout <<" Sua vez, "<< jogo.getNomeJogadorAtivo(jogadorAtual-1) <<endl<<"Pontuacao Atual: "<<jogo.getPontuacaoJogadorAtivo(jogadorAtual-1)<<endl;
		cout << "1 - Jogar dado"<<endl<<"2 - parar"<<endl << "-> ";
		cin>>decisao;

		if(decisao == 2)
		{
			jogo.retirarJogador(jogadorAtual-1,0);
			jogadorAtual--;
		}
		else
		{
			jogo.jogarDado(jogadorAtual-1);
			cout<<"Soma dos dados: "<<jogo.getPontuacaoJogadorAtivo(jogadorAtual-1)<<endl;
			if (jogo.pontuacaoDoJogador(jogadorAtual-1) >= jogo.getNParaAtingir())
			{
				jogo.retirarJogador(jogadorAtual-1,1);
				jogadorAtual--;
			}
		}

		//usleep(1000000); descomentar
		jogadorAtual++;
		cout<<endl;
		if (jogadorAtual > jogo.totalDeJogadores())
		{
			if (jogo.totalDeJogadores()==0)break;
			jogadorAtual=1;
		}
	}
	/*
	for (int i = 0; i < jogo.totalDeJogadoresF(); i++)
	{
		cout <<"i: "<< i<< "  "<< jogo.getNomeJogadorFora(i) <<" :"<<jogo.getPontuacaoJogadorFora(i)<< endl;
	}
	*/
	jogo.organizarVencedores();
	//cout<<"depois de organizar" <<endl;
	for (int i = 0; i < jogo.totalDeJogadoresF(); i++)
	{
		cout <<i+1<< "º: "<< jogo.getNomeJogadorFora(i) <<" :"<<jogo.getPontuacaoJogadorFora(i)<<endl;
	}
}