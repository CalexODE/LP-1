#include <iostream>

#include "soma.cpp"
#include "sub.cpp"
#include "mult.cpp"
#include "div.cpp"
#include "menu.h"

using namespace std;

void menu(void)
{
	cout << "olaaaaa" << endl;
	int x, y, resposta = 10, result;
	float result_float;
	do
	{
		cout << "Números: ";
		cin >> x >> y;
		cout << "Operação...\n 1-soma\n 2-subtração\n 3-multiplicação\n 4-divisão\n0-Sair" <<endl;
		cin >> resposta;
		switch(resposta)
		{
			case 0:
				cout << "saindo..." << endl;
				break;

			case 1:
				result = soma(x,y);
				cout << result << endl;
				break;

			case 2:
				result = subtracao(x,y);
				cout << result << endl;
				break;

			case 3:
				result = multiplicacao(x,y);
				cout << result << endl;
				break;

			case 4:
				result_float = divisao(x,y);
				cout << result_float << endl;
				break;

			default:
				cout << "Valor invalido" << endl;
		}
	}while(resposta != 0);
}
