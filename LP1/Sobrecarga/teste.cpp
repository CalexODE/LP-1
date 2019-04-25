#include <iostream>

using namespace std;

//Sobrecarga de funções
int somar(int x, int y, int z){cout<<"1º ";return x + y + z;}
int somar(int x, int y){cout<<"2º ";return x + y;}

//Argumento Padrão
void mostrar(int x, ints)

int main()
{
	cout << somar(2, 4, 2) << endl;
	cout << somar(2, 4) << endl;

	return 0;
}