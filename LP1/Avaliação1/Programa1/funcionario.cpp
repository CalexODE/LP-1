#include "funcionario.h"

Funcionario::Funcionario()
{
	std::cout << "Funcionario OK!" << std::endl;
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