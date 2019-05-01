#include "menu.hpp"

void menu()
{	
	system("clear");
	cout<< "Bem vindo ao jogo que eu não sei o nome!"<< endl;
	//usleep(1000000);
	int j=1;
	oJogo jogo;
	string nome;
	
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
	cout << "escolhemos nos jogadores, agora vamos jogar";	
}