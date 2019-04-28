#include <string>
#include <iostream>
#include <ostream>

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
	int getDia_ad();
	int getMes_ad();
	int getAno_ad();

	bool operator==(Funcionario &f);
	friend std::ostream& operator<<(std::ostream &O, Funcionario const f);
};