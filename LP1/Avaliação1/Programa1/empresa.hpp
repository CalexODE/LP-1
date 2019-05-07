#include "funcionario.hpp"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Empresa
{
private:

	string nome; //Nome da empresa
	string CNPJ; //CNPJ da empresa
	vector<Funcionario> vetFunc; //Vetor que irá armazenar os funcionários

public:
	Empresa();
	Empresa(string nome, string CNPJ);

	void setNome(string nome);
	string getNome();

	void setCNPJ(string CNPJ);
	string getCNPJ();

	int novoFuncionario(string nome, string cpf, float salario);
	
	void tFuncionarios();
	void tFuncionariosNovos();

	void aumentoSalario(float perc);

	int numeroDeFuncionarios();
};