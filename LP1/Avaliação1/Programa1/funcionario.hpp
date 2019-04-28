#include <string>
#include <iostream>
#include <time.h>

using std::string;

class Funcionario
{
private:
	string nome;
	string cpf;
	float salario;
	int dia_ad;
	int mes_ad;
	int ano_ad;

public:
	Funcionario();
	Funcionario(string nome, string cpf, float salario);

	void setSalario(float salario);
	float getSalario();

	void setNome(string nome);
	string getNome();

	void setCpf(string cpf);
	string getCpf();

	//Alterar Implementação
	void getData();

	bool operator==(Funcionario &f);
};