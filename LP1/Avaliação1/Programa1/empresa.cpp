#include "empresa.hpp"



//Construtor(es)
Empresa::Empresa()
{

}

//Nome da empresa
void Empresa::setNome(string nome)
{
	this->nome = nome;
}
string Empresa::getNome()
{
	return this->nome;
}

//CNPJ
void Empresa::setCNPJ(string CNPJ)
{
	this->CNPJ = CNPJ;
}
string Empresa::getCNPJ()
{
	return this->CNPJ;
}


//Adicionar novo funcionario
int Empresa::novoFuncionario(string nome, string cpf, float salario)
{
	Funcionario func(nome, cpf, salario);
	
	vector<Funcionario>::iterator ponteiroVec;
	ponteiroVec = vetFunc.begin();
	bool existencia = false;

	if(vetFunc.size() == 0)
	{
		vetFunc.push_back(func);
		return 1;
	}
	else
	{
		for (int i = 0; i <= vetFunc.size(); i++)
		{
			if(*(ponteiroVec+i) == func)
			{
				existencia = true;
				break;
			}
		}
		if(existencia)
		{
			return 0;
		}
		else
		{
			vetFunc.push_back(func);
			return 1;
		}
	}

}


//Aumento de todos os funcionarios de uma empresa
//Baseado em uma porcentagem
void Empresa::aumentoSalario(float perc)
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();

	for (int cont = 0; cont < vetFunc.size(); cont++)
	{
		(i+cont)->setSalario((i+cont)->getSalario() + (((i+cont)->getSalario()) * (perc/100)));
	}
}

void Empresa::tFuncionarios()
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();

	for (int cont = 0; cont < vetFunc.size(); cont++)
	{
		cout << *(i+cont) << endl;
	}
}


//funcionarios de até 90 dias de admissão
void Empresa::tFuncionariosNovos()
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();
	double dias_admissao, dias_totais;

	time_t timer;
	struct tm *horarioLocal;

	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

	int dia = horarioLocal->tm_mday;
	int mes = horarioLocal->tm_mon + 1;
	int ano = horarioLocal->tm_year + 1900;
	
	dias_totais = (ano * 365) + (mes * 30) + dia;

	bool mostrar = false;
	for (int cont = 0; cont <= vetFunc.size()-1; cont++)
	{
		dias_admissao = ((i+cont)->getAno_ad() * 365) + (i+cont)->getMes_ad() * 30 + ((i+cont)->getDia_ad());
		if ((dias_totais - dias_admissao) <= 90)
		{
			cout << *(i+cont) << endl;
		}
	}
}

int Empresa::numeroDeFuncionarios()
{
	return vetFunc.size();
}

