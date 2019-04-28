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