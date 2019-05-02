#include "menu.hpp"

void menu()
{	
	//system("clear");
	cout<< "Bem vindo ao jogo que eu não sei o nome!"<< endl;
	//usleep(1000000);
	int j=1;
	oJogo jogo;
	string nome;
	int numeroParaAtingir;
	//cout << jogo.totalDeJogadores()<<endl;
	while(true)
	{
		cout << "Jogador " << j << ": ";
		cin >> nome;
		jogo.adicionarJogador(nome);

		string r;
		cout << "Mais jogadores?[y/n]: ";
		cin >> r;
		if((r.compare("y") == 0) or (r.compare("Y")==0))
		{
			
		}
		else
		{
			break;
		}
		j++;
	}
	cout<<"escolhemos os jogadores, agora vamos jogar"<<endl;

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

		nome_jogador_atual = jogo.getJogadorAtivos(jogadorAtual-1);
		cout<<"jogadorAtual: "<<jogadorAtual<<endl;
		cout <<" Sua vez, "<< nome_jogador_atual << endl;
		cout << "1 - Jogar dado"<<endl<<"2 - parar"<<endl;
		cin>>decisao;
		if(decisao == 2)
		{
			jogo.retirarJogador(jogadorAtual-1);
			jogadorAtual--;
		}
		else
		{
			jogo.jogarDado(jogadorAtual-1);
			if (jogo.pontuacaoDoJogador(jogadorAtual-1) >= jogo.getNParaAtingir())
			{
				jogo.retirarJogador(jogadorAtual-1);
				jogadorAtual--;
			}
		}
		jogadorAtual++;

		if (jogadorAtual > jogo.totalDeJogadores())
		{
			if (jogo.totalDeJogadores()==0)
			{
				break;
			}
			jogadorAtual=1;
		}
	}
	jogo.organizarVencedores();

	for (int i = 0; i < jogo.totalDeJogadoresF(); i++)
	{
		cout <<"i: "<< i<< "  "<< jogo.getNomeJogadorFora(i) <<" :"<<jogo.getPontuacaoJogadorFora(i)<< endl;
	}
}