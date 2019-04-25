#include <string>
#include <iostream>
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
	Funcionario(float salario, string nome);

	void setSalario(float salario);
	float getSalario();

	void setNome(string nome);
	string getNome();

	void setCpf(string cpf);
	string getCpf();

	bool operator==(Funcionario &f);
};