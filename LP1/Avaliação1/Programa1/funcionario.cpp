#include "funcionario.hpp"

//Construtores

Funcionario::Funcionario()
{
	std::cout << "Funcionario OK!" << std::endl;
}
Funcionario::Funcionario(string nome, string cpf, float salario)
{
	setNome(nome);
	setCpf(cpf);
	setSalario(salario);

	time_t timer;
  	struct tm *horarioLocal;

  	time(&timer); // Obtem informações de data e hora
  	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

  	dia_ad = horarioLocal->tm_mday;
  	mes_ad = horarioLocal->tm_mon + 1;
	ano_ad = horarioLocal->tm_year + 1900;

	std::cout<< dia_ad <<"/"<<mes_ad<<"/"<<ano_ad<<std::endl;
}


//Nome
void Funcionario::setNome(string nome)
{
	this->nome = nome;
}
string Funcionario::getNome()
{
	return this->nome;
}

//Salario
void Funcionario::setSalario(float salario)
{
	this->salario = salario;
}
float Funcionario::getSalario()
{
	return this->salario;
}

//CPF
void Funcionario::setCpf(string cpf)
{
	this->cpf = cpf;
}
string Funcionario::getCpf()
{
	return this->cpf;
}

//Data
void Funcionario::getData()
{
	std::cout<<" "<<dia_ad <<"/"<<mes_ad<<"/"<<ano_ad<<std::endl;
}
int Funcionario::getDia_ad()
{
	return this->dia_ad;
}
int Funcionario::getMes_ad()
{
	return this->mes_ad;
}
int Funcionario::getAno_ad()
{
	return this->ano_ad;
}

//Sobrecarga ==
bool Funcionario::operator==(Funcionario  &t)
{
	if(this->cpf == t.getCpf())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Sobrecarga <<
std::ostream& operator<<(std::ostream &O, Funcionario const f)
{
	O << "Nome: "<<f.nome << " CPF: " <<f.cpf <<" Salario: "<<f.salario;
	return O;
}