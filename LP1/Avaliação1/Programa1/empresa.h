#include <string>
using std::string;

#include <iostream>

class Empresa
{
private:
	string nome;
	string CNPJ;
	//To Do
	//lista de funcionario(list, vector)

public:
	Empresa();
	Empresa(string nome, string CNPJ);

	void setNome(string nome);
	string getNome();

	void setCNPJ(string CNPJ);
	string getCNPJ();
};