#include <iostream>

#include "soma.cpp"
#include "sub.cpp"
#include "mult.cpp"
#include "div.cpp"
#include "menu.h"

using namespace std;

void menu(void)
{
	cout << "Bem vindo" << endl;
	int x, y, resposta = 10, result;
	float result_float;
	do
	{
		cout << "Operação...\n 1-soma\n 2-subtração\n 3-multiplicação\n 4-divisão\n0-Sair" <<endl;
		cin >> resposta;
		switch(resposta)
		{
			cout << "Números: ";
			cin >> x >> y;
			case 0:
				cout << "saindo..." << endl;
				break;

			case 1:
				result = soma(x,y);
				cout << x << " + " << y << ": " << result << endl;
				break;

			case 2:
				result = subtracao(x,y);
				cout << x << " - " << y << ": " << result << endl;
				break;

			case 3:
				result = multiplicacao(x,y);
				cout << x << " * " << y << ": " << result << endl;
				break;

			case 4:
				result_float = divisao(x,y);
				cout << x << " / " << y << ": " << result_float << endl;
				break;

			default:
				cout << "Valor invalido" << endl;
		}
	}while(resposta != 0);
	cout << "Obrigado pela preferencia!" << endl;
}
