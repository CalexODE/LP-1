#include "funcionario.hpp"

//Construtor(es)

Funcionario::Funcionario()
{
	//std::cout << "Funcionario OK!" << std::endl;
}

Funcionario::Funcionario(string nome, string cpf, float salario)
{
	setNome(nome);
	setCpf(cpf);
	setSalario(salario);

	//Obtençao da data atual para armazenar aos dados do funcionário
	time_t timer;
  	struct tm *horarioLocal;

  	time(&timer); // Obtem informações de data e hora
  	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

  	dia_ad = horarioLocal->tm_mday;
  	mes_ad = horarioLocal->tm_mon + 1;
	ano_ad = horarioLocal->tm_year + 1900;

}


//get e set do Nome
void Funcionario::setNome(string nome)
{
	this->nome = nome;
}
string Funcionario::getNome()
{
	return this->nome;
}

//get e set do Salario
void Funcionario::setSalario(float salario)
{
	this->salario = salario;
}
float Funcionario::getSalario()
{
	return this->salario;
}

//get e set do CPF
void Funcionario::setCpf(string cpf)
{
	this->cpf = cpf;
}
string Funcionario::getCpf()
{
	return this->cpf;
}

//get do dia/mes/ano de admissão
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

//Sobrecarga do operador ==
//Usado para comparação entre dois funcionários, que levará em consideração a iguadade em seus cpf's
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

//Sobrecarga do operador de inserção(<<)
//ao ser chamado, funcionário irá retornar uma ostream com os seus dados
std::ostream& operator<<(std::ostream &O, Funcionario const f)
{
	O << "Nome: "<<f.nome << " CPF: " <<f.cpf <<" Salario: "<<f.salario;
	return O;
}