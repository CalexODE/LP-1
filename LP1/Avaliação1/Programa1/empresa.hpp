#include "funcionario.hpp"

#include <string>
#include <iostream>

#include <vector>
using namespace std;

class Empresa
{
private:
	string nome;
	string CNPJ;
	vector<Funcionario> vetFunc;

public:
	Empresa();
	Empresa(string nome, string CNPJ);

	void setNome(string nome);
	string getNome();

	void setCNPJ(string CNPJ);
	string getCNPJ();

	int novoFuncionario(string nome, string cpf, float salario);
	//void mostraFuncionario(int n);//Auxiliar
	
	void tFuncionarios();
	void tFuncionariosNovos();

	int numeroDeFuncionarios();

	void aumentoSalario(float perc);
};